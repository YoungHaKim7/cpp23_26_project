// mandelbrot_pthread.cpp
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <pthread.h>
#include <string>
#include <thread>
#include <vector>

struct Args {
    int id;
    int threads;
    int width, height, max_iter;
    double xmin, xmax, ymin, ymax;
    unsigned char* img; // RGB buffer, size = width*height*3
};

static inline void color_map(int it, int max_iter, unsigned char& r, unsigned char& g, unsigned char& b)
{
    if (it >= max_iter) {
        r = g = b = 0;
        return;
    } // black for inside
    // Smooth-ish gradient using HSV-like ramp without lib
    double t = (double)it / max_iter;
    double v = 1.0, s = 1.0;
    double h = 6.0 * t; // 0..6
    int i = (int)h;
    double f = h - i;
    double p = v * (1.0 - s);
    double q = v * (1.0 - s * f);
    double u = v * (1.0 - s * (1.0 - f));
    double R = 0, G = 0, B = 0;
    switch (i % 6) {
    case 0:
        R = v;
        G = u;
        B = p;
        break;
    case 1:
        R = q;
        G = v;
        B = p;
        break;
    case 2:
        R = p;
        G = v;
        B = u;
        break;
    case 3:
        R = p;
        G = q;
        B = v;
        break;
    case 4:
        R = u;
        G = p;
        B = v;
        break;
    case 5:
        R = v;
        G = p;
        B = q;
        break;
    }
    r = (unsigned char)std::lround(R * 255.0);
    g = (unsigned char)std::lround(G * 255.0);
    b = (unsigned char)std::lround(B * 255.0);
}

void* worker(void* ptr)
{
    Args* a = static_cast<Args*>(ptr);

    const double dx = (a->xmax - a->xmin) / (a->width - 1);
    const double dy = (a->ymax - a->ymin) / (a->height - 1);

    // Simple static row-block partitioning
    for (int y = a->id; y < a->height; y += a->threads) {
        double cy = a->ymin + y * dy;
        unsigned char* row = a->img + (size_t)y * a->width * 3;

        for (int x = 0; x < a->width; ++x) {
            double cx = a->xmin + x * dx;
            double zx = 0.0, zy = 0.0;
            int it = 0;

            // Iterate z = z^2 + c
            // Escape when |z|^2 > 4
            while (zx * zx + zy * zy <= 4.0 && it < a->max_iter) {
                double zx2 = zx * zx - zy * zy + cx;
                zy = 2.0 * zx * zy + cy;
                zx = zx2;
                ++it;
            }

            // Write pixel
            unsigned char r, g, b;
            color_map(it, a->max_iter, r, g, b);
            row[3 * x + 0] = r;
            row[3 * x + 1] = g;
            row[3 * x + 2] = b;
        }
    }
    return nullptr;
}

int main(int argc, char** argv)
{
    // Defaults
    int width = 1200;
    int height = 800;
    int max_iter = 1000;
    double xmin = -2.5, xmax = 1.0;
    double ymin = -1.25, ymax = 1.25;
    int threads = (int)std::max(1u, std::thread::hardware_concurrency());
    std::string out = "mandelbrot.ppm";

    // Parse args (lightweight)
    if (argc > 1)
        width = std::atoi(argv[1]);
    if (argc > 2)
        height = std::atoi(argv[2]);
    if (argc > 3)
        max_iter = std::atoi(argv[3]);
    if (argc > 4)
        xmin = std::atof(argv[4]);
    if (argc > 5)
        xmax = std::atof(argv[5]);
    if (argc > 6)
        ymin = std::atof(argv[6]);
    if (argc > 7)
        ymax = std::atof(argv[7]);
    if (argc > 8)
        threads = std::max(1, std::atoi(argv[8]));
    if (argc > 9)
        out = argv[9];

    const size_t bytes = (size_t)width * height * 3;
    std::vector<unsigned char> img(bytes, 0);

    std::vector<pthread_t> tids(threads);
    std::vector<Args> targs(threads);

    auto t0 = std::chrono::steady_clock::now();

    for (int i = 0; i < threads; ++i) {
        targs[i] = Args { i, threads, width, height, max_iter, xmin, xmax, ymin, ymax, img.data() };
        if (pthread_create(&tids[i], nullptr, worker, &targs[i]) != 0) {
            std::perror("pthread_create");
            return 1;
        }
    }
    for (int i = 0; i < threads; ++i) {
        pthread_join(tids[i], nullptr);
    }

    auto t1 = std::chrono::steady_clock::now();
    double ms = std::chrono::duration<double, std::milli>(t1 - t0).count();
    std::cerr << "Rendered " << width << "x" << height
              << " in " << ms << " ms using " << threads << " threads.\n";

    // Write PPM (binary P6)
    FILE* f = std::fopen(out.c_str(), "wb");
    if (!f) {
        std::perror("fopen");
        return 1;
    }
    std::fprintf(f, "P6\n%d %d\n255\n", width, height);
    std::fwrite(img.data(), 1, bytes, f);
    std::fclose(f);
    std::cerr << "Wrote " << out << "\n";
    return 0;
}

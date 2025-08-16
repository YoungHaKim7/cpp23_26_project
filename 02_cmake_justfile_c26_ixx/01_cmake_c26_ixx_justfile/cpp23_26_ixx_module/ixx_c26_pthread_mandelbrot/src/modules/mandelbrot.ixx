module;

export module mandelbrot;

#include <cstddef>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <chrono>
#include <iostream>

struct Args {
    int id;
    int threads;
    int width, height, max_iter;
    double xmin, xmax, ymin, ymax;
    unsigned char* img; // RGB buffer, size = width*height*3
};

static inline void color_map(int it, int max_iter, unsigned char& r, unsigned char& g, unsigned char& b) {
    if (it >= max_iter) { r = g = b = 0; return; }          // black for inside
    // Smooth-ish gradient using HSV-like ramp without lib
    double t = (double)it / max_iter;
    double v = 1.0, s = 1.0;
    double h = 6.0 * t;                                      // 0..6
    int   i = (int)h;
    double f = h - i;
    double p = v * (1.0 - s);
    double q = v * (1.0 - s * f);
    double u = v * (1.0 - s * (1.0 - f));
    double R=0,G=0,B=0;
    switch (i % 6) {
        case 0: R=v; G=u; B=p; break;
        case 1: R=q; G=v; B=p; break;
        case 2: R=p; G=v; B=u; break;
        case 3: R=p; G=q; B=v; break;
        case 4: R=u; G=p; B=v; break;
        case 5: R=v; G=p; B=q; break;
    }
    r = (unsigned char)std::lround(R * 255.0);
    g = (unsigned char)std::lround(G * 255.0);
    b = (unsigned char)std::lround(B * 255.0);
}

void* worker(void* ptr) {
    Args* a = static_cast<Args*>(ptr);

    const double dx = (a->xmax - a->xmin) / (a->width  - 1);
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
            while (zx*zx + zy*zy <= 4.0 && it < a->max_iter) {
                double zx2 = zx*zx - zy*zy + cx;
                zy = 2.0*zx*zy + cy;
                zx = zx2;
                ++it;
            }

            // Write pixel
            unsigned char r,g,b;
            color_map(it, a->max_iter, r, g, b);
            row[3*x + 0] = r;
            row[3*x + 1] = g;
            row[3*x + 2] = b;
        }
    }
    return nullptr;
}

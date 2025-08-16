#include <pthread.h>
#include <vector>
#include <string>

import ixx_module;
import mandelbrot;

int main(int argc, char** argv) {
    // Defaults
    int width  = 1200;
    int height = 800;
    int max_iter = 1000;
    double xmin = -2.5, xmax = 1.0;
    double ymin = -1.25, ymax = 1.25;
    int threads = (int)std::max(1u, std::thread::hardware_concurrency());
    std::string out = "mandelbrot.ppm";

    // Parse args (lightweight)
    if (argc > 1)  width    = std::atoi(argv[1]);
    if (argc > 2)  height   = std::atoi(argv[2]);
    if (argc > 3)  max_iter = std::atoi(argv[3]);
    if (argc > 4)  xmin     = std::atof(argv[4]);
    if (argc > 5)  xmax     = std::atof(argv[5]);
    if (argc > 6)  ymin     = std::atof(argv[6]);
    if (argc > 7)  ymax     = std::atof(argv[7]);
    if (argc > 8)  threads  = std::max(1, std::atoi(argv[8]));
    if (argc > 9)  out      = argv[9];

    const size_t bytes = (size_t)width * height * 3;
    std::vector<unsigned char> img(bytes, 0);

    std::vector<pthread_t> tids(threads);
    std::vector<Args> targs(threads);

    auto t0 = std::chrono::steady_clock::now();

    for (int i = 0; i < threads; ++i) {
        targs[i] = Args{i, threads, width, height, max_iter, xmin, xmax, ymin, ymax, img.data()};
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
    if (!f) { std::perror("fopen"); return 1; }
    std::fprintf(f, "P6\n%d %d\n255\n", width, height);
    std::fwrite(img.data(), 1, bytes, f);
    std::fclose(f);
    std::cerr << "Wrote " << out << "\n";
    return 0;
}

#include <experimental/bits/simd.h>
#include <experimental/simd>
#include <iostream>

namespace stdx = std::experimental;

int main() {
    std::cout << "Hello C++" << std::endl;
    using floatv = stdx::native_simd<float>;
    using doublev = stdx::rebind_simd_t<double, floatv>;
    using intv    = stdx::rebind_simd_t<int, floatv>;

    std::cout << "floatv: " << typeid(floatv).name() << std::endl;
    std::cout << "doublev: " << typeid(doublev).name() << std::endl;
    std::cout << "intv: " << typeid(intv).name() << std::endl;
    return 0;
}

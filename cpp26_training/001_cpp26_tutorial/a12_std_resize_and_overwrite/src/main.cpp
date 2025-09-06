#include <cstddef>
#include <print>
#include <string>

int main()
{
    std::string s;
    s.resize_and_overwrite(5, [](char* buf, size_t n) {
        std::fill(buf, buf + n, '*');
        return n;
    });

    std::println("{}", s);
}

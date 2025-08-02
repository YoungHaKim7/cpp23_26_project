#include <cstdio>
#include <print>

int main()
{
    if (auto f = std::fopen("log.txt", "w")) {
        std::print(f, "Hello {}\n", "file");
        std::fclose(f);
    }
}
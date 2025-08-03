#include <print>
#include <ranges>
#include <vector>

int main()
{
    std::vector v = { 1, 2, 3 };
    bool has = std::ranges::find(v, 2) != v.end();
    std::println("Has 2? {}", has);
}

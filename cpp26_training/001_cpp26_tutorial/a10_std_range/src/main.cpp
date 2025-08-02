#include <print>
#include <ranges>

int main()
{
    auto r = std::views::iota(1,4);
    for (auto [a, b] : std::views::zip(r, r)) {
        std::println("{}, {}", a, b);
    }
}

#include <format>
#include <functional>
#include <print>

void greet(std::string who, std::string from)
{
    std::println("Hello {}, from {}", who, from);
}

int main()
{
    auto f = std::bind_back(greet, "world");
    f("C++26");
}

#include <print>

constexpr int sum()
{
    auto* ptr = new int(42);
    int val = *ptr;
    delete ptr;
    return val;
}

int main()
{
    int s = sum();

    std::println("{}", s);
}

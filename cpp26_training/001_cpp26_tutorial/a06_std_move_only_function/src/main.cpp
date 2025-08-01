// https://en.cppreference.com/w/cpp/utility/functional/move_only_function.html

#include <functional>
#include <print>

int main()
{
    std::move_only_function<void()> f = [] { std::println("Moved!"); };
    f();
}

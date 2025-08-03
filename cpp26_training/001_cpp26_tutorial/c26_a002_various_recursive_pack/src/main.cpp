#include <iostream>
#include <print>

// template <typename T, typename... Types> void print(T t, Types... args)
// {
//     std::cout << t << '\n';
//     if constexpr (sizeof...(args) > 0)
//         print(args...);
// }

template <typename... Types> void print(Types... args)
{
    std::cout << args...[0] << '\n';
}

int main()
{
    std::println("C++26 introduced variadic templates ");
    print('a', "foo", 42);
}

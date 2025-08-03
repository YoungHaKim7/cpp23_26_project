#include <iostream>
#include <print>

template <typename T, typename... Types> void print(T t, Types... args)
{
    std::cout << t << '\n';
    if constexpr (sizeof...(args) > 0)
        print(args...);
}

int main()
{
    std::println("c++ C++11 introduced variadic templates ");
    print('a', "foo", 42);
}

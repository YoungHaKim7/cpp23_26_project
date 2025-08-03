#include <print>

// template <typename T, typename... Types> void print(T t, Types... args)
// {
//     std::cout << t << '\n';
//     if constexpr (sizeof...(args) > 0)
//         print(args...);
// }

// template <typename... Types> void print(Types... args)
// {
//     std::cout << args...[0] << '\n';
// }

template <typename... Types> void print(Types... args)
{
    std::println("{}", args...[0]);
    std::println("{}", args...[1]);
    std::println("{}", args...[2]);
}

int main()
{
    std::println("C++26 introduced variadic templates ");
    print('a', "foo", 42);
}

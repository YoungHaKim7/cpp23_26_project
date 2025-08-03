#include <format>
#include <print>

template <typename T> constexpr int check()
{
    if consteval {
        return 1;
    } else {
        return 0;
    }
}

int main()
{
    constexpr int res_compile_time = check<int>();
    std::println("compile time: {}", res_compile_time);

    int res_run_time = check<int>();
    std::println("run time: {}", res_run_time);
}

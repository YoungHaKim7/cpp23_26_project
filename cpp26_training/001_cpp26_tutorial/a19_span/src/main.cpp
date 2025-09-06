#include <print>
#include <span>

void print(std::span<int> s)
{
    for (auto i : s)
        std::println("{}", i);
}

int main()
{
    int arr[] = { 1, 2, 3 };
    print(arr);
}

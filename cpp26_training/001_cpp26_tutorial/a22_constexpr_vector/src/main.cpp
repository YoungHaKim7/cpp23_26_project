#include <print>
#include <vector>

consteval int sum() {
    std::vector<int> v = {1,2,3};
    return v[0] + v[1] + v[2];
}

int main()
{
    std::println("{}", sum());
}

#include <format>
#include <print>

int main()
{
    std::string msg = std::format("{:>10}", "hi");
    std::println("{}", msg);
}

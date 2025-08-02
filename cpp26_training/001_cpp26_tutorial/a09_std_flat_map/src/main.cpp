#include <print>
#include <flat_map>

int main()
{
    std::flat_map<int, std::string> fm = {{1, "a"}, {2,"b"}};
    std::println("Key 2: {}", fm[2]);
}

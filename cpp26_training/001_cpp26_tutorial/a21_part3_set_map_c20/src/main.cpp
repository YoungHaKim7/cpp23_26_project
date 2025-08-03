#include <map>
#include <print>
#include <set>

int main()
{
    std::set<int> numbers = { 1, 2, 3 };
    if (numbers.contains(2)) {
        std::println("Set contains 2");
    }
    std::map<std::string, int> ages = { { "Alice", 25 }, { "Bob", 30 } };
    if (ages.contains("Alice")) {
        std::println("Map contains key 'Alice'");
    }
}

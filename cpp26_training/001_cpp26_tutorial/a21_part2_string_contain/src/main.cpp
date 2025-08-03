#include <print>
#include <string>

int main()
{
    std::string text = "hello world";
    if (text.contains("world")) {
        std::println("String contains 'world'");
    }
    if (text.contains('h')) {
        std::println("String contains 'h'");
    }
}

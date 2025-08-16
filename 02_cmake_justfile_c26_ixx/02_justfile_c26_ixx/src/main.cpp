import ixx_module;

#include <iostream>
#include <print>

int main()
{
    int result = ixx_module_api::add(2, 5);
    std::cout << "c26 hello world" << std::endl;
    std::cout << "2 + 5 = " << result << std::endl;
    std::println("c26 style : 2+ 5 = {}", result);
}

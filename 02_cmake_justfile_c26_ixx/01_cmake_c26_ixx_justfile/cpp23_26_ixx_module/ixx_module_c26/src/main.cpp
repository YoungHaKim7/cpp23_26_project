import ixx_module;
import subdiv_module;

#include <iostream>
#include <print>

int main()
{
    std::println("cpp26 + ixx");
    int result = ixx_module_api::add(2, 5);
    int sub = subdiv_api::subtract(10, 3);
    int div = subdiv_api::divide(10, 2);
    std::cout << "c26 hello world" << std::endl;
    std::cout << "2 + 5 = " << result << std::endl;
    std::cout << "10 - 3 = " << sub << std::endl;
    std::cout << "10 / 2 = " << div << std::endl;
    std::println("c26 style : 2+ 5 = {}", result);
}

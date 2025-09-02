module;
// Global module fragment
#include <cstring>
#include <string>
#include <iostream>

export module math_stuff; // Module declaration

// Only your own exports
export double add(double a, double b) {
    return a + b;
}

export void greet(const std::string& name) {
    std::string dest;
    dest = "Hello ";
    dest.append(name);
    std::cout << dest << std::endl;
}

export void print_name_length(const char* c_str_name) {
    std::cout << "Length : " << static_cast<long long>(std::strlen(c_str_name)) << std::endl;
}

module math;

#include <string>
#include <print>
#include <cstring>

void greet(const char* name) {
    std::string dest = "Hello ";
    dest.append(name);
    std::println("{}", dest);
}

int name_length(const char* c_str_name) {
    return std::strlen(c_str_name);
}

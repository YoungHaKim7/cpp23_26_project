// export module math;

// #include <cstring>
// #include <string>
// #include <print>

// export
// double add(double a, double b) {
//     return a + b;
// }

// export
// void greet(const std::string& name) {
//     std::string dest = "Hello ";
//     dest.append(name);
//     std::println("{}", dest);
// }

// export
// void print_name_length(const char* c_str_name) {
//     std::println("Length : {}", std::strlen(c_str_name));
// }


export module math;

// Only your own exports
export
double add(double a, double b) {
    return a + b;
}

export
void greet(const char* name);

export
int name_length(const char* c_str_name);

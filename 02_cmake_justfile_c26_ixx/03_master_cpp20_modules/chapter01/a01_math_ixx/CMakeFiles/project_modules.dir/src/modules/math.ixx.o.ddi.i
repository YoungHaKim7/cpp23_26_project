# 0 "/home/g/my_project/Rust_Lang/9999/2222/cpp23_26_project/02_cmake_justfile_c26_ixx/03_master_cpp20_modules/chapter01/a01_math_ixx/src/modules/math.ixx"
# 1 "/home/g/my_project/Rust_Lang/9999/2222/cpp23_26_project/02_cmake_justfile_c26_ixx/03_master_cpp20_modules/chapter01/a01_math_ixx//"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 0 "<command-line>" 2
# 1 "/home/g/my_project/Rust_Lang/9999/2222/cpp23_26_project/02_cmake_justfile_c26_ixx/03_master_cpp20_modules/chapter01/a01_math_ixx/src/modules/math.ixx"
# 25 "/home/g/my_project/Rust_Lang/9999/2222/cpp23_26_project/02_cmake_justfile_c26_ixx/03_master_cpp20_modules/chapter01/a01_math_ixx/src/modules/math.ixx"
export module math;


export
double add(double a, double b) {
    return a + b;
}

export
void greet(const char* name);

export
int name_length(const char* c_str_name);

// https://en.cppreference.com/w/cpp/io/basic_ostream/print

#include <iostream>
#include <string>
#include <print>
#include <cstdio>

std::string doit()
{
     // some long block of complex code
     return nullptr;
}

int main(void)
{
     std::string s = doit();
     std::print("{}\n", s);

}


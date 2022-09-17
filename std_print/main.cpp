// https://en.cppreference.com/w/cpp/io/basic_ostream/print

#include <iostream>
#include <string>
#include <print>
#include <cstdio>


int main(void)
{
     // c++20
     string s = format( "{} answer is {}\n, "the", 42);
     cout << s;
     
     // put string to cout
     print( "{} anser is {}", "The", 42);
     
     // put string to a file handle
     FILE* fp =  fopen("junk.txt", "w+");
     print(fp, "{} anser is {}", "The", 42);
     
     // or to a ostream
     s = "charlie";
     println(cerr, "sorry {}", s);
}


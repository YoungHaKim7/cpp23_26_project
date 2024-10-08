# link

- [`-std=c++2b`같은거_컴파일옵션 정리 버젼별c++20+23+26 & C/C++ Support in Clang](#cc-support-in-clang)
  - [`-o -Wextra -Wall` 같은거 정리](#gcc--clang)

- [나름 잘 정리된 C++](https://isocpp.org/blog/tag/experimental)
- [C++26관련 문서](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2024/p2996r5.html)
- Cpp practices
  - [Cpp best practices](https://github.com/cpp-best-practices/cppbestpractices)

<hr>

# Code Generation in Rust vs C++26 | Posted Sep 30, 2024  Updated Oct 4, 2024 | By Barry Revzin[|🔝|](#link)
- https://brevzin.github.io/c++/2024/09/30/annotations/

<hr>

# C++23 tutorial[|🔝|](#link)

[C++ Weekly - Ep 323 - C++23's auto{} and auto()](https://www.youtube.com/watch?v=5zVQ50LEnuQ)

gcc command

```
g++ -std=c++2b -Wpedantic -Wall -Wextra -Wconversion -O3 -Werror -o main main.cpp

./main
```

# C++23[|🔝|](#link)

https://en.m.wikipedia.org/wiki/C%2B%2B23

# C++23 Standard Library Preview - Jeff Garland - CppCon 2021[|🔝|](#link)

https://youtu.be/ySsqD2e5uRQ

- CppCon 2021 -

  https://cppcon.org/
  
  https://github.com/CppCon/CppCon2020

---

Despite the pandemic the C++ committee is continuing to work towards C++23. This survey presentation provides students with a broad overview of the changes and new facilities in the C++23 standard library.

<br>

# Compiler Explorer\_\_web coding[|🔝|](#link)

[compiler explorer](https://godbolt.org/)


# CppCon[|🔝|](#link)

https://github.com/CppCon/CppCon2023

https://github.com/CppCon/CppCon2022

https://github.com/CppCon/CppCon2021

https://github.com/CppCon/CppCon2020

https://github.com/CppCon

# C++23[|🔝|](#link)

https://www.modernescpp.com/index.php/ranges-improvements-with-c-23

https://en.cppreference.com/w/cpp/23

# C++ 23 Forum[|🔝|](#link)

https://cplusplus.com/forum/lounge/283965/

# C++ Core Guidelines[|🔝|](#link)

https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines

<hr>

# C/C++ Support in Clang[|🔝|](#link)

- Clang implements the following published and upcoming ISO C++ standards:
  - https://clang.llvm.org/cxx_status.html
    - https://gcc.gnu.org/onlinedocs/gcc/C-Dialect-Options.html
      - https://stackoverflow.com/questions/78069644/how-do-i-use-c-26-with-gcc-13-2-0

|Language Standard |	Flag |	Available in Clang? |
|-|-|-|
|[C++2c](https://clang.llvm.org/cxx_status.html#cxx26)<br> C++26|	-std=c++2c | Partial|
|C++23|	-std=c++23 <br> -std=c++2b |	Partial|
|C++20|	-std=c++20 <br> -std=c++2a |	Partial|
|C++17|	-std=c++17|	Clang 5|
|C++14|	-std=c++14|	Clang 3.4|
|C++11|	-std=c++11|	Clang 3.3|
|C++98/C++03	|-std=c++98 |	Yes (other than export)|
|GNU 89 | none, -std=gnu89 | |
|ANSI, ISO C90 | -ansi, -std=c89 | |
|ISO C99 | -std=c99 | |
|ISO C11 | -std=c11 | |

- (CS)컴퓨터 시스템 [ 3판 ] 김형신 저 | 퍼스트북 | 2016년 09월 06일(p35)

# GCC / Clang[|🔝|](#link)
```-Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic``` 
- use these and consider the following (see descriptions below)

## see descriptions below

- `-lm` - 필요하다면 표준 수학 함수를 추가한다. 

- ```-pedantic``` - Warn on language extensions

- ```-Wall -Wextra``` reasonable and standard

- ```-Wshadow``` warn the user if a variable declaration shadows one from a parent context

- ```-Wnon-virtual-dtor``` warn the user if a class with virtual functions has a non-virtual destructor. This helps catch hard to track down memory errors

- ```-Wold-style-cast``` warn for c-style casts

- ```-Wcast-align``` warn for potential performance problem casts
-Wunused warn on anything being unused

- ```-Woverloaded-virtual``` warn if you overload (not override) a virtual function

- ```-Wpedantic``` (all versions of GCC, Clang >= 3.2) warn if non-standard C++ is used

- ```-Wconversion``` warn on type conversions that may lose data

- ```-Wsign-conversion``` (Clang all versions, GCC >= 4.3) warn on sign conversions

- ```-Wmisleading-indentation``` (only in GCC >= 6.0) warn if indentation implies blocks where blocks do not exist

- ```-Wduplicated-cond``` (only in GCC >= 6.0) warn if if / else chain has duplicated conditions

- ```-Wduplicated-branches``` (only in GCC >= 7.0) warn if if / else branches have duplicated code

- ```-Wlogical-op``` (only in GCC) warn about logical operations being used where bitwise were probably wanted

- ```-Wnull-dereference``` (only in GCC >= 6.0) warn if a null dereference is detected

- ```-Wuseless-cast``` (only in GCC >= 4.8) warn if you perform a cast to the same type

- ```-Wdouble-promotion``` (GCC >= 4.6, Clang >= 3.8) warn if float is implicitly promoted to double

- ```-Wformat=2``` warn on security issues around functions that format output (i.e., printf)

- ```-Wlifetime``` (only special branch of Clang currently) shows object lifetime issues

- ```-Wimplicit-fallthrough``` Warns when case statements fall-through. (Included with -Wextra in GCC, not in clang)

Consider using ```-Weverything``` and disabling the few warnings you need to on Clang

- ```-Weffc++``` warning mode can be too noisy, but if it works for your project, use it also.


https://github.com/cpp-best-practices/cppbestpractices/blob/master/02-Use_the_Tools_Available.md


<hr>



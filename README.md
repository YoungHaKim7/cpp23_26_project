# link

- [gcc 최신 버젼 다운 받기](https://phoenixnap.com/kb/install-gcc-ubuntu)

- [최신 LLVM설치(clang)](#최신-llvm설치clang)

- [`-std=c++2b`같은거_컴파일옵션 정리 버젼별c++20+23+26 & C/C++ Support in Clang](#cc-support-in-clang)
  - [`-o -Wextra -Wall` 같은거 정리](#gcc--clang)

- [나름 잘 정리된 C++](https://isocpp.org/blog/tag/experimental)

- C++26
  - [C++26관련 문서(p2996r5)](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2024/p2996r5.html)
    - [p2300등 여러가 지 문서 다 모아놓았음c++](https://github.com/cplusplus/sender-receiver) 
    - [p2300r10](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2024/p2300r10.html)

- C++ 23
  - [New C++ features in GCC 13](https://developers.redhat.com/articles/2023/06/21/new-c-features-gcc-13#)
  - https://en.cppreference.com/w/c/23.html

- Cpp practices
  - [Cpp best practices](https://github.com/cpp-best-practices/cppbestpractices)

- C++26이후 최신 뉴스 모음
  - [(250428)GCC 15의 새로운 C++ 기능들 ](#gcc-15의-새로운-c-기능들-)

- C++버젼별 역사 및 정리 잘됨
  - https://dulidungsil.tistory.com/entry/GCC-%EB%B2%84%EC%A0%84%EA%B3%BC-C-%EB%B2%84%EC%A0%84-%EB%A7%A4%EC%B9%AD
  - C++ 필수 라이브러리 설명 잘됨.
    - https://doitnow-man.tistory.com/entry/C-gcc-%EB%B2%84%EC%A0%84%EA%B3%BC-libstdc-%EA%B4%80%EA%B3%84

<hr>

# `CPLUS_INCLUDE_PATH`이걸 해줘야 C++26이 된다.[|🔝|](#link)
- https://github.com/Quansight/pearu-sandbox/issues/9

```bash
export CPLUS_INCLUDE_PATH=$PREFIX/$HOST/include/c++/$GCCVERSION:$PREFIX/lib/gcc/$HOST/$GCCVERSION/include
```

- fishshell

```
set -x CPLUS_INCLUDE_PATH "$PREFIX/$HOST/include/c++/$GCCVERSION:$PREFIX/lib/gcc/$HOST/$GCCVERSION/include"

```

# gcc15최신판 다 설치하고 gcc-15 default로 만들기[|🔝|](#link)
- https://medium.com/@xersendo/moving-to-c-26-how-to-build-and-set-up-gcc-15-1-on-ubuntu-f52cc9173fa0

```
sudo update-alternatives --install /usr/bin/gcc gcc /opt/gcc-15/bin/gcc 100
sudo update-alternatives --install /usr/bin/g++ g++ /opt/gcc-15/bin/g++ 100
```

# C++ 26최신뉴스 모음[|🔝|](#link)
- [240212)2023년 C++ 에코시스템: C++20의 성장, Clang 기반 도구의 채택 확대, 개발자의 신뢰를 얻고 있는 AI | Jessie Cho | ](https://blog.jetbrains.com/ko/clion/2024/02/the-cpp-ecosystem-in-2023/)

# **[GCC 15의 새로운 C++ 기능들 ](<https://news.hada.io/topic?id=20545&utm_source=discord&utm_medium=bot&utm_campaign=1480>)**[|🔝|](#link)
- 250428
- GCC 15는 C++26 기능을 대거 추가했으며, 일부 C++23 기능도 개선했음  
- 주요 추가 기능은 **Pack Indexing**, **Variadic Friends**, **삭제 이유 명시**, **구조적 바인딩 조건문** 등  
- 새로운 컴파일러 옵션과 경고들도 도입되어 **개발자 경험**이 향상됨  
- C++ 모듈 지원이 강화되었고, 템플릿 컴파일 속…

<hr />

# gcc최신정보 및 다운로드 받기[|🔝|](#link)
- https://github.com/gcc-mirror/gcc
- https://gcc.gnu.org/

- gcc-15.1.0(Fri Apr 25 10: 36 :04 GMT 2025)
  - https://gcc.gnu.org/pipermail/gcc-announce/2025/000185.html

- gcc15최신버젼 설치방법(250731)
  - https://medium.com/@xersendo/moving-to-c-26-how-to-build-and-set-up-gcc-15-1-on-ubuntu-f52cc9173fa0
  - https://www.reddit.com/r/cpp/comments/1k7lmmn/gcc_15_released/

- gcc14버젼 설치방법
  - https://dev.to/marcosplusplus/how-to-install-gcc-14-and-use-c23-41od

# 최신 LLVM설치(clang)[|🔝|](#link)
- https://growingdev.blog/entry/llvm-clang-install
```
wget https://apt.llvm.org/llvm.sh
chmod +x llvm.sh
sudo ./llvm.sh <version number>
```

- 다른 방법
  - https://github.com/llvm/llvm-project/issues/57104

```bash
$ cmake -S llvm -B build -G Ninja \
	-DLLVM_ENABLE_PROJECTS="clang;clang-tools-extra" \
 	-DLLVM_ENABLE_RUNTIMES="compiler-rt;libcxx;libcxxabi" \
	-DLLVM_USE_LINKER=mold \
	-DCMAKE_BUILD_TYPE=Release \
	-DCMAKE_C_COMPILER=clang \
	-DCMAKE_CXX_COMPILER=clang++
$ cd build
$ cmake --build . --target install
```

# C++26: The Next C++ Standard | by Rainer Grimm이 사람이 최고[|🔝|](#link)
- August 19, 2024/0 Comments/in C++26/by Rainer Grimm
  - https://www.modernescpp.com/index.php/c26-the-next-c-standard/

<hr />

# Code Generation in Rust vs C++26 | Posted Sep 30, 2024  Updated Oct 4, 2024 | By Barry Revzin[|🔝|](#link)
- https://brevzin.github.io/c++/2024/09/30/annotations/

<hr />



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

# gcc15설치하다가 나온 메세지 분석하기

```bash
libtool: finish: PATH="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin:/sbin" ldconfig -n /opt/gcc-15/lib/../lib64
----------------------------------------------------------------------
Libraries have been installed in:
   /opt/gcc-15/lib/../lib64

If you ever happen to want to link against installed libraries
in a given directory, LIBDIR, you must either use libtool, and
specify the full pathname of the library, or use the `-LLIBDIR'
flag during linking and do at least one of the following:
   - add LIBDIR to the `LD_LIBRARY_PATH' environment variable
     during execution
   - add LIBDIR to the `LD_RUN_PATH' environment variable
     during linking
   - use the `-Wl,-rpath -Wl,LIBDIR' linker flag
   - have your system administrator add LIBDIR to `/etc/ld.so.conf'

```


# 해결
- https://github.com/Quansight/pearu-sandbox/issues/9

```
export CFLAGS="$CFLAGS -D__GLIBC_USE\(...\)=0"
```

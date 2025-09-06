// https://eel.is/c++draft/basic.fundamental

#include <print>

void fn() { }

enum Enum { A };
using Alias = int;

struct B { };

struct S : B {
    int mem;
    int : 0; // unnamed bit-field
};

template <auto> struct TCls { };

template <auto> void TFn();

template <auto> int TVar = 0;

template <auto>
concept Concept = requires { true; };

namespace NS {
}
namespace NSAlias = NS;

int main()
{
    int arr[] = { 1, 2, 3 };
    auto [a1, a2, a3] = arr;

    std::println("Structured binding: {} {} {}", a1, a2, a3);

    // The following code block is placeholder for reflection-based code
    // (will work only when `std::meta` and `^^` become available in your
    // compiler)

    /*
    constexpr auto ctx = std::meta::access_context::current();

    constexpr auto r1 = std::meta::reflect_constant(42);
    constexpr auto r2 = std::meta::reflect_object(arr[1]);
    constexpr auto r3 = ^^arr;
    constexpr auto r4 = ^^a3;
    constexpr auto r5 = ^^fn;
    constexpr auto r6 = ^^Enum::A;
    constexpr auto r7 = ^^Alias;
    constexpr auto r8 = ^^S;
    constexpr auto r9 = ^^S::mem;
    constexpr auto r10 = std::meta::members_of(^^S, ctx)[1];
    constexpr auto r11 = ^^TCls;
    constexpr auto r12 = ^^TFn;
    constexpr auto r13 = ^^TVar;
    constexpr auto r14 = ^^Concept;
    constexpr auto r15 = ^^NSAlias;
    constexpr auto r16 = ^^NS;
    constexpr auto r17 = std::meta::bases_of(^^S, ctx)[0];
    constexpr auto r18 = std::meta::data_member_spec(^^int, { .name = "member"
    });
    */
}

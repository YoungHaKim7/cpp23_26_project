// https://en.cppreference.com/w/cpp/language/attributes/assume.html
// assert(x > 0);     // trigger an assertion when NDEBUG is not defined and x > 0 is false (NDEBUG가 정의되지 않았고 x > 0이 거짓일 때 주장을 트리거합니다)
// [[assume(x > 0)]]; // provide optimization opportunities when NDEBUG is defined  (NDEBUG가 정의될 때 최적화 기회 제공])
#include <cmath>
#include <print>

int divide(int a, int b)
{
    [[assume(b != 0)]];
    return a / b;
}

void g(int val)
{
    std::println("g({})", val);
}

void h()
{
    std::println("h() called");
}

void f(int& x, int y)
{
    [[assume(x > 0)]]; // Compiler may assume x is positive

    g(x / 2); // More efficient code possibly generated

    x = 3;
    int z = x;

    [[assume((h(), x == z))]]; // Assumes h() doesn't change x

    h();
    g(x); // Compiler may replace this with g(3);

    h();
    g(x); // Cannot assume x == 3 here

    z = std::abs(y);

    [[assume((g(z), true))]]; // Assume g(z) will return

    g(z); // May be replaced with g(10) due to assumptions

    [[assume(y == -10)]]; // UB if y != -10

    [[assume((x - 1) * 3 == 12)]]; // Compiler can deduce x == 5

    g(x); // May be replaced with g(5);
}

int main()
{
    auto res = divide(10, 2);
    std::println("Result: {}", res);

    // compile error if uncommented (division by zero is UB)
    // auto res2 = divide(10, 0);
    // std::println("Result: {}", res2);

    int value = 6;
    f(value, -10);
}

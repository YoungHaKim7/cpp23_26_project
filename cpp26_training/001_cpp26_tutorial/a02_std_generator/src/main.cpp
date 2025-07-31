#include <print>
#include <generator>

// ===================================================
// Main Function
// ===================================================

std::generator<int> count(int n) {
    for (int i = 0; i < n; ++i) co_yield i;
}
int main() {
    for (int x : count(5)) std::println("{}", x);
}

// Safe error handling
#include <expected>
#include <print>

std::expected<int, const char*> safe_divide(int a, int b)
{
    if (b == 0)
        return std::unexpected("division by zero");
    return a / b;
}

// ===================================================
// Main Function
// ===================================================

int main()
{
    auto result = safe_divide(10, 2);
    if (result)
        std::println("Result: {}", *result);
}

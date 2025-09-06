#include <array>
#include <iostream>
#include <string_view>

// ================================
// User-defined types
// ================================

struct B { };

struct S : B {
    int mem;
    int : 0; // unnamed bit-field (ignored in reflection)
};

// ================================
// Reflection Utilities
// ================================

template <typename T> struct TypeName;

#define REGISTER_TYPE_NAME(T)                                                  \
    template <> struct TypeName<T> {                                           \
        static constexpr std::string_view name = #T;                           \
    };

REGISTER_TYPE_NAME(int)
REGISTER_TYPE_NAME(S)
REGISTER_TYPE_NAME(B)

template <typename T> constexpr std::string_view type_name = TypeName<T>::name;

// ============================================
// Helper to create std::array from variadic args
// ============================================

namespace detail {
template <typename... Args> constexpr auto make_string_view_array(Args... args)
{
    return std::array<std::string_view, sizeof...(Args)> { args... };
}
}

// ============================================
// General Members<T> default: no member names
// ============================================

template <typename T> struct Members {
    static constexpr auto names = detail::make_string_view_array();
};

// ============================================
// Macro for registering reflected members
// ============================================

#define REFLECT_MEMBER(CLASS, ...)                                             \
    template <> struct Members<CLASS> {                                        \
        static constexpr auto names                                            \
            = detail::make_string_view_array(__VA_ARGS__);                     \
    };

// Register reflected member names
REFLECT_MEMBER(S, "mem")

// ============================================
// Print reflected info
// ============================================

template <typename T> void print_reflected_info()
{
    std::cout << "Type: " << type_name<T> << "\nMembers: ";
    for (auto name : Members<T>::names) {
        std::cout << name << " ";
    }
    std::cout << '\n';
}

// ================================
// Main
// ================================

int main()
{
    std::cout << "Simulated reflection:\n";

    print_reflected_info<S>(); // Will show "mem"
    print_reflected_info<B>(); // Will show nothing
}
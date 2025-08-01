# mdspan
- https://en.cppreference.com/w/cpp/container/mdspan.html


# 1. `std::println` – Formatted printing

```cpp
#include <print>
int main() {
    std::println("Hello from C++26!");
}
```

# 2. `std::generator` – Lazy range generation

```cpp
#include <generator>
std::generator<int> count(int n) {
    for (int i = 0; i < n; ++i) co_yield i;
}
int main() {
    for (int x : count(5)) std::println("{}", x);
}
```

# 3. `std::mdspan` – Multi-dimensional array view

```cpp
#include <mdspan>
int main() {
    int data[6] = {1, 2, 3, 4, 5, 6};
    std::mdspan view(data, 2, 3);
    std::println("Element at (1,2): {}", view(1, 2));
}
```

# 4. `std::expected` – Safe error handling

```cpp
#include <expected>
std::expected<int, const char*> safe_divide(int a, int b) {
    if (b == 0) return std::unexpected("division by zero");
    return a / b;
}
int main() {
    auto result = safe_divide(10, 2);
    if (result) std::println("Result: {}", *result);
}
```

# 5. `[[assume(cond)]]` – Assumptions for optimizers

```cpp
int divide(int a, int b) {
    [[assume(b != 0)]];
    return a / b;
}
```

# 6. `std::move_only_function` – Move-only function wrappers

```cpp
#include <functional>
int main() {
    std::move_only_function<void()> f = [] { std::println("Moved!"); };
    f();
}
```

# 7. `consteval if` – Immediate if in compile-time contexts

```cpp
consteval int choose(bool flag) {
    if consteval { return flag ? 1 : 2; }
    else return 3;
}
```

# 8. `static operator()` – Static call operator in lambdas

```cpp
struct S {
    static void operator()() {
        std::println("Static operator()");
    }
};
int main() {
    S{}();
}
```

# 9. `std::flat_map` – Flat associative containers (P2786)

```cpp
#include <flat_map>
int main() {
    std::flat_map<int, std::string> fm = {{1, "a"}, {2, "b"}};
    std::println("Key 2: {}", fm[2]);
}
```

# 10. `std::range` improvements – zip, cartesian_product

```cpp
#include <ranges>
int main() {
    auto r = std::views::iota(1, 4);
    for (auto [a, b] : std::views::zip(r, r)) {
        std::println("{} {}", a, b);
    }
}
```

# 11. `std::valarray` SIMD upgrades

```cpp
#include <valarray>
int main() {
    std::valarray<int> a = {1, 2, 3};
    std::valarray<int> b = {4, 5, 6};
    std::valarray<int> c = a + b;
    std::println("{}", c[0]);
}
```

# 12. `std::resize_and_overwrite` on std::string

```cpp
#include <string>
int main() {
    std::string s;
    s.resize_and_overwrite(5, [](char* buf, size_t n) {
        std::fill(buf, buf + n, '*');
        return n;
    });
    std::println("{}", s);
}
```

# 13. `constexpr` dynamic memory

```cpp
consteval int sum() {
    auto* ptr = new int(42);
    int val = *ptr;
    delete ptr;
    return val;
}
```

# 14. `std::print` with file output

```cpp
#include <print>
#include <fstream>
int main() {
    std::ofstream out("log.txt");
    std::print(out, "Hello {}\n", "file");
}
```

# 15. `std::source_location` – Caller info

```cpp
#include <source_location>
void log(const std::source_location& loc = std::source_location::current()) {
    std::println("{}:{} - {}", loc.file_name(), loc.line(), loc.function_name());
}
int main() {
    log();
}
```

# 16. `std::format` – Extended format

```cpp
#include <format>
int main() {
    std::string msg = std::format("{:>10}", "hi");
    std::println("{}", msg);
}
```

# 17. `if consteval` – Runtime vs compile-time branching

```cpp
template<typename T>
constexpr int check() {
    if consteval return 1;
    else return 0;
}
```

# 18. `std::bind_back` – Partial binding from the right

```cpp
#include <functional>
void greet(std::string who, std::string from) {
    std::println("Hello {}, from {}", who, from);
}
int main() {
    auto f = std::bind_back(greet, "world");
    f("C++26");
}
```

# 19. `span` – Safer array handling

```cpp
#include <span>
void print(std::span<int> s) {
    for (auto i : s) std::println("{}", i);
}
int main() {
    int arr[] = {1, 2, 3};
    print(arr);
}
```

# 20. `std::is_scoped_enum` – Type trait

```cpp
#include <type_traits>
enum class E { A, B };
int main() {
    static_assert(std::is_scoped_enum_v<E>);
}
```

# 21. `std::ranges`::contains

```cpp
#include <ranges>
#include <vector>
int main() {
    std::vector v = {1, 2, 3};
    bool has = std::ranges::contains(v, 2);
    std::println("Has 2? {}", has);
}
```

# 22. `constexpr std::vector`

```cpp
#include <vector>
consteval int sum() {
    std::vector<int> v = {1, 2, 3};
    return v[0] + v[1] + v[2];
}
```

# 23. `deducing this –` Deduced object parameter

```cpp
struct Point {
    int x, y;
    auto move(this Point self, int dx, int dy) {
        return Point{self.x + dx, self.y + dy};
    }
};
```

# 24. `explicit(true/false)` – Context-sensitive constructors

```cpp
struct A {
    explicit(true) A(int) {} // always explicit
};
```

# 25. `requires` clauses for concepts

```cpp
template<typename T>
concept Addable = requires(T a, T b) { a + b; };
```

# 26. `std::unreachable()` – Mark unreachable code

```cpp
#include <utility>
int main() {
    if (false) std::unreachable();
}
```

# 27. `std::expected<void, E>` support

```cpp
std::expected<void, const char*> try_something(bool ok) {
    if (!ok) return std::unexpected("fail");
    return {};
}
```

# 28. `std::ranges::chunk` – Grouped ranges

```cpp
#include <ranges>
int main() {
    auto r = std::views::iota(1, 7) | std::views::chunk(3);
    for (auto group : r) {
        for (auto v : group) std::print("{} ", v);
        std::println("");
    }
}
```

# 29. `std::lazy_split` – Lazy string splitting

```cpp
#include <ranges>
#include <string_view>
int main() {
    std::string_view text = "a:b:c";
    auto r = std::views::lazy_split(text, ':');
    for (auto sv : r) std::println("{}", std::string_view(sv));
}
```

# 30. `std::tuple` – Structured bindings and formatting

```cpp
#include <tuple>
#include <print>
int main() {
    auto [a, b] = std::make_tuple(1, 2);
    std::println("{} {}", a, b);
}
```

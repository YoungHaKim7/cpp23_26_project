#include <type_traits>

enum class E { A, B};

int main()
{
    static_assert(std::is_scoped_enum_v<E>);
}

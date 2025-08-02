#include <print>
#include <valarray>

int main()
{
    std::valarray<int> a = {1, 2, 3};
    std::valarray<int> b = {4, 5, 6};
    std::valarray<int> c = a + b;
    std::println("{}", c[0]);
}

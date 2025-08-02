#include <print>

struct S {
    void operator()() {
        std::println("operator()");
    }
};

int main()
{
    S{}();
}

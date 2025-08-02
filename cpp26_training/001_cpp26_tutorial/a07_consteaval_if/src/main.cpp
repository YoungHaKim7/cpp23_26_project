#include <print>

consteval int choose(bool flag) {
    if consteval { return flag ? 1 : 2; }
    else { return 3; }
}

int main()
{
    int res = choose(3);
    std::print("choose : {}", res);
}

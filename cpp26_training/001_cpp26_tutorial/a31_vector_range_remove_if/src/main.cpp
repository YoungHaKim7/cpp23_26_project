#include <iostream>
#include <vector>

int main()
{
    std::vector<int> values { 2, 3, 4, 5, 8 };
    auto is_even = [](int x) { return x % 2 == 0; };
    auto new_end = std::remove_if(values.begin(), values.end(), is_even);
    // values.erase(new_end, values.end());
    for (auto it = values.begin(); it != new_end; it++) {
        std::cout << *it << std::endl;
    }

    return 0;
}

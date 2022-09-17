#include <iostream>
#include <string>
#include <vector>

void erase_all_of_first(auto &container) {
  std::erase(container, container.front());
}


int main() {
  std::vector<std::string> values{"test3", "test3", "hello there world",
                                  "bob", "test", "hello there world"};
  erase_all_of_first(values);

  for (const auto &str : values) {
    std::cout << str << '\n';
  }
}
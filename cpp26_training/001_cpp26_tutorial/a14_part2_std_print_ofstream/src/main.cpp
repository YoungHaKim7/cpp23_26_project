#include <print>
#include <fstream>

int main() {
    std::ofstream out("log.txt");
    std::print(out, "Hello {}\n", "file");
}


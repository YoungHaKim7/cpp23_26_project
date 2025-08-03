#include <fstream>
#include <print>

int main()
{
    std::ofstream out("log.txt");
    std::print(out, "Hello {}\n", "file");
}

#include <print>
#include <source_location>

void log(const std::source_location& loc = std::source_location::current())
{
    std::println(
        "{}:{} - {}", loc.file_name(), loc.line(), loc.function_name());
}

int main()
{
    std::println("std::source_location");
    log();
}

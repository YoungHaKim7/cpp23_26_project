#include <format>
#include <print>
#include <vector>

struct Point {
    int x, y;
    auto move(this Point self, int dx, int dy)
    {
        return Point { self.x + dx, self.y + dy };
    }
};

template <> struct std::formatter<Point> {
    constexpr auto parse(std::format_parse_context& ctx) { return ctx.begin(); }

    auto format(const Point& p, std::format_context& ctx) const
    {
        return std::format_to(ctx.out(), "({}, {})", p.x, p.y);
    }
};

int main()
{
    Point p { 1, 2 };
    std::println("{}", p);
}
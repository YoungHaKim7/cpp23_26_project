#include <print>

template <typename... Ts> class Passkey {
    friend Ts...;
    Passkey() { }
};

class A;
class B;

struct Widget {
    void secret(Passkey<A, B>) { std::println("secret() called"); }
};

class A {
public:
    void doit(Widget& w)
    {
        w.secret({}); // OK
    }
};

class B {
public:
    void doit(Widget& w)
    {
        w.secret({}); // OK
    }
};

class D {
public:
    void doit(Widget& w)
    {
        // w.secret({}); // won't compile!
    }
};

int main()
{
    Widget w;
    A a;
    B b;
    D d;

    std::println("Calling secret() from A");
    a.doit(w);

    std::println("Calling secret() from B");
    b.doit(w);

    std::println("Calling secret() from D (will not compile)");
    d.doit(w);

    std::println("PassKey idioms demonstrated");
}

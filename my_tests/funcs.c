int f();
int g() { return 0; }
int h();
int h() { return 0; }

int e(int x);
int d(int x, bool b);

int main() {
    int x;
    bool b;
    x(); // error: undeclared function
    f();
    g();
    h();
    i(); // error: undeclared function

    f(x); // error: different number of parameters
    e(); // error: different number of parameters
    e(x);
    e(x, x); // error: different number of parameters
    e(b); // error: different parameter types
    e(x, b); // error: different number of parameters
    e(b, x); // error: different number of parameters
    d(x, b);
    d(b, x); // error: different parameter types

    x = e(x);
    x = e(b); // error: different parameter types
    x = e(); // error: different number of parameters

    getint(); // error: undeclared function

    return 0;
}
int f();
void f(); // error: different return type

void g();
int g() { return 0; } // error: different return type

void h(int x);
void h(int x, int y); // error: different number of parameters

void i(int x);
void i(bool x); // error: different parameter type

void j(int x);
void j(int y);

void k(int x);
void k(bool x, bool y); // error: different number of parameters

void l(int x, int y);
void l(int x, bool y); // error: different parameter type

void m(int x, bool y);
void m(bool x, int y); // error: different parameter type

void n(int x) { return; }
void n(int x) { return; } // error: redefinition of 'n'

int main() {
    return 0;
}
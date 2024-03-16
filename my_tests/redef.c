int a;
bool b;

void f(int a, int b, int c, int c, int d, bool d); // error: redefinition of 'c', 'd'

void g(int a, int b, int c, int c, int d, bool d) {} // error: redefinition of 'c', 'd'

int main() {
    int x, x, y, z, a, b; // error: redefinition of 'x'
    int y; // error: redifinition of 'y'
    bool z; // error: redefinition of 'z'
    return 0;
}
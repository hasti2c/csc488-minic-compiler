int y;
int z;

void f(int x, bool z) {
    n; // error: undeclared variable
    x;
    y;
    z = true;
    z = 1; // error: different types
}

int main() {
    int n, a[5];
    bool z;
    10000000000000000; // error: out-of-range
    -10000000000000000; // error: out-of-range
    n = 10000000000000000; // error: out-of-range
    n = -10000000000000000; // error: out-of-range

    n[2]; // error: non-array type
    n = true; // error: different types
    n = a; // error: different types

    a;
    a[2];
    a[true]; // error: non-int index
    a[3 + 3];
    a = n; // error: different types

    x; // error: undeclared variable
    x = 2; // error: undeclared variable
    y;
    z = 3; // error: different types
    z = true;

    f; // error: undeclared variable
    f = 3; // error: undeclared variable
    return 0;
}
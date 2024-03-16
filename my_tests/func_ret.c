void f() {}
void g() { return; }
void h() { return 0; } // error: has returned expression

int i() {} // error: needs to return a value
int j() { return; } // error: has no returned expression
int k() { return 0; }
int l() { return true; } // error: wrong return type
int m() {
    int a[5];
    return a; // error: wrong return type
}
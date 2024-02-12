// This program takes an integer n and determines if it is a power of 2.
// If n is a power of 2, it prints the power (e.g. if n is 8, 3 is printed).
// If n is not a power of 2 or n is non-positive, it prints -1.
#include "minicio.h"

bool positive(int x) {
    return x > -x;
}

bool even(int x) {
    return (x / 2) * 2 == x;
}

int solve(int x) {
    int i;
    for (i = 0; even(x); i = i + 1)
        x = x / 2;
    if (x == 1)
        return i;
    else
        return -1;
}

int main() {
    int n, ret;
    n = getint();
    if (positive(n))
        ret = solve(n);
    else
        ret = -1;
    putint(ret);
    putnewline();
    return 0;
}

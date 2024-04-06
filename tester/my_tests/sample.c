#include "minicio.h"

int f(int x) {
    int i;
    i = 0;
    for (; i < 100 * 1000 * 1000; i = i + 1) {
        x = x + 0;
        x = x - 0;
        x = x * 1;
        x = x / 1;
        x = x + x * 0;
        x = x + 0 / x;
    }
    return x;
}

int main() {
    int x;
    x = f(10);
    putint(x);
    return 0;
}

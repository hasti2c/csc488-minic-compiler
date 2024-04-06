// A6 Private test 2: Function calls
// #include "minicio.h"

int gen_rand(int seed) {
    int i;
    int out;
    int rand1, rand2;
    rand1 = 29;
    rand2 = 167;

    out = seed * rand1;
    if (out > rand1) out = out - rand2;
    else out = out + rand2;

    for (i = rand1; i < rand2; i = i + 3) {
        out = out + i;
    }
    return out;
}

int fib(int t) {
    if (t <= 0) 
        return 0;
    if (t == 1)
        return 1;
    if (t > 40)
        return t / 3;
    return fib(t - 1) + fib(t - 2);
}

int pow(int i, int e) {
    for (e; e > 0; e = e - 1) 
        i = i * i;
    return i;
}

void looping() {
    int x;
    for (x = 100; x > 0; x = x - 1) {
        fib(x);
        gen_rand(x);
        pow(x, 5);
    }
}

void main() {
    looping();
}
// A6 Private test 1: Matrix Multiplication
#include "minicio.h"

// Takes a number and outputs another "pseudorandom" number
// Does some busy work like looping inside
int generate_num(int seed) {
    int i;
    int out;
    int rand1, rand2;
    rand1 = 3761;
    rand2 = 162587;

    out = seed * rand1;
    if (out > rand1) out = out - rand2;
    else out = out + rand2;

    for (i = rand1; i < rand2; i = i * 2) {
        out = out + i;
    }
    out = out / 7;
    return out;
}

// "Unit test" for above function
void test_generate_num() {
    // Test: Generate nums
    int i, total;
    for (i = 3000; i < 3010; i = i + 1) {
        total = generate_num(i);
        total = total / 3;
        putint(total);
        putnewline();
    }
}

// One dimensional Matrix multiplication
void matrix_multiply() {
    // 10 by 10 matrix
    int ROWS, COLS;
    int i, j, k;
    int r, c, r2;
    int m1[100], m2[100], result[100];
    ROWS = 10;
    COLS = 10;

    // Build the matrix with our number generator
    for (i = 0; i < ROWS; i = i + 1) {
        for (j = 0; j < COLS; j = j + 1){
            r = ROWS * i;
            m1[r + j] = generate_num(i + j);
            m2[r + j] = generate_num(j - 17);
            // putint(m2[r + j]);
            // putnewline();
        }
    }

    // Matrix Multiplication
    for (i = 0; i < ROWS; i = i + 1) {
        for (j = 0; j < COLS; j = j + 1){
            for (k = 0; k < COLS; k = k + 1) {
                r = ROWS * i;
                r2 = ROWS * k;
                result[r + j] = m1[r + k] * m2[r2 + j];
                // putint(result[r + j]);
                // putnewline();
            }
        }
    }
}

void main() {
    // Test: Generate nums
    // test_generate_num();
    matrix_multiply();
}
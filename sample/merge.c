// This program takes two arrays of integers (each of length at most 100) as input (assumed to each be sorted). Then it merges them (while preserving increasing order of elements) and prints the output. 
#include "minicio.h"

int N, M, a[100], b[100], c[200], i, j;

bool read_input() { // Returns true iff successful.
    N = getint();
    M = getint();
    if (N > 100 || M > 100)
        return false;
    for (i = 0; i < N; i = i + 1)
        a[i] = getint();
    for (i = 0; i < M; i = i + 1)
        b[i] = getint();
    return true;
}

void merge() {
    i = 0;
    j = 0;
    while (i < N && j < M) {
        if (a[i] <= b[j]) {
            c[i + j] = a[i];
            i = i + 1;
        } else {
            c[i + j] = b[j];
            j = j + 1;
        }
    }
    for (; i < N; i = i + 1)
        c[i + j] = a[i];
    for (; j < M; j = j + 1)
        c[i + j] = b[j];
}

void print_output() {
    for (i = 0; i < N + M; i = i + 1) {
        putint(c[i]);
        putcharacter(' ');
    }
    putnewline();
}

int main() {
    if (!read_input())
        return 1;
    merge();
    print_output();
    return 0;
}

#include <stdio.h>

int getint() {
    int ret;
    scanf("%d", &ret);
    return ret;
}

void putint(int v) {
    printf("%d ", v);
}

void putcharacter(char c) {
    printf("%c ", c);
}

void putnewline() {
    printf("\n");
}

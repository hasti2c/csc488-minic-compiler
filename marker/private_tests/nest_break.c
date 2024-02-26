#include "minicio.h"

int x;
int arr[10];

int main() {
    x = 5;
    for (x = 0; x < 10; x = x + 1)
        if (x == 5) {
            break;
        }
        arr[x] = x;
    return 0;
}
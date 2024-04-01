#include "minicio.h"

int main() {
    int i;
    int j;
    int k;

    i = 0;
    j = 0;
    k = 0;
                

    for (j=0; j < 20; j = j+1) {
        if (j < 15){
            continue;
        }
        putint(j);
        
    }
    putnewline();
    i = i + 1;
    for (j=0; j < 20; j = j+1) {
        if (j > 2){
            continue;
        }
        for(;i < 10; i = i+1){
            if (i > 5){
                continue;
            }
            k = i + j;
            putint(k); 
        }
    }

    return 1;
}
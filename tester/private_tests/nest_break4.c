#include "minicio.h"

bool is_even(int x){
    int i;
    i = 0;
    for(;i < x;){
        if(i * 2 == x){
            return true;
        }
        if((i * 2) + 1 == x){
            return false;
        }
        i = i + 1;
    }
    return false;
}
int main(){
    int x, y, z;
    int i, n;
    int total;
    total = 0;
    for(;;){
        x = getint();
        if(x == 0 || total > 0){
            break;
        }
        y = getint();
        z = getint();
        i = 0;
        n = 0;
        for(;i < y;){
            if(is_even(x + i)){
                putint(x + i);
                n = n + 1;
            }
            if(n >= z){
                break;
            }
            i = i + 1;
        }
        total = total + 1;
    }
    return 0;
}
#include "minicio.h"
int arr[10];
bool error(){
    int e;
    e = 10000;
    arr[e];
    return false;
}

bool success(){
    int s;
    for(s = 0; s < 10; s=s+1){
        arr[s] = arr[s] + s;
    }
    return true;
}

int main(){
    if(true || error()){
        putint(0);
        putnewline();
    }
    if(false && success()){
        return 1;
    }
    if(true && success()){
        int i;
        for(i = 0; i < 10; i=i+1){
            putint(arr[i]);
        }
        putnewline();
    }
    return 0;
}
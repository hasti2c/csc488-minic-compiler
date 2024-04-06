
//C program for Tower of Hanoi using Recursion

#include "minicio.h"

void towers(int num, int frompeg, int topeg, int auxpeg)
{
    if (num == 1)
    {
        putint(1);
        putint(frompeg);
        putint(topeg);
        putnewline();
        return;
    }
    towers(num - 1, frompeg, auxpeg, topeg);
    //num in putint here is the index of disk
    putint(num);
    putint(frompeg);
    putint(topeg);
    putnewline();
    towers(num - 1, auxpeg, topeg, frompeg);
}

int main()
{
    int num;
    num = getint();
    towers(num, 0, 2, 1);
    return 0;
}
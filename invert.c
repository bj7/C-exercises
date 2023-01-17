#include <stdio.h>
#include "printBin.h"

unsigned invert(int x, int p, int n)
{
    // get the bit range we want at the right most side
    // x7x6x5x4 x3x2x1x0
    int numBitstoShift = p - n;
    int x1 = x >> numBitstoShift;

    // generate a copy of the desired set of bits
    // 0000 1111
    int mask = (1 << n) - 1;
    // 0000 x3x2x1x0
    int c = mask & x1;

    // shift the copy back into position of where we want p - n
    // x3x2x1x0 0000
    int c1 = c << (p - n);
    // invert it 
    c1 = ~c1;

    // combine them, the other bits will stay the same
    return c1 & x;
}

int main() 
{
    int x = 0xFFFF;
    int p = 8;
    int n = 4;

    printBin(x);
    int inverted = invert(x, p, n);
    printBin(inverted);
}
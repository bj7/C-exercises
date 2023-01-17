#include <stdio.h>
#include "printBin.h"

unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p+1-n)) & ~(~0 << n);
}

unsigned setbits(int x, int p, int n, int y)
{
    // create mask of first n-bits of y
    int mask = (1 << n) - 1;
    int rightMostBits = mask & y;
    printf("right most y bits: ");
    printBin(rightMostBits);

    // poke a n-sized hole in x at offset p
    int poker = ~(mask << (p - n - 1));
    int xhole = x & poker;
    printf("hole puncher: ");
    printBin(xhole);
    
    // shift our bits over to fill the hole at p
    int filler = rightMostBits << (p - n);
    printf("filler: ");
    printBin(filler);
    int final = xhole | filler;
    printBin(final);
    return final;
}

int main() 
{
    int x = 0xCD;
    int y = 0xDE;
    int p = 4;
    int n = 2;
    
    printf("x value: ");
    printBin(x);
    printf("y value: ");
    printBin(y);
    
    int answer = setbits(x, p, n, y);
    printf("%X\n", answer);
}
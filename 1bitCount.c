#include <stdio.h>

int main()
{
    int b = 0xcd;
    int c = 0;

    while (b) {
        c++;
        b &= (b-1);
    } 
    
    printf("Number of 1 bits %d\n", c);
}
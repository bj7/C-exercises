#include <stdio.h>
#include "printBin.h"

void printBin(int n)
{
    while (n) {
        if (n & 1) {
            printf("1");
        } else {
            printf("0");
        }

        n >>= 1;
    }

    printf("\n");
}

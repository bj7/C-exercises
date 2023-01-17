#include <string.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>

int htoi(char s[]);

int main(int argc, char* argv[]) 
{
    printf("%d\n", htoi(argv[1]));
}

int htoi(char s[]) 
{
    int powers = strlen(s) - 1;
    int output = 0;
    int i = 0;
    
    if (s[0] == '0' && tolower(s[1]) == 'x') {
        // skip
        i = 2;
        powers -= 2;
    } 
    
    while (s[i] != '\0') {
        // get decimal representation
        int dec = s[i] - '0';
        output += dec * pow(16.0, powers);
        powers--;
        i++;
    }

    return output;
}
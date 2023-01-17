#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <string.h>
#include <ctype.h>

#define BELL '\x7'

int main()
{
	char ch;
	int i;
	float fl;
	double db;
	short sh;
	long l;
	signed long sl;
	char s[] = "this is a test";

	float x = 4.5;
	int y = 5;
	printf("x=%f; y=%d\n", x, y);
	y = x;
	x = y;
	printf("x=%f; y=%d\n", x, y);
	

	printf("length is %ld\n", strlen(s));
	printf("%s\n", s);
	printf("0X%X\n", s[3]);
	printf("%d\n", s[3]);
	printf("0X%X\n", s[120]);

	printf("modulo %d\n", 14%3);

	printf("%ld byte\n", sizeof ch);
	printf("%ld bytes\n", sizeof i);
	printf("%ld bytes\n", sizeof fl);
	printf("%ld bytes\n", sizeof db);
	printf("%ld bytes\n", sizeof l);
	printf("%ld bytes\n", sizeof sl);
	printf("%c\n", BELL);

	printf("%d\n", UCHAR_MAX);
	printf("%d\n", isdigit('s'));
}
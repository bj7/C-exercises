#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100 // max size of operand or operator
#define NUMBER 0
#define MAXVAL 100 // max depth of value stack
#define BUFSIZE 100

double getTop(void);
 
char buf[BUFSIZE];
int bufp = 0;
int getch(void);
void ungetch(int);
int sp = 0;
double val[MAXVAL];
int getop(char []);
void push(double);
double pop(void);

int main()
{
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch(type) {
			case NUMBER: 
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0) {
					push(pop() / op2);
				} else {
					printf("error: zero divisor\n");
				}
				break;
			case '%':
				op2 = pop();
				int result = (int)pop() % (int)op2;
				push((double)result);
				break;
			case 'p': // print top 
				printf("\t%.8g\n", getTop());
				break;
			case 'd': // duplicate top
				op2 = getTop();
				push(op2);
				break;
			case 's': // swap top two
				op2 = pop();
				double nt = pop();
				push(op2);
				push(nt);
				break;
			case 'c': // clear
				sp = 0;
				break;
			case '\n':
				printf("\t%.8g\n", pop());
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;
		}
	}
	return 0;
}

void push(double f) 
{
	if (sp < MAXVAL) {
		// printf("double f %g\n", f);
		val[sp++] = f;
	} else {
		printf("error: stack full, can't push %g\n", f);
	}
}

double getTop(void)
{
	if (sp > 0) {
		double r = val[sp-1];
		// printf("val[--sp] %g\n", r);
		return r; 
	} else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

double pop(void)
{
	if (sp > 0) {
		double r = val[--sp];
		// printf("val[--sp] %g\n", r);
		return r; 
	} else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

int getop(char s[])
{
	int i, c;

	while((s[0] = c = getch()) == ' ' || c == '\t') {
		continue;
	}

	s[1] = '\0';

	if (!isdigit(c) && c != '.' && c != '-') {
		return c;
	}

	i = 0;
	
	if (isdigit(c)) {
		// while (isdigit(s[++i] = c = getch())) {
		//     continue;
		// }
		while (isdigit(c)) {
			c = getch();
			s[++i] = c;
		}
	}

	if (c == '.') {
		while (isdigit(s[++i] = c = getch())) {
			continue;
		}
	}

	if (c == '-') {
		while (isdigit(s[++i] = c = getch())) {
			continue;
		}
	}

	s[i] = '\0'; // EOF

	if (c != EOF) {
		ungetch(c);
	}

	return NUMBER;
}

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE) {
		printf("ungetch: too many characters\n");
	} else {
		buf[bufp++] = c;
	}
}

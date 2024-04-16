#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a, b;
	int ra = 0;
	int rb = 0;

	scanf("%d %d", &a, &b);

	ra = a / 100;
	ra += ((a % 100) / 10) * 10;
	ra += (a % 10) * 100;

	rb = b / 100;
	rb += ((b % 100) / 10) * 10;
	rb += (b % 10) * 100;

	if (ra > rb)
		printf("%d", ra);
	else
		printf("%d", rb);
}
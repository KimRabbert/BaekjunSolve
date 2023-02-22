#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int first;
	int a = 0, b = 0;
	int n = 0;
	int sec = -1;
	int cycle = 0;

	scanf("%d", &first);

	n = first;

	while (first != sec) {
		cycle++;
		a = n / 10;
		b = n % 10;
		n = a + b;
		n = b * 10 + n % 10;
		sec = n;
	}

	printf("%d", cycle);
}
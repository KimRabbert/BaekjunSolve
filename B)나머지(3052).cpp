#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	bool remainder[42];
	int i, x;
	int count = 0;

	for (i = 0; i < 42; i++)
		remainder[i] = false;

	for (i = 0; i < 10; i++) {
		scanf("%d", &x);
		remainder[x % 42] = true;
	}

	for (i = 0; i < 42; i++)
		if (remainder[i])
			count++;

	printf("%d", count);
}
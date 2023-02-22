#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n;
	int sigma = 0;

	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		sigma += i;

	printf("%d", sigma);
}
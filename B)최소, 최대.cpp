#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n, a;
	int max = -1000000;
	int min = 1000000;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		if (a > max)
			max = a;
		if (a < min)
			min = a;
	}

	printf("%d %d", min, max);
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n, sc;
	int sum = 0;
	int max = 0;
	float avg;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &sc);
		sum += sc;
		if (sc > max)
			max = sc;
	}

	avg = (float)sum * 100 / max / n;

	printf("%.3f", avg);
}
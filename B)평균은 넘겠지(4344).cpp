#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int c, n;
	int i, j;
	float avg;
	int sum = 0;
	int over = 0;
	int* sc;

	scanf("%d", &c);

	for (i = 0; i < c; i++) {
		scanf("%d", &n);
		sc = (int*)malloc(sizeof(int) * n);

		for (j = 0; j < n; j++) {
			scanf("%d", &sc[j]);
			sum += sc[j];
		}

		avg = (float)sum / n;

		for (j = 0; j < n; j++)
			if (sc[j] > avg)
				over++;

		printf("%.3f%%\n", (float)over / n * 100);

		sum = 0;
		over = 0;
		free(sc);
	}
}
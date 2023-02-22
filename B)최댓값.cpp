#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int max = -1;
	int maxl[2] = { 0, };
	int a;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%d", &a);
			if (a > max) {
				max = a;
				maxl[0] = i + 1;
				maxl[1] = j + 1;
			}
		}
	}

	printf("%d\n", max);
	printf("%d %d", maxl[0], maxl[1]);
}
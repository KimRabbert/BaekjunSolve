#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int max = 0;
	int maxloc;
	int x;

	for (int i = 0; i < 9; i++) {
		scanf("%d", &x);
		if (x > max) {
			max = x;
			maxloc = i + 1;
		}
	}

	printf("%d\n%d", max, maxloc);
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int t, r;
	char s[20];
	int i, j, k;

	scanf("%d", &t);

	for (i = 0; i < t; i++) {
		scanf("%d %s", &r, s);

		for (j = 0; s[j] != NULL; j++)
			for (k = 0; k < r; k++)
				printf("%c", s[j]);

		printf("\n");
	}
}
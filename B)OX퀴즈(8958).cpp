#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	char tc[80];
	int total = 0;
	int ox = 0;
	int n;
	int len;
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", tc);
		len = strlen(tc);

		for (int j = 0; j < len; j++) {
			if (tc[j] == 'O') {
				ox++;
				total += ox;
			}
			else
				ox = 0;
		}

		printf("%d\n", total);
		total = 0;
		ox = 0;
	}
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int i, s;
	bool num[31];

	for (i = 1; i <= 30; i++)
		num[i] = true;
	
	for (i = 0; i < 28; i++) {
		scanf("%d", &s);
		num[s] = false;
	}

	for (i = 1; i <= 30; i++)
		if (num[i])
			printf("%d\n", i);
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int total, n;
	int a, b;
	
	scanf("%d", &total);
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		total -= a * b;
	}

	if (total == 0)
		printf("Yes");
	else
		printf("No");
}
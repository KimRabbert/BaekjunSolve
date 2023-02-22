#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n;
	char num[100];
	int sum = 0;

	scanf("%d", &n);
	scanf("%s", num);

	for (int i = 0; i < n; i++)
		sum += num[i] - 48;

	printf("%d", sum);
}
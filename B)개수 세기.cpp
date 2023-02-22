#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int* arr;
	int n, i, x;
	int count = 0;
	scanf("%d", &n);

	arr = (int*)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	scanf("%d", &x);

	for (i = 0; i < n; i++)
		if (arr[i] == x)
			count++;

	printf("%d", count);

	free(arr);
}
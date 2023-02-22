#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

bool hansu(int);

int main() {
	int n;
	int count = 0;

	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		if (hansu(i))
			count++;

	printf("%d", count);
}

bool hansu(int n) {
	int a, b, c;

	if (n < 100) {
		return true;
	}
	else if (n < 1000) {
		a = n / 100;
		b = (n % 100) / 10;
		c = n % 10;

		if ((a - b) == (b - c))
			return true;
		else
			return false;
	}
	else
		return false;
}
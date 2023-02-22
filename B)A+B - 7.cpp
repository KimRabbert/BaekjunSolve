#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a, b, n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &a, &b);
		printf("Case #%d: %d\n", i, a + b);
	}
}
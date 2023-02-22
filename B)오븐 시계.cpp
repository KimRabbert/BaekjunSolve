#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int h, m;
	int t;
	
	scanf("%d %d", &h, &m);
	scanf("%d", &t);

	m += t;
	h += m / 60;
	m = m % 60;
	h = h % 24;

	printf("%d %d", h, m);
}
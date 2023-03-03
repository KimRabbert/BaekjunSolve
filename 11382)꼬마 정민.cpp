#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	long long int a, b, c; 

	scanf("%lld %lld %lld", &a, &b, &c); // a, b, c 입력 (1 <= a, b, c <= 10^12)
	printf("%lld", a + b + c); // a + b + c 출력
}
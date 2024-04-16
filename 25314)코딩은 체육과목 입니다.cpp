#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int by;
	int n;

	scanf("%d", &by); //바이트 입력 (4 <= by <= 1000, by는 4의 배수)

	n = by / 4;  //바이트를 4로 나누어 반복횟수 지정

	for (int i = 0; i < n; i++)
		printf("long ");
	printf("int");
}
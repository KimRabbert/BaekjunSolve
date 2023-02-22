#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	char a, c = ' ';
	int count = 0;

	do {
		scanf("%c", &a);
		if ((a == ' ' || a == '\n') && c != ' ') // 처음과 마지막에 공백이 나올 경우를 제외
			count++;
		c = a;
	} while (a != NULL && a != '\n');

	printf("%d", count);
}
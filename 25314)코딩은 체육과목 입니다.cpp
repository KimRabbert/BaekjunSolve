#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int by;
	int n;

	scanf("%d", &by); //����Ʈ �Է� (4 <= by <= 1000, by�� 4�� ���)

	n = by / 4;  //����Ʈ�� 4�� ������ �ݺ�Ƚ�� ����

	for (int i = 0; i < n; i++)
		printf("long ");
	printf("int");
}
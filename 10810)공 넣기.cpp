#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int basket_n; // �ٱ����� ���� [1,100]
	int basket[101];
	int n; // �ٱ��Ͽ� ���� ���� Ƚ�� [1,100]
	int start, end; // �ٱ����� ���� ���۰� ��
	int ball; // �ٱ��Ͽ� �� ���� ��ȣ
	int i, j;

	for (i = 1; i <= 100; i++) // �迭 �ʱ�ȭ
		basket[i] = 0;
	
	scanf("%d %d", &basket_n, &n);

	for (i = 0; i < n; i++) {
		scanf("%d %d %d", &start, &end, &ball);
		for (j = start; j <= end; j++)
			basket[j] = ball;
	}

	for (i = 1; i <= basket_n; i++) // �ٱ��� ���
		printf("%d ", basket[i]);
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int basket_q; // �ٱ����� ���� [1,100]
	int basket[101]; // �ٱ��� �迭
	int basket2[101];
	int range_n; // ��ȯ Ƚ�� [1,100]
	int a, b; // ���� ���۰� �� a, b [1,basket_q]
	int t, i, j;

	scanf("%d %d", &basket_q, &range_n);

	for (i = 1; i <= basket_q; i++) // �ٱ��� �迭 ����
		basket[i] = i;

	for (i = 0; i < range_n; i++) { // �ٱ��� ��ȯ
		scanf("%d %d", &a, &b);

		for (j = a; j <= b; j++)
			basket2[j] = basket[b - j + a];

		for (j = a; j <= b; j++)
			basket[j] = basket2[j];
	}

	for (i = 1; i <= basket_q; i++) // ���
		printf("%d ", basket[i]);
}
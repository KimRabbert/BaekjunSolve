#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int basket_q; // �ٱ����� ���� [1,100]
	int basket[101]; // �ٱ��� �迭
	int change; // ��ȯ Ƚ�� [1,100]
	int ca, cb; // ��ȯ�� �ٱ��� a, b [1,basket_q]
	int t, i;
	
	scanf("%d %d", &basket_q, &change);

	for (i = 1; i <= basket_q; i++) // �ٱ��� �迭 ����
		basket[i] = i;

	for (i = 0; i < change; i++) { // �ٱ��� ��ȯ
		scanf("%d %d", &ca, &cb);

		t = basket[ca];
		basket[ca] = basket[cb];
		basket[cb] = t;
	}

	for (i = 1; i <= basket_q; i++) // ���
		printf("%d ", basket[i]);
}
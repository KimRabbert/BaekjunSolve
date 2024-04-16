#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int basket_q; // 바구니의 수량 [1,100]
	int basket[101]; // 바구니 배열
	int basket2[101];
	int range_n; // 교환 횟수 [1,100]
	int a, b; // 범위 시작과 끝 a, b [1,basket_q]
	int t, i, j;

	scanf("%d %d", &basket_q, &range_n);

	for (i = 1; i <= basket_q; i++) // 바구니 배열 설정
		basket[i] = i;

	for (i = 0; i < range_n; i++) { // 바구니 교환
		scanf("%d %d", &a, &b);

		for (j = a; j <= b; j++)
			basket2[j] = basket[b - j + a];

		for (j = a; j <= b; j++)
			basket[j] = basket2[j];
	}

	for (i = 1; i <= basket_q; i++) // 출력
		printf("%d ", basket[i]);
}
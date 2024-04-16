#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int basket_q; // 바구니의 수량 [1,100]
	int basket[101]; // 바구니 배열
	int change; // 교환 횟수 [1,100]
	int ca, cb; // 교환할 바구니 a, b [1,basket_q]
	int t, i;
	
	scanf("%d %d", &basket_q, &change);

	for (i = 1; i <= basket_q; i++) // 바구니 배열 설정
		basket[i] = i;

	for (i = 0; i < change; i++) { // 바구니 교환
		scanf("%d %d", &ca, &cb);

		t = basket[ca];
		basket[ca] = basket[cb];
		basket[cb] = t;
	}

	for (i = 1; i <= basket_q; i++) // 출력
		printf("%d ", basket[i]);
}
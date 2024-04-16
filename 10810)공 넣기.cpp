#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int basket_n; // 바구니의 수량 [1,100]
	int basket[101];
	int n; // 바구니에 공을 넣을 횟수 [1,100]
	int start, end; // 바구니의 범위 시작과 끝
	int ball; // 바구니에 들어갈 공의 번호
	int i, j;

	for (i = 1; i <= 100; i++) // 배열 초기화
		basket[i] = 0;
	
	scanf("%d %d", &basket_n, &n);

	for (i = 0; i < n; i++) {
		scanf("%d %d %d", &start, &end, &ball);
		for (j = start; j <= end; j++)
			basket[j] = ball;
	}

	for (i = 1; i <= basket_n; i++) // 바구니 출력
		printf("%d ", basket[i]);
}
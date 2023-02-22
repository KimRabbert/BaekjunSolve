#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void construct(bool*, int);

int main() {
	int i;

	bool selfnum[10001];

	for (i = 1; i <= 10000; i++)
		selfnum[i] = true;

	for (i = 1; i <= 10000; i++) {
		if (selfnum[i]) {
			construct(selfnum, i);
			printf("%d\n", i);
		}
	}
}

void construct(bool* arr, int n) {
	int sum = n;
	int t;
	for (int i = 0; i < 5; i++) {
		t = pow(10.0, double(i));
		sum += n % (t * 10) / t;
	}

	if (sum <= 10000) {
		arr[sum] = false;
		construct(arr, sum);
	}
}
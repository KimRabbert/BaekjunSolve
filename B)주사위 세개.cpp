#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a, b, c;
	int ov = 1;
	int mo;
	int award;
	scanf("%d %d %d", &a, &b, &c);

	if (a == b) {
		ov++;
		mo = a;
		if (b == c)
			ov++;
	}
	else if (b == c) {
		ov++;
		mo = b;
	}
	else if (a == c) {
		ov++;
		mo = a;
	}
	else {
		if (a >= b) {
			if (b >= c) {
				mo = a;
			}
			else {
				if (a >= c) {
					mo = a;
				}
				else
					mo = c;
			}
		}
		else {
			if (b >= c)
				mo = b;
			else
				mo = c;
		}
	}

	if (ov == 3)
		award = 10000 + mo * 1000;
	else if (ov == 2)
		award = 1000 + mo * 100;
	else
		award = mo * 100;

	printf("%d", award);
}
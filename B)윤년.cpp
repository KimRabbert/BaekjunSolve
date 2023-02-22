#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int year;
	bool ly = false;
	scanf("%d", &year);

	if (year % 4 == 0) {
		if (year % 100 == 0) {
			if (year % 400 == 0)
				ly = true;
		}
		else {
			ly = true;
		}
	}

	if (ly)
		printf("1");
	else
		printf("0");
}
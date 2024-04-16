#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	char num[16];
	int time = 0;

	scanf("%s", num);

	for (int i = 0; i < strlen(num); i++) {
		if (num[i] >= 'A' && num[i] <= 'C')
			time += 3;
		else if (num[i] >= 'D' && num[i] <= 'F')
			time += 4;
		else if (num[i] >= 'G' && num[i] <= 'I')
			time += 5;
		else if (num[i] >= 'J' && num[i] <= 'L')
			time += 6;
		else if (num[i] >= 'M' && num[i] <= 'O')
			time += 7;
		else if (num[i] >= 'P' && num[i] <= 'S')
			time += 8;
		else if (num[i] >= 'T' && num[i] <= 'V')
			time += 9;
		else
			time += 10;
	}

	printf("%d", time);
}
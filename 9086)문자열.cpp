#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	char word[1001];
	int n;
	int length;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%s", word);
		length = strlen(word);
		printf("%c%c\n", word[0], word[length - 1]);
	}
}
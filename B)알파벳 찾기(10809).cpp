#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int az[26];
	char word[101];
	int i;
	int w;

	for (i = 0; i < 26; i++)
		az[i] = -1;

	scanf("%s", &word);

	for (i = 0; word[i] != NULL; i++) {
		w = word[i] - 97;

		if (az[w] == -1)
			az[w] = i;
	}

	for (i = 0; i < 26; i++)
		printf("%d ", az[i]);
}
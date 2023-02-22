#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int alphabet[26] = { 0, };
	char s[1000001];
	int max = 0;
	int maxc;
	int maxcount = 0;

	scanf("%s", s);

	// 단어에서 알파벳 대소문자 상관없이 카운트
	for (int i = 0; s[i] != NULL; i++) {
		if (s[i] > 96)
			alphabet[s[i] - 97]++;
		else
			alphabet[s[i] - 65]++;
	}

	// 단어에서 가장 많이 나온 알파벳 찾기
	for (int i = 0; i < 26; i++) {
		if (alphabet[i] > max) {
			max = alphabet[i];
			maxc = i;
			maxcount = 1;
		}
		else if (alphabet[i] == max)
			maxcount++;
	}

	// 단어에서 가장 많이 나온 알파벳이 여러 개일 경우 '?' 출력
	if (maxcount > 1)
		printf("\?");
	else // 한 개일 경우 대문자로 출력
		printf("%c", maxc + 65);
}
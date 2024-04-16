#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	char line[101];

	while (true) {
		fgets(line, sizeof(line), stdin);
		if (feof(stdin))
			break;

		printf("%s", line);
	}
}
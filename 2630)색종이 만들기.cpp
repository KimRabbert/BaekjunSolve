#include <iostream>
#include <vector>
using namespace std;

vector<vector<bool>> paper;
int white = 0, blue = 0;

void set_paper(int n) {
	int i, j;
	bool k;
	
	vector<bool> v(n, false);
	for (i = 0; i < n; i++)
		paper.push_back(v);

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cin >> k;

			if (k)
				paper[i][j] = true;
		}
	}
}

void check_paper(int x, int y, int n) {
	int i, j;
	bool flag = false;
	bool color = paper[y][x];

	for (i = y; i < y + n; i++) {
		for (j = x; j < x + n; j++) {
			if (color != paper[i][j]) {
				flag = true;
				break;
			}
		}

		if (flag)
			break;
	}

	if (flag) {
		check_paper(x, y, n / 2);
		check_paper(x + n / 2, y, n / 2);
		check_paper(x, y + n / 2, n / 2);
		check_paper(x + n / 2, y + n / 2, n / 2);
	}
	else {
		if (color)
			blue++;
		else
			white++;
	}
}

int main() {
	int n;

	cin >> n;

	set_paper(n);

	check_paper(0, 0, n);

	cout << white << "\n" << blue;
}
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int w, h;
int tomato = 0;
vector<vector<int>> warehouse;
queue<pair<int, int>> q;

void input() {
	cin >> w >> h;

	int i, j, k;
	vector<int> v(w, 0);
	for (i = 0; i < h; i++)
		warehouse.push_back(v);

	for (i = 0; i < h; i++) {
		for (j = 0; j < w; j++) {
			cin >> k;

			warehouse[i][j] = k;

			if (k == 0)
				tomato++;

			if (k == 1)
				q.push({ i, j });
		}
	}
}

int days() {
	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, 1, 0, -1 };
	int size, i, j;
	int x, y, tx, ty;
	int cnt = 0;
	
	while (!q.empty() && tomato) {
		size = q.size();
		cnt++;

		for (i = 0; i < size; i++) {
			x = q.front().second;
			y = q.front().first;
			q.pop();

			for (j = 0; j < 4; j++) {
				tx = x + dx[j];
				ty = y + dy[j];

				if (tx >= 0 && tx < w && ty >= 0 && ty < h && warehouse[ty][tx] == 0) {
					warehouse[ty][tx] = 1;
					q.push({ ty, tx });
					tomato--;
				}
			}
		}
	}

	if (tomato == 0)
		return cnt;
	else
		return -1;
}

int main() {
	input();

	cout << days();
}
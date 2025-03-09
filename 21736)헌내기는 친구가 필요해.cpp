#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Campus {
	vector<vector<char>> campus;
	int width, height;
	int people;
	bool inRange(int, int);
	int startLoc[2];

public:
	Campus(int w, int h) {
		vector<char> v(w, 0);
		campus.assign(h, v);

		width = w;
		height = h;
		people = 0;
		startLoc[0] = -1;
		startLoc[1] = -1;
	}
	void campusInput();
	int getPeople();
};

void Campus::campusInput() {
	int i, j;

	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			cin >> campus[i][j];

			if (campus[i][j] == 'I') {
				startLoc[0] = i;
				startLoc[1] = j;
			}
		}
	}
}

bool Campus::inRange(int y, int x) {
	return y >= 0 && y < height && x >= 0 && x < width;
}

int Campus::getPeople() {
	queue<vector<int>> q;
	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, 1, 0, -1 };
	int tx, ty, x, y, i;

	q.push({ startLoc[0], startLoc[1] });
	campus[startLoc[0]][startLoc[1]] = 'X';

	while (!q.empty()) {	//BFS
		y = q.front()[0];
		x = q.front()[1];
		q.pop();

		for (i = 0; i < 4; i++) {
			ty = y + dy[i];
			tx = x + dx[i];

			if (inRange(ty, tx) && campus[ty][tx] != 'X') {
				if (campus[ty][tx] == 'P')
					people++;

				campus[ty][tx] = 'X';
				q.push({ ty, tx });
			}
		}
	}

	return people;
}

int main() {
	int width, height;
	int p;
	
	cin >> height >> width;

	Campus campus(width, height);

	campus.campusInput();
	p = campus.getPeople();

	if (p == 0) {
		cout << "TT";
	}
	else {
		cout << p;
	}
}
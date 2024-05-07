#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Map {
	vector<vector<int>> map;
	vector<vector<int>> distance;
	int height, width;
	pair<int, int> start = { -1, -1 };
public:
	Map(int y, int x) {
		height = y;
		width = x;
		vector<int> v(x, -1);
		map.assign(y, v);
		distance.assign(y, v);
	}
	void input();
	void bfs();
	void print();
};

void Map::input() {
	int i, j;

	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			cin >> map[i][j];

			if (map[i][j] == 2) {
				start.first = i;
				start.second = j;
			}
			else if (map[i][j] == 0) {
				distance[i][j] = 0;
			}
		}
	}
}

void Map::bfs() {
	queue<pair<int, int>> q;
	int cnt = 0;
	int x, y;
	int tx, ty;
	int len, i, j;
	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, 1, 0, -1 };

	q.push(start);
	distance[start.first][start.second] = 0;

	while (!q.empty()) {
		len = q.size();
		cnt++;

		for (i = 0; i < len; i++) {
			y = q.front().first;
			x = q.front().second;
			q.pop();

			for (j = 0; j < 4; j++) {
				ty = y + dy[j];
				tx = x + dx[j];

				if (ty >= 0 && ty < height && tx >= 0 && tx < width) {
					if (map[ty][tx] != 0 && distance[ty][tx] == -1) {
						distance[ty][tx] = cnt;
						q.push({ ty, tx });
					}
				}
			}
		}
	}
}

void Map::print() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++)
			cout << distance[i][j] << ' ';
		cout << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int x, y;

	cin >> y >> x;

	Map m(y, x);

	m.input();
	m.bfs();
	m.print();
}
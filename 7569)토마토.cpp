#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Tomato {
	int width, depth, height;
	int unripeTomatoes;
	vector<vector<vector<int>>> box;
	queue<vector<int>> bfsQueue;
	bool inRange(int, int, int);
public:
	Tomato(int x, int y, int h) {
		width = x;
		depth = y;
		height = h;

		vector<int> v(x, 0);
		vector<vector<int>> v2(y, v);
		box.assign(h, v2);

		unripeTomatoes = 0;
	}
	void inputInfo();
	int getPeriod();
};

void Tomato::inputInfo() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int i, j, k;

	for (i = 0; i < height; i++) {
		for (j = 0; j < depth; j++) {
			for (k = 0; k < width; k++) {
				cin >> box[i][j][k];

				if (box[i][j][k] == 0) {
					unripeTomatoes++;
				}
				else if (box[i][j][k] == 1) {
					bfsQueue.push({ i, j, k });
				}
			}
		}
	}
}

bool Tomato::inRange(int z, int y, int x) {
	return (x >= 0 && x < width && y >= 0 && y < depth && z >= 0 && z < height);
}

int Tomato::getPeriod() {
	if (unripeTomatoes == 0)
		return 0;

	int dx[6] = { 1, 0, -1, 0, 0, 0 };
	int dy[6] = { 0, 1, 0, -1, 0, 0 };
	int dz[6] = { 0, 0, 0, 0, 1, -1 };
	int tx, ty, tz;
	int x, y, z;
	int period = 0;
	int i, j;
	int queueSize = bfsQueue.size();

	while (queueSize > 0) {
		for (i = 0; i < queueSize; i++) {
			z = bfsQueue.front()[0];
			y = bfsQueue.front()[1];
			x = bfsQueue.front()[2];
			bfsQueue.pop();

			for (j = 0; j < 6; j++) {
				tx = x + dx[j];
				ty = y + dy[j];
				tz = z + dz[j];

				if (inRange(tz, ty, tx) && box[tz][ty][tx] == 0) {
					box[tz][ty][tx] = 1;
					bfsQueue.push({ tz, ty, tx });

					unripeTomatoes--;
				}
			}
		}

		period++;
		queueSize = bfsQueue.size();
	}

	if (unripeTomatoes > 0)
		return -1;

	return period - 1;
}

int main() {
	int w, d, h;

	cin >> w >> d >> h;

	Tomato t(w, d, h);
	
	t.inputInfo();

	cout << t.getPeriod();
}
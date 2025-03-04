#include <iostream>
#include <vector>
using namespace std;

int euclideanAlgotihm(int x, int y) {
	int mod;

	if (x < y) {
		int tmp = x;
		x = y;
		y = tmp;
	}

	mod = x % y;
	while (mod != 0) {
		x = y;
		y = mod;
		mod = x % y;
	}

	return y;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int M, N, x, y;
	int answer, j, k;
	int testCase;
	int lastYear;
	int xSize, ySize;
	vector<int> xMultiple;
	vector<int> yMultiple;

	cin >> testCase;

	for (int i = 0; i < testCase; i++) {
		cin >> M >> N >> x >> y;

		lastYear = M * N / euclideanAlgotihm(M, N);
		xSize = lastYear / M;
		ySize = lastYear / N;

		for (j = 0; j < xSize; j++)
			xMultiple.push_back(x + j * M);

		for (j = 0; j < ySize; j++)
			yMultiple.push_back(y + j * N);

		j = 0;
		k = 0;
		answer = -1;
		while (j < xSize && k < ySize) {
			if (xMultiple[j] == yMultiple[k]) {
				answer = xMultiple[j];
				break;
			}
			else if (xMultiple[j] > yMultiple[k]) {
				k++;
			}
			else {
				j++;
			}
		}

		cout << answer << '\n';

		xMultiple.clear();
		yMultiple.clear();
	}
	
}
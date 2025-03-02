#include <iostream>
#include <vector>
using namespace std;

class KevinBacon {
	vector<vector<int>> graph;
	int users;
public:
	KevinBacon(int n) {
		users = n;
		
		vector<int> v(n + 1, -1);
		graph.assign(n + 1, v);

		for (int i = 1; i < n + 1; i++)
			graph[i][i] = 0;
	}
	void connect(int, int);
	int calKev();
};

void KevinBacon::connect(int a, int b) {
	graph[a][b] = 1;
	graph[b][a] = 1;
}

int KevinBacon::calKev() {
	int num;
	int min = 10000;
	int minNum = -1;

	for (int k = 1; k <= users; k++) {
		for (int i = 1; i <= users - 1; i++) {
			for (int j = i + 1; j <= users; j++) {
				if (graph[i][k] == -1 || graph[k][j] == -1)
					continue;

				num = graph[i][k] + graph[k][j];
				if (graph[i][j] > num || graph[i][j] == -1) {
					graph[i][j] = num;
					graph[j][i] = num;
				}
			}
		}
	}

	for (int i = 1; i <= users; i++) {
		num = 0;

		for (int j = 1; j <= users; j++)
			num += graph[i][j];

		if (num < min) {
			min = num;
			minNum = i;
		}
	}

	return minNum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int users, relationships;
	int a, b;

	cin >> users >> relationships;

	KevinBacon kb(users);

	for (int i = 0; i < relationships; i++) {
		cin >> a >> b;
		kb.connect(a, b);
	}

	cout << kb.calKev();
}
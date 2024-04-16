#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<bool>> network;

void net_setting() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int com, net;
	int a, b;

	cin >> com;

	vector<bool> v(com + 1, false);
	for (int i = 0; i <= com; i++)
		network.push_back(v);

	cin >> net;

	for (int i = 0; i < net; i++) {
		cin >> a >> b;
		network[a][b] = true;
		network[b][a] = true;
	}
}

int worm() {
	int size = network.size();

	vector<bool> com(size, false);
	com[1] = true;

	queue<int> q;
	q.push(1);

	int cnt = 0, tmp, i;

	while (!q.empty()) {
		tmp = q.front();
		q.pop();

		for (i = 1; i < size; i++) {
			if (network[tmp][i] && !com[i]) {
				q.push(i);
				com[i] = true;
				cnt++;
			}
		}
	}

	return cnt;
}

int main() {
	net_setting();

	cout << worm();
}
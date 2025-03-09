#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	int n;
	int size, length;

	cin >> size >> length;

	for (int i = 1; i <= size; i++) {
		cin >> n;

		pq.push({ n, i });

		while (pq.top().second < i - length + 1)
			pq.pop();

		cout << pq.top().first << ' ';
	}
}
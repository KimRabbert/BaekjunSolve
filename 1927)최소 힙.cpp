// ÃÖ¼Ò Èü 1927
#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	unsigned int n, x;
	priority_queue<unsigned int, vector<unsigned int>, greater<unsigned int>> pq;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x;
		
		if (x == 0) {
			if (pq.empty()) {
				cout << 0 << "\n";
			}
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else {
			pq.push(x);
		}
	}
}
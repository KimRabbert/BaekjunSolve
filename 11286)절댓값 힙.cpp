#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 우선순위 큐 비교 연산자 오버로딩 (우선순위 : 절댓값 작은 순서 + 값 작은 순서)
struct cmp {
	bool operator()(int a, int b) {
		if (abs(a) == abs(b))
			return a > b;
		return abs(a) > abs(b);
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	priority_queue<int, vector<int>, cmp> pq;
	int n, operation;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> operation;

		if (operation == 0) {
			if (pq.empty()) {
				cout << "0\n";
			}
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else {
			pq.push(operation);
		}
	}
}
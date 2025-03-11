#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int testCase, calculation, num;
	int i, j;
	char command;

	cin >> testCase;

	for (i = 0; i < testCase; i++) {
		priority_queue<pair<int, int>> dualPQMax;	//max heap
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> dualPQMin;	//min heap
		vector<bool> isRemoved;		//다른 우선순위 큐와 동기화하기 위해 선언

		cin >> calculation;

		isRemoved.assign(calculation, true);

		for (j = 0; j < calculation; j++) {
			cin >> command >> num;

			if (command == 'I') {
				dualPQMax.push({ num, j });	//숫자마다 id 지정
				dualPQMin.push({ num, j });

				isRemoved[j] = false;
			}
			else if (command == 'D'){
				if (num == 1) {
					while (!dualPQMax.empty() && isRemoved[dualPQMax.top().second]) dualPQMax.pop();	//top에 있는 노드가 이미 지워진 노드일 경우 pop
					if (!dualPQMax.empty()) {
						isRemoved[dualPQMax.top().second] = true;
						dualPQMax.pop();
					}
				}
				else {
					while (!dualPQMin.empty() && isRemoved[dualPQMin.top().second]) dualPQMin.pop();
					if (!dualPQMin.empty()) {
						isRemoved[dualPQMin.top().second] = true;
						dualPQMin.pop();
					}
				}
			}
		}

		while (!dualPQMax.empty() && isRemoved[dualPQMax.top().second]) dualPQMax.pop();
		while (!dualPQMin.empty() && isRemoved[dualPQMin.top().second]) dualPQMin.pop();

		if (dualPQMax.empty()) {
			cout << "EMPTY\n";
		}
		else {
			cout << dualPQMax.top().first << ' ' << dualPQMin.top().first << '\n';
		}
	}
}
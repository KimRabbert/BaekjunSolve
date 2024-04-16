#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int minMove(int start, int dest) {
	queue<int> q;
	vector<bool> v(100001, false);
	int tmp, i, size;
	int cnt = 0;
	int over = 200000;

	q.push(start);
	v[start] = true;

	while (1) {
		size = q.size();
		cnt++;

		for (i = 0; i < size; i++) {
			tmp = q.front();
			q.pop();
			
			if (tmp < dest) {
				if (tmp - 1 >= 0 && !v[tmp - 1]) {
					if (tmp - 1 == dest) {
						if (over > cnt)
							return cnt;
						return over;
					}

					v[tmp - 1] = true;
					q.push(tmp - 1);
				}

				if (!v[tmp + 1]) {
					if (tmp + 1 == dest) {
						if (over > cnt)
							return cnt;
						return over;
					}

					v[tmp + 1] = true;
					q.push(tmp + 1);
				}

				if (tmp * 2 <= dest && !v[tmp * 2]) {
					if (tmp * 2 == dest) {
						if (over > cnt)
							return cnt;
						return over;
					}

					v[tmp * 2] = true;
					q.push(tmp * 2);
				}
				else if (tmp * 2 > dest) {
					if (over > tmp * 2 - dest + cnt)
						over = tmp * 2 - dest + cnt;
				}
			}
			else if (tmp > dest) {
				return tmp - dest;
			}
			else {
				return 0;
			}
		}
	}
}

int main() {
	int n, k;

	cin >> n >> k;

	cout << minMove(n, k);
}
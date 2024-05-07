#include <iostream>
#include <vector>
using namespace std;

vector<int> v = { 1, 2, 4 };

int mathod(int n) {
	if (n <= 0)
		return 0;

	if (n <= v.size())
		return v[n - 1];

	int sum = 0;

	sum += mathod(n - 1) + mathod(n - 2) + mathod(n - 3);
	v.push_back(sum);
	
	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T, n;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> n;
		cout << mathod(n) << "\n";
	}
}
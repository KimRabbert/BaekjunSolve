#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	vector<int> v;
	vector<int> x;
	int n;

	cin >> n;
	x.assign(n, 0);
	v.assign(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> x[i];
		v[i] = x[i];
	}

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for (int i = 0; i < n; i++)
		cout << lower_bound(v.begin(), v.end(), x[i]) - v.begin() << ' ';
}
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> treeH;

long long int height(int n) {
	int i = treeH.size() - 1;
	long long int sum = 0;

	while (treeH[i] > n)
		sum += treeH[i--] - n;

	return sum;
}

int search(int low, int high, int n) {
	int mid;
	long long int h;
	int max;

	while (low <= high) {
		mid = (low + high) / 2;

		h = height(mid);

		if (h < n) {
			high = mid - 1;
		}
		else {
			max = mid;
			low = mid + 1;
		}
	}

	return max;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int tree, len;

	cin >> tree >> len;

	treeH.assign(tree, 0);

	for (int i = 0; i < tree; i++)
		cin >> treeH[i];

	sort(treeH.begin(), treeH.end());
	
	cout << search(0, treeH[treeH.size() - 1], len);
}
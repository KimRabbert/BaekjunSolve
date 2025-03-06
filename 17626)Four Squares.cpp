#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main() {
	vector<int> dp;
	vector<int> sqrNum;
	int n;
	int size = 0;
	int cnt = 0;
	int i, j;

	cin >> n;

	sqrNum.push_back(0);
	while (++size * size <= n)
		sqrNum.push_back(size * size);

	dp.assign(n + 1, 4);

	dp[0] = 0;
	dp[1] = 1;

	cnt = 1;
	for (i = 2; i <= n; i++) {
		if (sqrt(i) == (int)sqrt(i)) {
			dp[i] = 1;
			cnt++;
			continue;
		}

		for (j = cnt; j > 0; j--)
			if (dp[i - sqrNum[j]] + 1 < dp[i])
				dp[i] = dp[i - sqrNum[j]] + 1;
	}

	cout << dp[n];
}
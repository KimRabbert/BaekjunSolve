#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> dp;
vector<int> score;

int maxScore(int n) {
	vector<int> v(3, 0);
	dp.assign(n + 1, v);

	for (int i = 1; i <= n; i++) {
		dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = dp[i - 1][0] + score[i];
		dp[i][2] = dp[i - 1][1] + score[i];
	}

	return max(dp[n][1], dp[n][2]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	
	cin >> n;

	score.assign(n + 1, 0);

	for (int i = 1; i <= n; i++)
		cin >> score[i];

	cout << maxScore(n);
}
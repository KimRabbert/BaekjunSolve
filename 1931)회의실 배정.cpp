#include <iostream>
#include <vector>
//#include <unordered_map>
//#include <algorithm>
using namespace std;

vector<pair<unsigned int, unsigned int>> schedule;

/*
bool compare(pair<unsigned int, unsigned int> a, pair<unsigned int, unsigned int> b) {
	return a.first < b.first;
}

void time_set() {
	int n;
	unsigned int a, b;
	
	cin >> n;

	unordered_map<unsigned int, unsigned int> h;

	for (int i = 0; i < n; i++) {
		cin >> a >> b;

		if (h.find(a) == h.end()) {
			h.insert({ a, schedule.size() });
			schedule.push_back({ a, b });
		}
		else {
			if (schedule[h[a]].second > b)
				schedule[h[a]].second = b;
		}
	}

	sort(schedule.begin(), schedule.end(), compare);
}

int max_cnt(unsigned int n, int i) {
	if (i >= schedule.size())
		return 0;

	int max = 0;
	int tmp = 0;

	if (n <= schedule[i].first)
		tmp = max_cnt(schedule[i].second, i + 1) + 1;
	if (max < tmp)
		max = tmp;

	tmp = max_cnt(n, i + 1);

	if (max < tmp)
		max = tmp;

	return max;
}
*/

void time_set() {
	int n;
	unsigned int a, b;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		schedule.push_back({ a, b });
	}
}

int max_cnt(int n, int i) {
	if (i >= schedule.size())
		return 0;

	int max = 0;
	int tmp = 0;

	if (n == -1 || schedule[n].second <= schedule[i].first || schedule[n].first >= schedule[i].second)
		tmp = max_cnt(i, i + 1) + 1;
	if (max < tmp)
		max = tmp;

	tmp = max_cnt(n, i + 1);

	if (max < tmp)
		max = tmp;

	return max;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	time_set();

	cout << max_cnt(-1, 0);
}
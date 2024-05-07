#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<unsigned int, unsigned int>> schedule;

bool compare(pair<unsigned int, unsigned int> a, pair<unsigned int, unsigned int> b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

void time_set() {
	int n;
	unsigned int a, b;
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a >> b;

		schedule.push_back({ a, b });
	}

	sort(schedule.begin(), schedule.end(), compare);
}

int max_cnt() {
	int max = 0;
	int end = 0;
	int size = schedule.size();

	for (int i = 0; i < size; i++) {
		if (schedule[i].first >= end) {
			max++;
			end = schedule[i].second;
		}
	}

	return max;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	time_set();

	cout << max_cnt();
}
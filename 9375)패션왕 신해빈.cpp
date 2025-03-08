#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int tc, n;
	string clothesName, clothesType;
	vector<int> cnt;
	unordered_map<string, int> type;
	int result;

	cin >> tc;

	for (int i = 0; i < tc; i++) {
		type.clear();
		cnt.clear();
		result = 1;

		cin >> n;

		for (int j = 0; j < n; j++) {
			cin >> clothesName >> clothesType;

			if (type.find(clothesType) == type.end()) {
				type.insert({ clothesType, type.size() });
				cnt.push_back(1);
			}
			else {
				cnt[type[clothesType]] += 1;
			}
		}

		if (cnt.size() == 1) {
			result = cnt[0];
		}
		else {
			for (int j = 0; j < cnt.size(); j++)
				result *= cnt[j] + 1;
			result--;
		}

		cout << result << '\n';
	}
}
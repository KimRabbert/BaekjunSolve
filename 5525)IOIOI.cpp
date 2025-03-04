#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, strLen;
	string str;
	vector<int> pnVector;
	int cnt = 0;
	int answer = 0;
	int i;

	cin >> n;
	cin >> strLen;
	cin >> str;

	for (i = 0; i < strLen; i++) {
		if (str[i] == 'I') {
			while (i + 1 < strLen && str[i] != str[i + 1]) {
				cnt++;
				i++;
			}

			if (str[i] == 'I')
				cnt++;

			pnVector.push_back((cnt - 1) / 2);
			cnt = 0;
		}
	}

	for (i = 0; i < pnVector.size(); i++) {
		if (pnVector[i] >= n) {
			answer += pnVector[i] - n + 1;
		}
	}

	cout << answer;
}
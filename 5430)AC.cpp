#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int testCase;
	int arrSize;
	int arrBegin = 0;
	int arrEnd;
	int i, j, k;
	string function;
	string arrString;
	vector<int> arr;
	bool errflag = false;
	bool isReversed = false;

	cin >> testCase;

	for (i = 0; i < testCase; i++) {
		cin >> function;
		cin >> arrSize;
		cin >> arrString;

		arrEnd = arrSize - 1;

		for (j = 1; j < arrString.length(); j++) {
			if (arrString[j] >= '0' && arrString[j] <= '9') {
				k = j;
				while (arrString[k] >= '0' && arrString[k] <= '9')
					k++;
				arr.push_back(stoi(arrString.substr(j, k - j)));

				j = k - 1;
			}
		}

		for (j = 0; j < function.length(); j++) {
			if (function[j] == 'R') {
				isReversed = !isReversed;
			}
			else {
				if (arrSize == 0) {
					errflag = true;
					break;
				}

				if (isReversed) {
					arrEnd--;
				}
				else {
					arrBegin++;
				}
				arrSize--;
			}
		}

		if (errflag) {
			cout << "error\n";
		}
		else {
			cout << '[';

			if (isReversed) {
				for (j = arrEnd; j >= arrBegin; j--) {
					cout << arr[j];
					if (j != arrBegin)
						cout << ',';
				}
			}
			else {
				for (j = arrBegin; j <= arrEnd; j++) {
					cout << arr[j];
					if (j != arrEnd)
						cout << ',';
				}
			}
			
			cout << "]\n";
		}
		
		isReversed = false;
		errflag = false;
		arrBegin = 0;
		arr.clear();
	}
}
#include <iostream>
using namespace std;

int main() {
	int B;
	string N;
	int dec = 0;
	int t = 1;

	cin >> N >> B;

	int len = N.length();

	for (int i = len - 1; i >= 0; i--) {
		if (N[i] >= '0' && N[i] <= '9') {
			dec += (N[i] - '0') * t;
		}
		else if (N[i] >= 'A' && N[i] <= 'Z') {
			dec += (N[i] - 'A' + 10) * t;
		}

		t *= B;
	}

	cout << dec;
}
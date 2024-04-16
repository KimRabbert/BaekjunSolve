#include <iostream>
using namespace std;

int main() {
	int B, N;
	string s = "";
	int tmp;
	cin >> N >> B;

	while (N > 0) {
		tmp = N % B;
		if (tmp >= 0 && tmp <= 9) {
			s = char('0' + tmp) + s;
		}
		else if (tmp >= 10 && tmp <= 35) {
			s = char('A' + tmp - 10) + s;
		}
		N /= B;
	}

	cout << s;
}
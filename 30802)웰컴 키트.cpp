#include <iostream>
using namespace std;

int main() {
	int n;
	int s[6];
	int t, p;

	cin >> n;
	for (int i = 0; i < 6; i++)
		cin >> s[i];
	cin >> t >> p;

	int sum = 0;
	for (int i = 0; i < 6; i++)
		sum += s[i] / t + bool(s[i] % t);

	cout << sum << "\n";
	cout << n / p << ' ' << n % p;
}
#include <iostream>
#include <string>
using namespace std;

int main() {
	string a, b, c;
	int num;
	string result = "";

	cin >> a;
	cin >> b;
	cin >> c;

	if (a[0] >= '0' && a[0] <= '9') {
		num = stoi(a) + 3;
	}
	else if (b[0] >= '0' && b[0] <= '9') {
		num = stoi(b) + 2;
	}
	else if (c[0] >= '0' && c[0] <= '9') {
		num = stoi(c) + 1;
	}

	if (num % 3 == 0)
		result = "Fizz";
	if (num % 5 == 0)
		result += "Buzz";
	if (result.length() == 0)
		result = to_string(num);

	cout << result;
}
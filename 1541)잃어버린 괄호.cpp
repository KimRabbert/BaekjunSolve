#include <iostream>
#include <string>
using namespace std;

int main() {
	string expression;
	string numStr;
	int num;
	int sum = 0;
	bool flag = true;
	int i, j;

	cin >> expression;

	for (i = 0; i < expression.length(); i++) {
		if (expression[i] == '-') {
			flag = false;
		}
		else if (expression[i] >= '0' && expression[i] <= '9') {
			j = i;
			while (expression[j] >= '0' && expression[j] <= '9')
				j++;

			num = stoi(expression.substr(i, j - i));

			sum += num * (int(flag) * 2 - 1);

			i = j - 1;
		}
	}

	cout << sum;
}
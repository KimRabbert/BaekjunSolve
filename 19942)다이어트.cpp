#include <iostream>
#include <vector>
using namespace std;

class Diet {
	vector<vector<int>> ingredients;
	vector<int> minNum;
	vector<int> currentNum;
	int current[5] = { 0, 0, 0, 0, 0 };
	int target[4] = { 0, 0, 0, 0 };
	int minPrice;
	int size;
public:
	Diet() {
		minPrice = 10000;
		size = 0;
	}
	void inputIngredients();
	void dp(int);
	void print();
};

void Diet::inputIngredients() {
	int n;

	cin >> n;
	cin >> target[0] >> target[1] >> target[2] >> target[3];

	size = n;
	vector<int> v(5, 0);
	ingredients.assign(n, v);

	for (int i = 0; i < n; i++) {
		cin >> ingredients[i][0] >> ingredients[i][1] >> ingredients[i][2] >> ingredients[i][3] >> ingredients[i][4];
	}
}

void Diet::dp(int n) {
	int i;

	currentNum.push_back(n);
	
	for (i = 0; i < 5; i++)
		current[i] += ingredients[n][i];

	if (current[0] >= target[0] && current[1] >= target[1] && current[2] >= target[2] && current[3] >= target[3]) {
		if (minPrice > current[4]) {
			minPrice = current[4];
			minNum = currentNum;
		}

		for (i = 0; i < 5; i++)
			current[i] -= ingredients[n][i];
		currentNum.pop_back();

		return;
	}

	for (i = n + 1; i < size; i++)
		dp(i);

	for (i = 0; i < 5; i++)
		current[i] -= ingredients[n][i];
	currentNum.pop_back();

	for (i = n + 1; i < size; i++)
		dp(i);
}

void Diet::print() {
	if (minPrice == 10000) {
		cout << -1;
		return;
	}

	cout << minPrice << '\n';
	
	for (int i : minNum)
		cout << i + 1 << ' ';
}

int main() {
	Diet diet;

	diet.inputIngredients();
	diet.dp(0);
	diet.print();
}
#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int n, tmp;
	double avg;
	long sum = 0;
	int range;
	int	num[8001];
	int max = -4001, min = 4001;
	int mode = 0, mode2 = -4001, moden = 0;
	int i;
	int mid, midn = 0;

	for (i = 0; i <= 8000; i++)
		num[i] = 0;

	cin >> n;

	for (i = 0; i < n; i++) {
		cin >> tmp;
		num[tmp + 4000]++;
		sum += tmp;
		if (tmp > max)
			max = tmp;
		if (tmp < min)
			min = tmp;
	}

	range = max - min;
	avg = round((double)sum / n);
	mid = n / 2 + 1;
	if (avg == (int)-0)
		avg = 0;

	for (i = min; i <= max; i++) {
		mid -= num[i + 4000];
		if (mid <= 0) {
			midn = i;
			break;
		}
	}

	for (i = min; i <= max; i++) {
		if (num[i + 4000] > moden) {
			mode = i;
			mode2 = -4001;
			moden = num[i + 4000];
		}
		else if (num[i + 4000] == moden && mode2 == -4001) {
			mode2 = i;
		}
	}

	if (mode2 == -4001)
		mode2 = mode;

	cout << (int)avg << endl;
	cout << midn << endl;
	cout << mode2 << endl;
	cout << range;
}
/*
N개의 과일
과일 번호 : 1 ~ 9
과일 종류 <= 2
최대 과일 개수 구하기

배열을 선형 탐색하며 지속적으로 과일의 종류가 2개 이하가 되도록 유지 및 최대값 갱신
*/

#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int numberOfFruit;
	int fruitCnt[11] = { 0, };	//현재 사용된 과일의 종류(1~9)와 개수
	int sortCnt = 0;	//과일의 종류
	int begin = 0, end = 0;
	int max = 0;

	cin >> numberOfFruit;

	int fruitArr[200000];

	for (int i = 0; i < numberOfFruit; i++) {
		cin >> fruitArr[i];
		end++;
		
		if (fruitCnt[fruitArr[i]] == 0) {
			sortCnt++;

			while (sortCnt > 2) {
				fruitCnt[fruitArr[begin]]--;
				if (fruitCnt[fruitArr[begin]] == 0)
					sortCnt--;
				begin++;
			}
		}

		fruitCnt[fruitArr[i]]++;

		if (max < end - begin)
			max = end - begin;
	}

	cout << max;
}
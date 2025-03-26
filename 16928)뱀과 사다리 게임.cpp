#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Game {
	pair<bool, int> snakeLadder[101];
	int minDice[101];
public:
	Game() {
		for (int i = 0; i < 101; i++) {
			snakeLadder[i] = { false, 0 };
			minDice[i] = -1;
		}
		minDice[1] = 0;
	}
	void getSnakeLadder();
	int minEnd();
};

void Game::getSnakeLadder() {
	int ladder, snake;
	int start, end;

	cin >> ladder >> snake;

	for (int i = 0; i < ladder + snake; i++) {
		cin >> start >> end;
		snakeLadder[start] = { true, end };
	}
}

int Game::minEnd() {
	queue<int> q;
	int count = 0, curLoc;
	int i;

	q.push(1);

	while (minDice[100] == -1) {
		curLoc = q.front();
		q.pop();
		
		count = minDice[curLoc];

		for (i = 1; i <= 6; i++) {
			if (curLoc + i <= 100 && minDice[curLoc + i] == -1) {
				minDice[curLoc + i] = count + 1;
				if (snakeLadder[curLoc + i].first) {
					if (minDice[snakeLadder[curLoc + i].second] == -1) {
						minDice[snakeLadder[curLoc + i].second] = count + 1;
						q.push(snakeLadder[curLoc + i].second);
					}
				}
				else {
					q.push(curLoc + i);
				}
			}
		}
	}

	return minDice[100];
}

int main() {
	Game game;

	game.getSnakeLadder();

	cout << game.minEnd();
}
/*
입력 : 정점의 개수 N (1 <= N <= 100), 가중치 없는 그래프의 인접 행렬
출력 : 정점 사이의 경로 존재 유무를 1, 0으로 인접 행렬 형식으로 출력

플로이드 워셜 알고리즘

*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<vector<int>> graph;
	int size;
	int i, j, k;

	cin >> size;

	{
		vector<int> v(size, 0);
		graph.assign(size, v);
	}

	for (i = 0; i < size; i++)
		for (j = 0; j < size; j++)
			cin >> graph[i][j];

	for (k = 0; k < size; k++) {
		for (i = 0; i < size; i++) {
			for (j = 0; j < size; j++) {
				if (graph[i][k] && graph[k][j])
					graph[i][j] = 1;
			}
		}
	}

	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++)
			cout << graph[i][j] << ' ';
		cout << '\n';
	}
}
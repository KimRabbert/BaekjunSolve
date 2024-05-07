#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

class Graph {
	vector<list<int>> graph;
	int vertex;
public:
	Graph(int n) {
		this->vertex = n;
		list<int> l;
		for (int i = 0; i <= n; i++)
			this->graph.push_back(l);
	}
	void input(int);
	int ConnectedComponent();
};

void Graph::input(int n) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int a, b;

	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		this->graph[a].push_back(b);
		this->graph[b].push_back(a);
	}
}

int Graph::ConnectedComponent() {
	int tmp;
	int n = this->vertex;
	int cnt = 0;
	vector<bool> v(n + 1, false);
	queue<int> q;
	list<int>::iterator it;

	for (int i = 1; i <= n; i++) {
		if (v[i])
			continue;

		cnt++;
		v[i] = true;

		q.push(i);				// BFS
		while (!q.empty()) {  
			tmp = q.front();
			q.pop();

			for (it = this->graph[tmp].begin(); it != this->graph[tmp].end(); it++) {
				if (!v[*it]) {
					v[*it] = true;
					q.push(*it);
				}
			}
		}
	}

	return cnt;
}

int main() {
	int n, m;

	cin >> n >> m;
	Graph g(n);

	g.input(m);

	cout << g.ConnectedComponent();
}
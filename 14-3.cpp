#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
public:
	int size;
	vector<int>* v;
	bool* visit;

	Graph(int size) {
		this->size = size;
		v = new vector<int>[size + 1];
		visit = new bool[size + 1];
		for (int i = 0; i < size + 1; i++) {
			visit[i] = false;
		}
	}

	void insertEdge(int vertex1, int vertex2) {
		v[vertex1].push_back(vertex2);
		v[vertex2].push_back(vertex1);
	}

	void bfs(int cur) {
		queue<int>q;
		q.push(cur);
		visit[cur] = true;
		while (!q.empty()) {
			int temp = q.front();
			cout << temp << " ";
			q.pop();
			for (int i = 0; i < v[temp].size(); i++) {
				if (!visit[v[temp][i]]) {
					q.push(v[temp][i]);
					visit[v[temp][i]] = true;
				}
			}
		}
	}
};

int main() {
	int t, n, m, v1, v2;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		Graph g(n);
		for (int i = 0; i < m; i++) {
			cin >> v1 >> v2;
			g.insertEdge(v1, v2);
		}
		g.bfs(1);
		cout << endl;
	}
}
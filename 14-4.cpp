#include <iostream>
#include <vector>
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

	int dfs(int cur) {
		int size = 0;
		visit[cur] = true;
		size++;
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];
			if (!visit[next]) {
				size += dfs(next);
			}
		}
		return size;
	}

	void reset() {
		for (int i = 0; i < size + 1; i++) {
			visit[i] = false;
		}
	}
};

int main() {
	int t, n, m, a, v1, v2;
	cin >> t;
	while (t--) {
		cin >> n >> m >> a;
		Graph g(n);
		for (int i = 0; i < m; i++) {
			cin >> v1 >> v2;
			g.insertEdge(v1, v2);
		}
		for (int i = 0; i < a; i++) {
			cin >> v1;
			cout << g.dfs(v1) << endl;
			g.reset();
		}
	}
}
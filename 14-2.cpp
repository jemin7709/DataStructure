#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
public:
	int size;
	vector<int>* v;

	Graph(int size) {
		this->size = size;
		v = new vector<int>[size + 1];
	}

	void insertEdge(int vertex1, int vertex2) {
		v[vertex1].push_back(vertex2);
		v[vertex2].push_back(vertex1);
	}

	int bfsandD(int cur, int target) {
		vector<int>visit, distance;
		queue<int>q;
		q.push(cur);
		visit.resize(size + 1, false);
		distance.resize(size + 1, 0);
		distance[cur] = 0;
		visit[cur] = true;
		while (!q.empty()) {
			int temp = q.front();
			q.pop();
			for (int i = 0; i < v[temp].size(); i++) {
				if (!visit[v[temp][i]]) {
					q.push(v[temp][i]);
					visit[v[temp][i]] = true;
					distance[v[temp][i]] = distance[temp] + 1;
				}
			}
		}
		return distance[target];
	}
};

int main() {
	int t, n, m, v1, v2, k, start, target;
	cin >> t;
	while (t--) {
		cin >> n >> m >> k;
		Graph g(n);
		for (int i = 0; i < m; i++) {
			cin >> v1 >> v2;
			g.insertEdge(v1, v2);
		}
		for (int i = 0; i < k; i++) {
			cin >> start >> target;
			cout << g.bfsandD(start, target) << " ";
			cout << endl;
		}
	}
}
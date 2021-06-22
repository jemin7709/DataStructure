#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 500
class ListGraph {
public:
	vector<int>list[MAX];
	int size;
	ListGraph(int size) {
		this->size = size + 1;
	}
	void insertE(int v1, int v2) {
		list[v1].push_back(v2);
		list[v2].push_back(v1);
	}
	int bfs(int cur) {
		vector<bool>visit;
		queue<int>q;
		int count = 0;
		visit.resize(size, false);
		q.push(cur);
		visit[cur] = true;
		while (!q.empty()) {
			int temp = q.front();
			q.pop();
			count++;
			for (int i = 0; i < list[temp].size(); i++) {
				int v = list[temp][i];
				if (!visit[v]) {
					q.push(v);
					visit[v] = true;
				}
			}
		}
		return count;
	}
};

int main() {
	int t, n, m, k, v1, v2, c;
	cin >> t;
	while (t--) {
		cin >> n >> m >> k;
		ListGraph g(n);
		while (m--) {
			cin >> v1 >> v2;
			g.insertE(v1, v2);
		}
		while (k--) {
			cin >> c;
			cout << g.bfs(c) << endl;
		}
	}
}
#include <iostream>
#include <queue>
#include <vector>
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
	int D(int start, int target) {
		vector<bool>visit;
		vector<int>distance;
		queue<int>q;
		visit.resize(size, false);
		distance.resize(size, 0);
		visit[start] = true;
		q.push(start);
		while (!q.empty()) {
			int temp = q.front();
			q.pop();
			for (int i = 0; i < list[temp].size(); i++) {
				int v = list[temp][i];
				if (!visit[v]) {
					q.push(v);
					visit[v] = true;
					distance[v] = distance[temp] + 1;
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
		ListGraph g(n);
		for (int i = 0; i < m; i++) {
			cin >> v1 >> v2;
			g.insertE(v1, v2);
		}
		for (int i = 0; i < k; i++) {
			cin >> start >> target;
			cout << g.D(start, target) << endl;
		}
	}
}
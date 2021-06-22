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
		this->size = size+1;
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
		q.push(start);
		visit[start] = true;
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
	int t, n, m, k, v1, v2;
	cin >> t;
	while (t--) {
		cin >> n >> m >> k;
		ListGraph g(n);
		while (m--) {
			cin >> v1 >> v2;
			g.insertE(v1, v2);
		}
		while (k--) {
			cin >> v1 >> v2;
			cout << g.D(v1, v2) << endl;
		}
	}
}
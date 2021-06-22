#include <iostream>
#include <vector>
using namespace std;

#define MAX 500
class ListGraph {
public:
	vector<int>list[MAX];
	vector<int>vlist;
	vector<bool>visit;
	int size;
	ListGraph() {
		visit.resize(MAX, false);
		size = 0;
	}
	int find(int v) {
		for (int i = 0; i < size; i++) {
			if (vlist[i] == v) {
				return i;
			}
		}
		return -1;
	}
	void insertV(int v) {
		vlist.push_back(v);
		size++;
	}
	void eraseV(int v) {
		int i = find(v);
		vlist.erase(vlist.begin() + i);
		size--;
	}
	void insertE(int v1, int v2) {
		//int i1 = find(v1);
		//int i2 = find(v2);
		list[v1].push_back(v2);
		list[v2].push_back(v1);
	}
	void eraseE(int v1, int v2) {
		int i1 = v1;
		int i2 = v2;
		int i12 = 0, i21 = 0;
		for (int i = 0; i < list[i1].size(); i++) {
			if (i2 == list[i1][i]) {
				i12 = i;
				break;
			}
		}
		for (int i = 0; i < list[i2].size(); i++) {
			if (i1 == list[i2][i]) {
				i21 = i;
				break;
			}
		}
		list[i1].erase(list[i1].begin() + i12);
		list[i2].erase(list[i2].begin() + i21);
	}
	void dfs(int v) {
		visit[v] = true;
		cout << v << " ";
		for (int i = 0; i < list[v].size(); i++) {
			int next = list[v][i];
			if (!visit[next]) {
				dfs(next);
			}
		}
	}
};

int main() {
	int t, n, m, v1, v2;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		ListGraph g;
		for (int i = 0; i < m; i++) {
			cin >> v1 >> v2;
			g.insertV(v1);
			g.insertV(v2);
			g.insertE(v1, v2);
		}
		g.dfs(1);
		cout << endl;
	}
}
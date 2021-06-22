#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define MAX 500
class VectorGraph {
public:
	bool matrix[MAX][MAX] = { false };
	vector<int>list;
	int size;
	VectorGraph() {
		size = 0;
	}
	int find(int v) {
		for (int i = 0; i < size; i++) {
			if (list[i] == v) {
				return i;
			}
		}
		return -1;
	}
	void insertV(int v) {
		list.push_back(v);
		size++;
	}
	void eraseV(int v) {
		int i = find(v);
		list.erase(list.begin() + i);
		size--;
	}
	void insertE(int v1, int v2) {
		int i1 = find(v1);
		int i2 = find(v2);
		matrix[i1][i2] = true;
		matrix[i2][i1] = true;
	}
	void eraseE(int v1, int v2) {
		int i1 = find(v1);
		int i2 = find(v2);
		matrix[i1][i2] = false;
		matrix[i2][i1] = false;
	}
	bool isAdjacentTo(int v1, int v2) {
		int i1 = find(v1);
		int i2 = find(v2);
		return matrix[i1][i2];
	}
	vector<int>oppositeList(int v) {
		int i = find(v);
		vector<int>oppo;
		for (int j = 0; j < size; j++) {
			if (matrix[i][j]) {
				oppo.push_back(j);
			}
		}
		return oppo;
	}
};

int main() {
	int n, m, x;
	cin >> n >> m;
	VectorGraph g;
	for (int i = 1; i <= n; i++) {
		g.insertV(i);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> x;
			if (x == 1) {
				g.insertE(i, j);
			}
		}
	}
	while (m--) {
		vector<int>list;
		vector<int>list2;
		vector<bool>ans;
		bool check = false;
		for (int i = 0; i < n; i++) {
			ans.push_back(false);
		}
		cin >> x;
		list = g.oppositeList(x);
		for (int i : list) {
			list2 = g.oppositeList(i + 1);
			for (int j = 0; j < list2.size(); j++) {
				if (list2[j] + 1 != x && !g.isAdjacentTo(x, list2[j] + 1)) {
					ans[list2[j]] = true;
				}
			}
		}
		for (int i = 0; i < ans.size(); i++) {
			if (ans[i] == true) {
				cout << i + 1 << " ";
				check = true;
			}
		}
		if (!check) {
			cout << 0;
		}
		cout << endl;
	}
}
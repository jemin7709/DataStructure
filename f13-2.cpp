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
	bool isAdjacentTo(int v1, int  v2) {
		int i1 = find(v1);
		int i2 = find(v2);
		return matrix[i1][i2];
	}
	bool isAdjacentAdjacentTo(int v1, int v2) {
		int i1 = find(v1);
		int i2 = find(v2);
		vector<int>ff;
		for (int i = 0; i < size; i++) {
			if (matrix[i1][i]) {
				ff.push_back(i);
			}
		}
		for (int i : ff) {
			if (matrix[i1][i] && matrix[i2][i]) {
				return true;
			}
		}
		return false;
	}
};

int main() {
	int n, m, x, k;
	cin >> n >> m;
	VectorGraph g;
	for (int i = 1; i < n + 1; i++) {
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
		cin >> k;
		int ans = 0;
		int* list = new int[k];
		for (int i = 0; i < k; i++) {
			cin >> x;
			list[i] = x;
		}
		for (int i = 0; i < k; i++) {
			for (int j = i + 1; j < k; j++) {
				if (g.isAdjacentTo(list[i], list[j])) {
					ans = 1;
				}
				else if (g.isAdjacentAdjacentTo(list[i], list[j])) {
					ans = 1;
				}
				else {
					ans = 0;
					goto out;
				}
			}
		}
	out:
		cout << ans << endl;
	}
}
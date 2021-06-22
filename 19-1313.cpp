#include <iostream>
#include <vector>
using namespace std;

#define MAX 500
class VectorGraph {
public:
	bool matrix[MAX][MAX] = { false };
	vector<int>list;
	int size;
	VectorGraph() {
		this->size = 0;
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
	void insertE(int v1, int v2) {
		int i1 = find(v1);
		int i2 = find(v2);
		matrix[i1][i2] = true;
		matrix[i2][i1] = true;
	}
	bool isAdjacentTo(int v1, int v2) {
		int i1 = find(v1);
		int i2 = find(v2);
		return matrix[i1][i2];
	}
	vector<int>opposite(int v) {
		int i1 = find(v);
		vector<int>oppo;
		for (int i = 0; i < size; i++) {
			if (matrix[i1][i]) {
				oppo.push_back(i);
			}
		}
		return oppo;
	}
};

int main() {
	int m, n, e, v1, v2;
	cin >> m >> n;
	VectorGraph g;
	for (int i = 1; i <= m; i++) {
		g.insertV(i);
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> e;
			if (e == 1) {
				g.insertE(i, j);
			}
		}
	}
	while (n--) {
		vector<int>list1;
		vector<int>list2;
		vector<bool>ans;
		bool check = false;
		ans.resize(m, false);
		cin >> v1;
		list1 = g.opposite(v1);
		for (int i : list1) {
			list2 = g.opposite(i + 1);
			for (int j = 0; j < list2.size(); j++) {
				if (list2[j] + 1 != v1 && !g.isAdjacentTo(v1, list2[j] + 1)) {
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
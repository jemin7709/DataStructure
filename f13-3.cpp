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
		if (matrix[i1][i2]) {
			cout << "Exist" << endl;
			return;
		}
		matrix[i1][i2] = true;
		matrix[i2][i1] = true;
	}
	void eraseE(int v1, int v2) {
		int i1 = find(v1);
		int i2 = find(v2);
		if (!matrix[i1][i2]) {
			cout << "None" << endl;
			return;
		}
		matrix[i1][i2] = false;
		matrix[i2][i1] = false;
	}
	int incidentEdges(int v) {
		int i1 = find(v);
		int count = 0;
		for (int i = 0; i < size; i++) {
			if (matrix[i1][i]) {
				count++;
			}
		}
		return count;
	}
};

int main() {
	int t, n, v1, v2;
	string c;
	cin >> t >> n;
	VectorGraph g;
	while (n--) {
		cin >> v1;
		g.insertV(v1);
	}
	while (t--) {
		cin >> c;
		if (c == "insertEdge") {
			cin >> v1 >> v2;
			g.insertE(v1, v2);
		}
		else if (c == "eraseEdge") {
			cin >> v1 >> v2;
			g.eraseE(v1, v2);
		}
		else if (c == "incidentEdges") {
			cin >> v1;
			cout << g.incidentEdges(v1) << endl;
		}
	}
	return 0;
}
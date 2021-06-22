#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define MAX 500
class VectorGraph {
public:
	int matrix[MAX][MAX] = { 0 };
	vector<int>vertexlist;
	int size;

	VectorGraph() {
		size = 0;
	}

	int find_vertex(int vertex) {
		for (int i = 0; i < size; i++) {
			if (vertexlist[i] == vertex) {
				return i;
			}
		}
		return -1;
	}

	void insert_vertex(int vertex) {
		vertexlist.push_back(vertex);
		size++;
	}

	void erase_vertex(int vertex) {
		int i = find_vertex(vertex);
		vertexlist.erase(vertexlist.begin() + i);
		size--;
	}

	void insert_edge(int vertex1, int vertex2) {
		int idx1 = find_vertex(vertex1);
		int idx2 = find_vertex(vertex2);
		matrix[idx1][idx2] = 1;
		matrix[idx2][idx1] = 1;
	}

	void erase_edge(int vertex1, int vertex2) {
		int idx1 = find_vertex(vertex1);
		int idx2 = find_vertex(vertex2);
		matrix[idx1][idx2] = 0;
		matrix[idx2][idx1] = 0;
	}

	bool isAdjacentTo(int vertex1, int vertex2) {
		int idx1 = find_vertex(vertex1);
		int idx2 = find_vertex(vertex2);
		if (matrix[idx1][idx2] != 0) {
			return true;
		}
		else {
			return false;
		}
	}

	bool isAdjacentAdjacentTo(int vertex1, int vertex2) {
		int idx1 = find_vertex(vertex1);
		int idx2 = find_vertex(vertex2);
		vector<int>list;
		for (int i = 0; i < size; i++) {
			if (matrix[idx1][i] != 0) {
				list.push_back(i);
			}
		}
		for (int i : list) {
			if (matrix[i][idx1] != 0 && matrix[i][idx2] != 0) {
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
		g.insert_vertex(i);
	}
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			cin >> x;
			if (x == 1) {
				g.insert_edge(i, j);
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
	return 0;
}
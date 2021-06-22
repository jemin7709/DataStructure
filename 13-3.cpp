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
		if (matrix[idx1][idx2] == 1) {
			cout << "Exist" << endl;
			return;
		}
		matrix[idx1][idx2] = 1;
		matrix[idx2][idx1] = 1;
	}

	void erase_edge(int vertex1, int vertex2) {
		int idx1 = find_vertex(vertex1);
		int idx2 = find_vertex(vertex2);
		if (matrix[idx1][idx2] == 0) {
			cout << "None" << endl;
			return;
		}
		matrix[idx1][idx2] = 0;
		matrix[idx2][idx1] = 0;
	}

	int incidentEdges(int vertex) {
		int idx = find_vertex(vertex);
		int count = 0;
		for (int i = 0; i < size; i++) {
			if (matrix[idx][i] != 0) {
				count++;
			}
		}
		return count;
	}
};

int main() {
	int t, n, vertex, vertex2;
	string c;
	cin >> t >> n;
	VectorGraph g;
	while (n--) {
		cin >> vertex;
		g.insert_vertex(vertex);
	}
	while (t--) {
		cin >> c;
		if (c == "insertEdge") {
			cin >> vertex >> vertex2;
			g.insert_edge(vertex, vertex2);
		}
		else if (c == "eraseEdge") {
			cin >> vertex >> vertex2;
			g.erase_edge(vertex, vertex2);
		}
		else if (c == "incidentEdges") {
			cin >> vertex;
			cout << g.incidentEdges(vertex) << endl;
		}
	}
	return 0;
}
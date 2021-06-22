#include <iostream>
#include <vector>
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
		int idx = find_vertex(vertex);
		vertexlist[idx] = -1;
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
};
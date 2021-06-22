#include <iostream>
#include <vector>
using namespace std;

#define MAX 500
class ListGraph {
public:
	vector<int>list[MAX];
	vector<int>vertexlist;
	int size;

	ListGraph() {
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
		list[idx1].push_back(idx2);
		list[idx2].push_back(idx1);
	}
	void erase_edge(int vertex1, int vertex2) {
		int idx1 = find_vertex(vertex1);
		int idx2 = find_vertex(vertex2);
		for (int i = 0; i < list[idx1].size(); i++) {
			if (idx2 == list[idx1][i]) {
				idx2 = i;
				break;
			}
		}
		for (int i = 0; i < list[idx2].size(); i++) {
			if (idx1 == list[idx2][i]) {
				idx1 = i;
				break;
			}
		}
		list[idx1].erase(list[idx1].begin() + idx2);
		list[idx2].erase(list[idx2].begin() + idx1);
	}
};
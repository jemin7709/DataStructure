#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct vertex {
	int vertex_id;
	int matrix_id;
	vertex* next;
	vertex* prev;

	vertex() {
		vertex_id = matrix_id = -1;
		prev = next = NULL;
	}
	vertex(int vertex_id) {
		this->vertex_id = vertex_id;
		matrix_id = -1;
		prev = next = NULL;
	}
};

struct edge {
	vertex* src;
	vertex* dst;
	edge* next;
	edge* prev;

	edge() {
		src = dst = NULL;
		prev = next = NULL;
	}
	edge(vertex* src, vertex* dst) {
		this->src = src;
		this->dst = dst;
		prev = next = NULL;
	}
};

class VertexList {
private:
	vertex* header;
	vertex* trailer;

public:
	VertexList() {
		header = new vertex();
		trailer = new vertex();
		header->next = trailer;
		trailer->prev = header;
	}

	void insert_back(vertex* new_vertex) {
		new_vertex->prev = trailer->prev;
		new_vertex->next = trailer;
		new_vertex->matrix_id = new_vertex->prev->matrix_id + 1;
		trailer->prev->next = new_vertex;
		trailer->prev = new_vertex;
		return;
	}

	void remove(vertex* del_vertex) {
		for (vertex* cur = del_vertex->next; cur != trailer; cur = cur->next) {
			cur->matrix_id--;
		}
		del_vertex->prev->next = del_vertex->next;
		del_vertex->next->prev = del_vertex->prev;
		delete del_vertex;
		return;
	}

	vertex* find_vertex(int vertex_id) {
		for (vertex* cur = header->next; cur != trailer; cur = cur->next) {
			if (cur->vertex_id == vertex_id) {
				return cur;
			}
		}
		return NULL;
	}
};

class EdgeList {
private:
	edge* header;
	edge* trailer;
public:
	EdgeList() {
		header = new edge();
		trailer = new edge();
		header->next = trailer;
		trailer->prev = header;
	}

	void insert_back(edge* new_edge) {
		new_edge->prev = trailer->prev;
		new_edge->next = trailer;
		trailer->prev->next = new_edge;
		trailer->prev = new_edge;
		return;
	}

	void remove(edge* del_edge) {
		del_edge->prev->next = del_edge->next;
		del_edge->next->prev = del_edge->prev;
		delete del_edge;
		return;
	}
};

class Graph {
private:
	edge*** edge_matrix;
	VertexList vertex_list;
	EdgeList edge_list;
	int vertex_size;
public:
	Graph() {
		vertex_size = 0;
		edge_matrix = NULL;
	}

	int getVertexSize() {
		return vertex_size;
	}

	void insert_vertex(int vertex_id) {
		if (vertex_list.find_vertex(vertex_id) != NULL) {
			return;
		}

		vertex* new_vertex = new vertex(vertex_id);
		edge*** new_matrix = new edge * *[vertex_size + 1];
		for (int i = 0; i < vertex_size + 1; i++) {
			new_matrix[i] = new edge * [vertex_size + 1];
		}
		for (int i = 0; i < vertex_size; i++) {
			for (int j = 0; j < vertex_size; j++) {
				new_matrix[i][j] = edge_matrix[i][j];
			}
		}
		for (int i = 0; i < vertex_size + 1; i++) {
			new_matrix[i][vertex_size] = new_matrix[vertex_size][i] = NULL;
		}
		for (int i = 0; i < vertex_size; i++) {
			delete[] edge_matrix[i];
		}
		delete[] edge_matrix;

		edge_matrix = new_matrix;
		vertex_list.insert_back(new_vertex);
		vertex_size++;
		return;
	}

	void erase_vertex(int vertex_id) {
		vertex* del_vertex = vertex_list.find_vertex(vertex_id);
		if (del_vertex == NULL) {
			return;
		}

		int del_idx = del_vertex->matrix_id;
		edge*** new_matrix = new edge * *[vertex_size - 1];
		for (int i = 0; i < vertex_size - 1; i++) {
			new_matrix[i] = new edge * [vertex_size - 1];
		}
		for (int i = 0; i < vertex_size - 1; i++) {
			for (int j = 0; j < vertex_size - 1; j++) {
				if (i < del_idx && j < del_idx) {
					new_matrix[i][j] = edge_matrix[i][j];
				}
				else if (i < del_idx) {
					new_matrix[i][j] = edge_matrix[i][j + 1];
				}
				else if (j < del_idx) {
					new_matrix[i][j] = edge_matrix[i + 1][j];
				}
				else {
					new_matrix[i][j] = edge_matrix[i + 1][j + 1];
				}
			}
		}
		for (int i = 0; i < vertex_size; i++) {
			if (edge_matrix[del_idx][i] != NULL) {
				edge_list.remove(edge_matrix[del_idx][i]);
			}
		}
		for (int i = 0; i < vertex_size; i++) {
			delete[] edge_matrix[i];
		}
		delete[] edge_matrix;

		edge_matrix = new_matrix;
		vertex_list.remove(del_vertex);
		vertex_size--;
		return;
	}

	void insert_edge(int src_vertex_id, int dst_vertex_id) {
		vertex* src_vertex = vertex_list.find_vertex(src_vertex_id);
		vertex* dst_vertex = vertex_list.find_vertex(dst_vertex_id);
		if (src_vertex == NULL || dst_vertex == NULL) {
			return;
		}
		int src_id = src_vertex->matrix_id;
		int dst_id = dst_vertex->matrix_id;

		if (edge_matrix[src_id][dst_id] != NULL || edge_matrix[dst_id][src_id] != NULL) {
			return;
		}

		edge* new_edge = new edge(src_vertex, dst_vertex);
		edge_list.insert_back(new_edge);
		edge_matrix[src_id][dst_id] = edge_matrix[dst_id][src_id] = new_edge;
		return;
	}

	void erase_edge(int src_vertex_id, int dst_vertex_id) {
		vertex* src_vertex = vertex_list.find_vertex(src_vertex_id);
		vertex* dst_vertex = vertex_list.find_vertex(dst_vertex_id);
		if (src_vertex == NULL || dst_vertex == NULL) {
			return;
		}
		int src_id = src_vertex->matrix_id;
		int dst_id = dst_vertex->matrix_id;

		if (edge_matrix[src_id][dst_id] == NULL || edge_matrix[dst_id][src_id] == NULL) {
			return;
		}

		edge_list.remove(edge_matrix[src_id][dst_id]);
		edge_matrix[src_id][dst_id] = edge_matrix[dst_id][src_id] = NULL;
		return;
	}

	bool isAdjacentTo(int src_vertex_id, int dst_vertex_id) {
		vertex* src_vertex = vertex_list.find_vertex(src_vertex_id);
		vertex* dst_vertex = vertex_list.find_vertex(dst_vertex_id);
		int src_id = src_vertex->matrix_id;
		int dst_id = dst_vertex->matrix_id;

		if (edge_matrix[src_id][dst_id] != NULL || edge_matrix[dst_id][src_id] != NULL) {
			return true;
		}
		else {
			return false;
		}
	}

	bool vertices1(int src_vertex_id, int dst_vertex_id) {
		vertex* vertex1 = vertex_list.find_vertex(src_vertex_id);
		vertex* vertex2 = vertex_list.find_vertex(dst_vertex_id);
		int id1 = vertex1->matrix_id;
		int id2 = vertex2->matrix_id;
		if (edge_matrix[id1][id2] != NULL) {
			return true;
		}
		else {
			return false;
		}
	}

	bool vertices2(int src_vertex_id, int dst_vertex_id) {
		vertex* vertex1 = vertex_list.find_vertex(src_vertex_id);
		vertex* vertex2 = vertex_list.find_vertex(dst_vertex_id);
		int id1 = vertex1->matrix_id;
		int id2 = vertex2->matrix_id;
		vector<int>list;
		for (int i = 0; i < vertex_size; i++) {
			if (edge_matrix[id1][i] != NULL) {
				list.push_back(i);
			}
		}
		for (int i : list) {
			if (edge_matrix[i][id1] != NULL && edge_matrix[i][id2] != NULL) {
				return true;
			}
		}
		return false;
	}
};

int main() {
	int n, m, x, k;
	cin >> n >> m;
	Graph g;
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
				if (g.vertices1(list[i], list[j])) {
					ans = 1;
				}
				else if (g.vertices2(list[i], list[j])) {
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
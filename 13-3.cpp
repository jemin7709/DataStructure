#include <iostream>
#include <string>
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
			cout << "Exist" << endl;
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
			cout << "None" << endl;
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

	int incidentEdges(int vertex_id) {
		vertex* vertex = vertex_list.find_vertex(vertex_id);
		int id = vertex->matrix_id;
		int count = 0;
		for (int i = 0; i < vertex_size; i++) {
			if (edge_matrix[id][i] != NULL) {
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
	Graph g;
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
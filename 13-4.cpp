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

	vector<int> oppositeVertexes(int vertex) {
		int idx = find_vertex(vertex);
		vector<int>list;
		for (int i = 0; i < size; i++) {
			if (matrix[idx][i] != 0) {
				list.push_back(i);
			}
		}
		return list;
	}
};

int main() {
	int n, m, x;
	cin >> n >> m; // �����ڼ� n�� ������ �� m�Է�
	VectorGraph g; // ������� �׷��� g ����
	for (int i = 1; i < n + 1; i++) {
		g.insert_vertex(i); // �����ڼ���ŭ ���� ����
	}
	for (int i = 1; i < n + 1; i++) { // 2x2�迭�� �Է��� �����Ƿ�
		for (int j = 1; j < n + 1; j++) { // 2�� for��
			cin >> x; // 0 or 1 �Է�
			if (x == 1) { // 1�� �Էµ� ���
				g.insert_edge(i, j); // i, j�ڸ��� ������ �߰�
			}
		}
	}
	while (m--) {
		vector<int>list; // ģ�� ����� ���� �迭
		vector<int>list2; // ģ���� ģ�� ����� ���� �迭
		vector<bool>ans; // ģ���� ģ���� ���°���� Ȯ���� �迭
		bool check = false; // ģ���� ģ���� �����ϴ��� �������� �ʴ��� Ȯ��
		for (int i = 0; i < n; i++) {
			ans.push_back(false); // ģ���� ģ�� �迭�� �ʱ�ȭ
		}
		cin >> x; // Ȯ���� ���� �Է�
		list = g.oppositeVertexes(x); // ģ�� ��� ��������
		for (int i : list) {
			list2 = g.oppositeVertexes(i + 1); // ģ���� ģ�� ��� ��������
			for (int j = 0; j < list2.size(); j++) {
				if (list2[j] + 1 != x && !g.isAdjacentTo(x, list2[j] + 1)) { // ������ �����ϰ� �Ÿ��� ģ���鼭 ģ���� ģ���� ģ���� ����
					ans[list2[j]] = true; // �ش� ��ȣ�� ģ���� �ִٰ� ����
				}
			}
		}
		for (int i = 0; i < ans.size(); i++) { // ģ�� ����� �о����
			if (ans[i] == true) { // ģ���� �ִٸ�
				cout << i + 1 << " "; // ���°���� ���
				check = true; // ģ���� ģ���� �����Ѵٰ� ����
			}
		}
		if (!check) { // ģ���� ģ���� �������� �ʴ´ٸ�
			cout << 0; // 0 ���
		}
		cout << endl;
	}
	return 0;
}
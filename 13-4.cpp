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
	cin >> n >> m; // 가입자수 n과 질의의 수 m입력
	VectorGraph g; // 인접행렬 그래프 g 생성
	for (int i = 1; i < n + 1; i++) {
		g.insert_vertex(i); // 가입자수만큼 정점 생성
	}
	for (int i = 1; i < n + 1; i++) { // 2x2배열로 입력이 들어오므로
		for (int j = 1; j < n + 1; j++) { // 2중 for문
			cin >> x; // 0 or 1 입력
			if (x == 1) { // 1이 입력된 경우
				g.insert_edge(i, j); // i, j자리에 엣지를 추가
			}
		}
	}
	while (m--) {
		vector<int>list; // 친구 목록을 담을 배열
		vector<int>list2; // 친구의 친구 목록을 담을 배열
		vector<bool>ans; // 친구의 친구가 몇번째인지 확인할 배열
		bool check = false; // 친구의 친구가 존재하는지 존재하지 않는지 확인
		for (int i = 0; i < n; i++) {
			ans.push_back(false); // 친구의 친구 배열을 초기화
		}
		cin >> x; // 확인할 정점 입력
		list = g.oppositeVertexes(x); // 친구 목록 가져오기
		for (int i : list) {
			list2 = g.oppositeVertexes(i + 1); // 친구의 친구 목록 가져오기
			for (int j = 0; j < list2.size(); j++) {
				if (list2[j] + 1 != x && !g.isAdjacentTo(x, list2[j] + 1)) { // 본인을 제외하고 거리가 친구면서 친구의 친구인 친구도 제외
					ans[list2[j]] = true; // 해당 번호의 친구가 있다고 변경
				}
			}
		}
		for (int i = 0; i < ans.size(); i++) { // 친구 목록을 읽어오기
			if (ans[i] == true) { // 친구가 있다면
				cout << i + 1 << " "; // 몇번째인지 출력
				check = true; // 친구의 친구가 존재한다고 변경
			}
		}
		if (!check) { // 친구의 친구가 존재하지 않는다면
			cout << 0; // 0 출력
		}
		cout << endl;
	}
	return 0;
}
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Node {
public:
	int data;
	Node* par;
	vector<Node*> chi;
	Node(int data) {
		this->data = data;
		par = NULL;
	}
};

class Tree {
public:
	Node* root;
	vector<Node*> all;
	Tree(int i) {
		root = new Node(i);
		all.push_back(root);
	}
	void insert(int x, int y) {
		Node* node = new Node(y);
		for (Node* n : all) {
			if (n->data == x) {
				node->par = n;
				n->chi.push_back(node);
				all.push_back(node);
				return;
			}
		}
	}
	void level(int x) {
		int count = 1;
		for (Node* n : all) {
			if (n->data == x) {
				while (n != root) {
					count++;
					n = n->par;
				}
				cout << count << endl;
				return;
			}
		}
		cout << -1 << endl;
	}
};

int main() {
	int n, m, x, y;
	Tree t(1);
	cin >> n >> m;
	while (n--) {
		cin >> x >> y;
		t.insert(x, y);
	}
	while (m--) {
		cin >> y;
		t.level(y);
	}

}
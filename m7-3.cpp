#include <iostream>
#include <vector>
using namespace std;

class Node{
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
	vector<Node*>all;
	Tree(int data) {
		root = new Node(data);
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

	void postOT(Node* n) {
		for (Node* c : n->chi) {
			postOT(c);
		}
		if (n == root) {
			cout << 0 << ' ';
		}
		else {
			cout << n->par->data << ' ';
		}
	}
};

int main() {
	int n, c, x, t;
	cin >> n;
	while (n--) {
		Tree T(1);
		cin >> c;
		while (c--) {
			cin >> x >> t;
			T.insert(x, t);
		}
		T.postOT(T.root);
		cout << endl;
	}
}
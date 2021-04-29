#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Tree {
public:
	class Node {
	public:
		int data;
		Node* par;
		vector<Node*> chi;
		Node(int data) {
			this->data = data;
			this->par = NULL;
		}
	};
	Node* root;
	vector<Node*> node_v;
	Tree() {
		Node* r = new Node(1);
		root = r;
		this->node_v.push_back(r);
	}

	void insertNode(int par_data, int data) {
		Node* node = new Node(data);
		for (unsigned int i = 0; i < node_v.size(); i++) {
			if (node_v[i]->data == par_data) {
				node_v[i]->chi.push_back(node);
				node_v.push_back(node);
				node->par = node_v[i];
				return;
			}
		}
	}

	Node* preOT(Node* node, int data) {
		if (node->data == data) {
			return node;
		}
		for (Node* c : node->chi) {
			Node* n = preOT(c, data);
			if (n != nullptr) {
				if (n->data == data) {
					return n;
				}
			}
		}
	}

	void prePrint(Node* node) {
		if (node == root) {
			cout << 0 << ' ';
		}
		else {
			cout << node->par->data << ' ';
		}
		if (!(node->chi.empty())) {
			for (Node* n : node->chi) {
				if (n != nullptr) {
					prePrint(n);
				}
			}
		}
	}


	void postPrint(Node* node) {
		if (!(node->chi.empty())) {
			for (Node* n : node->chi) {
				if (n != nullptr) {
					postPrint(n);
				}
			}
		}
		if (node == root) {
			cout << 0 << endl;
		}
		else {
			cout << node->par->data << ' ';
		}
	}
};

int main() {
	int n, c, x, t;
	cin >> n;
	while (n--) {
		Tree T;
		cin >> c;
		while (c--) {
			cin >> x >> t;
			T.insertNode(x, t);
		}
		T.postPrint(T.root);
		cout << endl;
	}
}
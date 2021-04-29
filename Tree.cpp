#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
	int data;
	Node* par;
	vector<Node*> chi;
	Node() {}
	Node(int data) {
		this->data = data;
		this->par = nullptr;
	}
};

class Tree :Node {
public:
	Node* root;
	Tree() {
		this->root = nullptr;
	}

	void insertNode(int parData, int data) {
		Node* node = new Node();
		Node* par = preOT(this->root, parData);
		
		node->data = data;
		node->par = par;
		par->chi.push_back(node);
	}

	void deleteNode(int data) {
		Node* node = preOT(this->root, data);
		Node* par = node->par;

		for (unsigned int i = 0; i < node->chi.size(); i++) {
			node->chi[i]->par = par;
		}
		for (unsigned int i = 0; i < par->chi.size(); i++) {
			if (par->chi[i] == node) {
				par->chi.erase(par->chi.begin() + i);
			}
		}
		delete node;
	}

	Node* preOT(Node* node, int data) {
		if (node->data == data) {
			return node;
		}
		for (Node* c : node->chi) {
			Node* re = preOT(c, data);
			if (re != nullptr) {
				if (re->data == data) {
					return re;
				}
			}
		}
	}

	Node* isNode(Node* node, int data) {
		if (node->data == data) {
			return node;
		}
		else {
			return nullptr;
		}
	}

	void prePrint(Node* node) {
		cout << node->data << ' ';
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
		cout << node->data << ' ';
	}
};

int main() {
	Node* root = new Node(1);
	Tree t;
	t.root = root;
	t.insertNode(root->data, 2);
	t.insertNode(root->data, 3);
	t.insertNode(2, 4);
	t.insertNode(2, 5);
	t.insertNode(3, 6);
	t.prePrint(root);
	cout << '\n';
	t.postPrint(root);
}
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int data;
	Node* par, * left, * right;
	Node(int data) {
		this->data = data;
		par = left = right = NULL;
	}
	void setLeft(Node* node) {
		if (node == NULL) {
			this->left = NULL;
		}
		else {
			this->left = node;
			node->par = this;
		}
	}
	void setRight(Node* node) {
		if (node == NULL) {
			this->right = NULL;
		}
		else {
			this->right = node;
			node->par = this;
		}
	}
};

class BST {
public:
	Node* root;
	BST() {
		root = NULL;
	}
	Node* search(int data) {
		Node* cur = root;
		while (cur != NULL) {
			if (data == cur->data) {
				return cur;
			}
			else if (data > cur->data) {
				cur = cur->right;
			}
			else {
				cur = cur->left;
			}
		}
		return NULL;
	}
	void insert(int data) {
		Node* node = new Node(data);
		if (root == NULL) {
			root = node;
			return;
		}
		Node* cur = root;
		Node* par = NULL;
		while (cur != NULL) {
			if (data > cur->data) {
				par = cur;
				cur = cur->right;
			}
			else {
				par = cur;
				cur = cur->left;
			}
		}
		if (data > par->data) {
			par->setRight(node);
		}
		else {
			par->setLeft(node);
		}
	}
	void remove(int data) {
		Node* node = search(data);
		Node* par = node->par;
		if (node->left == NULL && node->right == NULL) {
			par->left == node ? par->left = NULL : par->right = NULL;
		}
		else if (node->left == NULL || node->right == NULL) {
			Node* child = node->left == NULL ? node->right : node->left;
			child->par = par;
			if (node == root) {
				root = child;
				return;
			}
			par->left == node ? par->left = child : par->right = child;
		}
		else {
			Node* cur = node->right;
			while (cur->left != NULL) {
				cur = cur->left;
			}
			int temp = cur->data;
			remove(cur->data);
			node->data = temp;
		}
	}

	void solution(Node* node) {
		if (node == NULL) {
			return;
		}
		if (node->left != NULL) {
			solution(node->left);
		}
		cout << node->data << " ";
		if (node->right != NULL) {
			solution(node->right);
		}
	}
};

int main() {
	int n, size, data;
	cin >> n;
	while (n--) {
		BST b;
		cin >> size;
		for (int i = 0; i < size; i++) {
			cin >> data;
			b.insert(data);
		}
		b.solution(b.root);
		cout << endl;
	}
}
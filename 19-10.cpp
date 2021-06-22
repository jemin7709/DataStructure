#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* par, *left, *right;
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
	Node* find(int data) {
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
		return cur;
	}
	void insert(int data) {
		Node* node = new Node(data);
		if (root == NULL) {
			root = node;
			return;
		}
		Node* par = NULL;
		Node* cur = root;
		while (cur != NULL) {
			par = cur;
			if (data > cur->data) {
				cur = cur->right;
			}
			else {
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
		Node* node = find(data);
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

	int height(Node* node) {
		if (node == NULL) {
			return 0;
		}
		int left = height(node->left);
		int right = height(node->right);
		return 1 + (left > right ? left : right);
	}
};

int main() {
	int t, n, temp;
	cin >> t;
	while (t--) {
		BST b;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> temp;
			b.insert(temp);
		}
		cout << b.height(b.root) - 1 << endl;
	}
}
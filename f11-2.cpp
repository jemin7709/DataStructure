#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int data;
	Node* par, *left, *right;
	Node(int data) {
		this->data = data;
		left = right = par = NULL;
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
			if (par->left == node) {
				par->left = NULL;
			}
			else {
				par->right = NULL;
			}
		}
		else if (node->left == NULL || node->right == NULL) {
			Node* child = (node->left == NULL) ? node->right : node->left;
			child->par = par;
			if (node == root) {
				root = child;
				return;
			}
			if (par->left == node) {
				par->left = child;
			}
			else {
				par->right = child;
			}
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

	int sub(Node* node) {
		if (node == NULL) {
			return 0;
		}
		int count = 0;
		if (node->left != NULL) {
			count += sub(node->left);
		}
		count++;
		if (node->right != NULL) {
			count += sub(node->right);
		}
		return count;
	}
};

int main() {
	int n, data;
	string command;
	BST b;
	cin >> n;
	while (n--) {
		cin >> command;
		if (command == "insert") {
			cin >> data;
			b.insert(data);
		}
		else if (command == "delete") {
			cin >> data;
			b.remove(data);
		}
		else if (command == "sub") {
			cin >> data;
			Node* node = b.search(data);
			cout << b.sub(node) << endl;
		}
	}
}
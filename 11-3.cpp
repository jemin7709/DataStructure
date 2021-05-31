#include <iostream>
#include <string>

using namespace std;

class Node {
private:
	int data;
	Node* par;
	Node* left;
	Node* right;

public:
	Node(int data) {
		this->data = data;
		this->par = NULL;
		this->left = NULL;
		this->right = NULL;
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

	friend class BST;
};

class BST {
public:
	Node* root;
	BST() {
		this->root = NULL;
	}

	Node* search(int data) {
		Node* cur = this->root;
		while (cur != NULL) {
			if (data == cur->data) {
				return cur;
			}
			else if (data > cur->data) {
				cur = cur->right;
			}
			else if (data < cur->data) {
				cur = cur->left;
			}
		}
		return NULL;
	}

	void insert(int data) {
		Node* node = new Node(data);
		if (this->root == NULL) {
			this->root = node;
			return;
		}

		Node* par = NULL;
		Node* cur = this->root;

		while (cur != NULL) {
			if (data > cur->data) {
				par = cur;
				cur = cur->right;
			}
			else if (data < cur->data) {
				par = cur;
				cur = cur->left;
			}
		}

		if (data > par->data) {
			par->setRight(node);
		}
		else if (data < par->data) {
			par->setLeft(node);
		}
	}

	void remove(int data) {
		Node* node = search(data);
		Node* parn = node->par;

		if (node->left == NULL && node->right == NULL) {
			if (parn->data < node->data) {
				parn->right = NULL;
			}
			else if (parn->data > node->data) {
				parn->left = NULL;
			}
			delete node;
		}
		else if (node->left == NULL && node->right != NULL) {
			Node* right = node->right;
			right->par = parn;
			if (parn->data < right->data) {
				parn->right = right;
			}
			else if (parn->data > right->data) {
				parn->left = right;
			}
			delete node;
		}
		else if (node->left != NULL && node->right == NULL) {
			Node* left = node->left;
			left->par = parn;
			if (parn->data < left->data) {
				parn->right = left;
			}
			else if (parn->data > left->data) {
				parn->left = left;
			}
			delete node;
		}
		else {
			Node* cur = node->right;
			Node* parnn = NULL;
			while (cur->left != NULL) {
				cur = cur->left;
			}
			node->data = cur->data;
			parnn = cur->par;
			if (cur->right != NULL) {
				if (parn->data < cur->data) {
					parn->right = cur->right;
				}
				else if (parn->data > cur->data) {
					parn->left = cur->right;
				}
			}
			else {
				if (parnn == node) {
					parnn->right = NULL;
				}
				else {
					parnn->left = NULL;
				}
			}
		}
	}

	int count = 0;
	void solution(Node* node) {
		if (node == NULL) {
			return;
		}
		if (node->left != NULL) {
			solution(node->left);
		}
		cout << node->data << ' '; 
		if (node->right != NULL) {
			solution(node->right);
		}
	}
};

int main() {
	int t, n, data;
	cin >> t;
	while (t--) {
		BST b;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> data;
			b.insert(data);
		}
		b.solution(b.root);
		cout << endl;
	}
}
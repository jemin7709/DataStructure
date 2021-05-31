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

class BST{
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
			else {
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
			else {
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
		if (node == root) {
			if (root->right == NULL) {
				root = root->left;
			}
			else {
				root = root->right;
			}
			delete node;
			return;
		}

		if (node->left == NULL && node->right == NULL) {
			Node* parn = node->par;
			if (parn->data < node->data) {
				parn->right = NULL;
			}
			else if (parn->data > node->data) {
				parn->left = NULL;
			}
			delete node;
		}
		else if (node->left == NULL || node->right == NULL) {
			Node* parn = node->par;
			Node* child = (node->left == NULL) ? node->right : node->left;
			child->par = parn;
			if (parn->data < child->data) {
				parn->right = child;
			}
			else if (parn->data > child->data) {
				parn->left = child;
			}
			delete node;
		}
		else {
			Node* cur = node->right;
			Node* parn = NULL;
			while (cur->left != NULL) {
				cur = cur->left;
			}
			node->data = cur->data;
			parn = cur->par;
			if (cur->right != NULL) {
				cur->right->par = parn;
				if (parn == node) {
					parn->right = cur->right;
				}
				else {
					if (parn->data < cur->data) {
						parn->right = cur->right;
					}
					else if (parn->data > cur->data) {
						parn->left = cur->right;
					}
				}
			}
			else {
				(parn == node) ? parn->right = NULL : parn->left = NULL;
			}
			delete cur;
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
		count += 1;
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
		else if(command == "delete"){
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
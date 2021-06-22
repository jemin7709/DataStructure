#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int data;
	Node* par;
	Node* left;
	Node* right;
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
		Node* par = NULL;
		Node* cur = root;
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
		Node* parn = node->par;
		if (node->left == NULL && node->right == NULL) {
			if (parn->left == node) {
				parn->left = NULL;
			}
			else {
				parn->right = NULL;
			}
			delete node;
		}
		else if (node->left == NULL || node->right == NULL) {
			Node* child = (node->left == NULL) ? node->right : node->left;
			child->par = parn;
			if (node == root) {
				root = child;
				delete node;
				return;
			}
			if (parn->left == node) {
				parn->left = child;
			}
			else {
				parn->right = child;
			}
			delete node;
		}
		else if (node->left != NULL && node->right != NULL) {
			Node* cur = node->right;
			while (cur->left != NULL) {
				cur = cur->left;
			}
			int temp = cur->data;
			remove(cur->data);
			node->data = temp;
		}
	}
	int count = 0;
	void solution(Node* node, int index) {
		if (node == NULL) {
			return;
		}
		if (node->left != NULL) {
			solution(node->left, index);
		}
		count++;
		if (count == index) {
			cout << node->data << endl;
			return;
		}
		if (node->right != NULL) {
			solution(node->right, index);
		}
	}
};

int main() {
	int n, size, data, index;
	cin >> n;
	while (n--) {
		BST b;
		cin >> size;
		for (int i = 0; i < size; i++) {
			cin >> data;
			b.insert(data);
		}
		cin >> index;
		b.solution(b.root, index);
	}
}
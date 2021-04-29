#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Node {
public:
	int data;
	Node* par;
	vector<Node*>chi_v;

	Node(int data) {
		this->data = data;
		this->par = NULL;
	}
};

class Tree {
public:
	Node* root;
	vector<Node*> node_v;

	Tree(int data) {
		Node* node = new Node(data);
		this->root = node;
		this->node_v.push_back(node);
	}

	int insertNode(int par_data, int data) {
		Node* node = new Node(data);
		for (unsigned int i = 0; i < node_v.size(); i++) {
			if (node_v[i]->data == par_data) {
				node_v[i]->chi_v.push_back(node);
				node_v.push_back(node);
				node->par = node_v[i];
				return 1;
			}
		}
		return 0;
	}

	void delNode(int data) {
		Node* curNode;
		Node* parNode;
		for (unsigned int i = 0; i < node_v.size(); i++) {
			if (node_v[i]->data == data) {
				if (node_v[i] == root) {
					cout << -1 << endl;
					return;
				}

				curNode = node_v[i];
				parNode = curNode->par;
				for (Node* child : curNode->chi_v) {
					parNode->chi_v.push_back(child);
					child->par = parNode;
				}

				for (unsigned int j = 0; j < parNode->chi_v.size(); j++) {
					if (parNode->chi_v[j]->data == data) {
						parNode->chi_v.erase(parNode->chi_v.begin() + j);
					}
				}

				node_v.erase(node_v.begin() + i);
				delete curNode;
				return;
			}
		}
		cout << -1 << endl;
	}

	void printChi(int data) {
		for (unsigned int i = 0; i < node_v.size(); i++) {
			if (node_v[i]->data == data) {
				if (node_v[i]->chi_v.empty()) {
					cout << -1 << endl;
					return;
				}
				for (Node* child : node_v[i]->chi_v) {
					cout << child->data << " ";
				}
				cout << endl;
				return;
			}
		}
	}

	void printPar(int data) {
		for (unsigned int i = 0; i < node_v.size(); i++) {
			if (node_v[i]->data == data) {
				if (node_v[i] == root) {
					cout << -1 << endl;
					return;
				}
				cout << node_v[i]->par->data << endl;
				return;
			}
		}
		cout << -1 << endl;
	}

	void depth(int data) {
		int count = 0;
		Node* cur;
		for (unsigned int i = 0; i < node_v.size(); i++) {
			if (node_v[i]->data == data) {
				cur = node_v[i];
				while(cur != root) {
					cur = cur->par;
					count++;
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
		t.insertNode(x, y);
	}
	while (m--) {
		cin >> y;
		t.depth(y);
	}

}



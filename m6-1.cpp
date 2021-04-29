#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Node {
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
	vector<Node*> all;
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
		cout << -1 << endl;
	}

	void Delete(int x) {
		for (Node* n : all) {
			if (n->data == x) {
				if (n == root) {
					cout << -1 << endl;
					return;
				}
				Node* par = n->par;
				for (Node* c : n->chi) {
					c->par = par;
					par->chi.push_back(c);
				}
				for (int i = 0; i < par->chi.size(); i++) {
					if (par->chi[i] == n) {
						par->chi.erase(par->chi.begin() + i);
						break;
					}
				}
				for (int i = 0; i < all.size(); i++) {
					if (all[i] == n) {
						all.erase(all.begin() + i);
						break;
					}
				}
				delete n;
				return;
			}
		}
		cout << -1 << endl;
	}

	void print(int x) {
		for (Node* n : all) {
			if (n->data == x) {
				if (n->chi.empty()) {
					cout << -1 << endl;
					return;
				}
				for (Node* c : n->chi) {
					cout << c->data << ' ';
				}
				cout << endl;
				return;
			}
		}
		cout << -1 << endl;
	}

};

int main() {
	int n, x, y;
	string c;
	Tree t(1);
	cin >> n;
	while (n--) {
		cin >> c;
		if (c == "insert") {
			cin >> x >> y;
			t.insert(x, y);
		}
		else if (c == "delete") {
			cin >> x;
			t.Delete(x);
		}
		else if (c == "print") {
			cin >> x;
			t.print(x);
		}
	}

}
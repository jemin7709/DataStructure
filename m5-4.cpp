#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node* prev;
	Node() {
		data = 0;
		next = NULL;
		prev = NULL;
	}
	Node(int data) {
		this->data = data;
		next = NULL;
		prev = NULL;
	}
};

class Iterator {
public:
	Node* I;
	int operator *() {
		return I->data;
	}

	Iterator(Node* node) {
		I = node;
	}

	bool operator !=(Iterator n) {
		return I != n.I;
	}
	bool operator ==(Iterator n) {
		return I == n.I;
	}

	Iterator& operator ++() {
		I = I->next;
		return *this;
	}

	Iterator& operator --() {
		I = I->prev;
		return *this;
	}

};

class List {
public:
	Node* header;
	Node* trailer;
	int size;
	List() {
		header = new Node;
		trailer = new Node;
		header->next = trailer;
		trailer->prev = header;
		size = 0;
	}
	Iterator begin() {
		return Iterator(header->next);
	}
	Iterator end() {
		return Iterator(trailer);
	}

	void insert(Iterator p, int v) {
		Node* node = new Node(v);
		Node* cur = p.I;
		Node* pre = cur->prev;
		pre->next = node;
		node->prev = pre;
		node->next = cur;
		cur->prev = node;
		size++;
	}

};

int main() {
	int t, n, p, temp;
	cin >> t;
	while (t--) {
		cin >> n;
		List l;
		for (int i = 0; i < n; i++) {
			cin >> p;
			l.insert(l.end(), p);
		}
		Iterator prev = --l.begin();
		Iterator curr = l.begin();
		Iterator next = ++l.begin();
		while (curr != l.end()) {
			temp = *prev + 3 * (*curr) + *next;
			cout << temp << ' ';
			++prev;
			++curr;
			++next;
		}
		cout << endl;
	}
}
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
		next = prev = NULL;
	}
	Node(int data) {
		this->data = data;
		next = prev = NULL;
	}
};

class Iterator {
public:
	Node* I;
	Iterator(Node* n) {
		I = n;
	}
	Iterator& operator++() {
		I = I->next;
		return *this;
	}
	Iterator& operator--() {
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
	bool empty() {
		return size == 0;
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
		cur->prev = node;
		node->next = cur;
		size++;
	}

	Iterator erase(Iterator p) {
		if (empty()) {
			cout << "Empty" << endl;
		}
		else {
			Node* cur = p.I;
			Node* pre = cur->prev;
			pre->next = cur->next;
			cur->next->prev = pre;
			size--;
			return begin();
		}
	}

	void reversePrint() {
		if (empty()) {
			cout << "Empty" << endl;
			return;
		}
		Node* cur = trailer->prev;
		while (cur->prev != NULL) {
			cout << cur->data << ' ';
			cur = cur->prev;
		}
		cout << endl;
	}

	void find(int v) {
		if (empty()) {
			cout << "Empty" << endl;
			return;
		}
		int idx = -1;
		Node* cur = header->next;
		for (int i = 0; cur->next != NULL;i++) {
			if (cur->data == v) {
				idx = i;
				break;
			}
			cur = cur->next;
		}
		cout << idx << endl;
	}
};

int main() {
	int T, e;
	cin >> T;
	List l;
	Iterator iter = l.begin();

	for (int i = 0; i < T; i++) {
		string command;
		cin >> command;
		if (command == "begin") {
			iter = l.begin();
		}
		else if (command == "end") {
			iter = l.end();
		}
		else if (command == "insert") {
			cin >> e;
			l.insert(iter, e);
		}
		else if (command == "erase") {
			iter = l.erase(iter);
		}
		else if (command == "++") {
			++iter;
		}
		else if (command == "--") {
			--iter;
		}
		else if (command == "reversePrint") {
			l.reversePrint();
		}
		else if (command == "find") {
			cin >> e;
			l.find(e);
		}
	}
	return 0;
}
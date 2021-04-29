#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};

class SList {
public:
	Node* head;
	Node* tail;
	int size;

	SList() {
		head = NULL;
		tail = NULL;
		size = 0;
	}

	bool empty() {
		return size == 0;
	}

	void Print() {
		if (empty()) {
			cout << "Empty" << endl;
			return;
		}
		Node* cur = head;
		while (cur->next != NULL) {
			cout << cur->data << ' ';
			cur = cur->next;
		}
		cout << cur->data << endl;
	}

	void Append(int v) {
		Node* node = new Node();
		node->data = v;
		node->next = NULL;
		if (empty()) {
			head = tail = node;
		}
		else {
			tail->next = node;
			tail = node;
		}
		size++;
		Print();
	}

	void Insert(int i, int v) {
		if (i > size) {
			cout << "Index Error" << endl;
			return;
		}
		Node* n = new Node();
		n->data = v;
		n->next = NULL;
		Node* c = head;
		if (i == 0) {
			if (empty()) {
				Append(v);
			}
			else {
				n->next = head;
				head = n;
			}
		}
		else if (i == size) {
			Append(v);
		}
		else {
			for (int j = 0; j < i - 1; j++) {
				c = c->next;
			}
			n->next = c->next;
			c->next = n;
		}
		size++;
		Print();
	}

	void Delete(int i) {
		if (empty() || i >= size) {
			cout << -1 << endl;
			return;
		}
		int temp;
		if (i == 0) {
			temp = head->data;
			if (size == 1) {
				head = tail = NULL;
			}
			else {
				head = head->next;
			}
		}
		else {
			Node* c = head;
			Node* p = head;
			for (int j = 0; j < i; j++) {
				p = c;
				c = c->next;
			}
			temp = c->data;
			p->next = c->next;
			if (c == tail) {
				tail = p;
			}
		}
		cout << temp << endl;
		size--;
	}

	void Sum() {
		if (empty()) {
			cout << 0 << endl;
			return;
		}
		int sum = 0;
		Node* c = head;
		for (int in = 0; c != NULL; in++) {
			sum += c->data;
			c = c->next;
		}
		cout << sum << endl;
	}
};

int main() {
	int M, idx, value;
	string command;
	SList List;
	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> command;
		if (command == "Print") {
			List.Print();
		}
		if (command == "Append") {
			cin >> value;
			List.Append(value);
		}
		if (command == "Delete") {
			cin >> idx;
			List.Delete(idx);
		}
		if (command == "Insert") {
			cin >> idx >> value;
			List.Insert(idx, value);
		}
		if (command == "Sum") {
			List.Sum();
		}
	}
	return 0;
}
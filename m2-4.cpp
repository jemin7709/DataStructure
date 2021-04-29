#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node* prev;
	Node() {}
	Node(int data) {
		this->data = data;
		next = NULL;
		prev = NULL;
	}
};

class DList {
public:
	Node* header;
	Node* trailer;
	int size;
	DList() {
		header = NULL;
		trailer = NULL;
		size = 0;
	}
	
	bool empty() {
		return size == 0;
	}

	void Print() {
		if (empty()) {
			cout << "empty" << endl;
		}
		else {
			Node* cur = header;
			while (cur->next != NULL) {
				cout << cur->data << ' ';
				cur = cur->next;
			}
			cout << cur->data << endl;
		}
	}

	void Append(int v) {
		Node* node = new Node(v);
		if (empty()) {
			header = node;
			trailer = node;
		}
		else {
			trailer->next = node;
			node->prev = trailer;
			trailer = node;
		}
		size++;
		Print();
	}

	void Delete(int idx) {
		if (empty() || idx >= size) {
			cout << -1 << endl;
		}
		else {
			int temp;
			if (idx == 0) {
				temp = header->data;
				if (size == 1) {
					header = NULL;
					trailer = NULL;
				}
				else {
					header = header->next;
					header->prev = NULL;
				}
			}
			else if (idx == size - 1) {
				temp = trailer->data;
				trailer = trailer->prev;
				trailer->next = NULL;
			}
			else {
				Node* cur = header;
				Node* pre = trailer;
				for (int i = 0; i < idx; i++) {
					pre = cur;
					cur = cur->next;
				}
				temp = cur->data;
				pre->next = cur->next;
				if (cur == trailer) {
					trailer = pre;
				}
				else {
					cur->next->prev = pre;
				}
			}
			cout << temp << endl;
			size--;
		}
	}
	
	void Print_reverse() {
		if (empty()) {
			cout << "empty" << endl;
		}
		else {
			Node* cur = trailer;
			while (cur->prev != NULL) {
				cout << cur->data << ' ';
				cur = cur->prev;
			}
			cout << cur->data << endl;
		}
	}

	void Sum() {
		if (empty()) {
			cout << 0 << endl;
		}
		else {
			int sum = header->data;
			Node* cur = header->next;
			while (cur != NULL) {
				sum += cur->data;
				cur = cur->next;
			}
			cout << sum << endl;
		}
	}

};

int main() {
	int M, idx, value;
	string command;
	DList List;
	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> command;
		if (command == "Print") {
			List.Print();
		}
		else if (command == "Print_reverse") {
			List.Print_reverse();
		}
		else if (command == "Append") {
			cin >> value;
			List.Append(value);
		}
		else if (command == "Delete") {
			cin >> idx;
			List.Delete(idx);
		}
		else if (command == "Sum") {
			List.Sum();
		}
	}
	return 0;
}
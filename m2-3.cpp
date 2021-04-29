#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node() {};
	Node(int data) {
		this->data = data;
		next = NULL;
	}
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
			cout << "empty" << endl;
		}
		else {
			Node* cur = head;
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
			head = node;
			tail = node;
		}
		else {
			tail->next = node;
			tail = node;
		}
		size++;
	}

	void Delete(int idx) {
		if (empty() || idx >= size) {
			cout << -1 << endl;
		}
		else {
			int temp;
			if (idx == 0) {
				temp = head->data;
				if (size == 1) {
					head = NULL;
					tail = NULL;
				}
				else {
					head = head->next;
				}
			}
			else {
				Node* cur = head;
				Node* pre = head;
				for (int i = 0; i < idx; i++) {
					pre = cur;
					cur = cur->next;
				}
				temp = cur->data;
				pre->next = cur->next;
				if (cur == tail) {
					tail = pre;
				}
			}
			cout << temp << endl;
			size--;
		}
	}

	void Insert(int idx, int v) {
		if (idx > size) {
			cout << "Index Error" << endl;
		}
		else {
			Node* node = new Node(v);
			if (idx == 0) {
				if (empty()) {
					Append(v);
				}
				else {
					node->next = head;
					head = node;
				}
			}
			else if(idx == size){
				Append(v);
			}
			else {
				Node* cur = head;
				Node* pre = head;
				for (int i = 0; i < idx; i++) {
					pre = cur;
					cur = cur->next;
				}
				node->next = pre->next;
				pre->next = node;
			}
			Print();
			size++;
		}
	}

	void Min() {
		if (empty()) {
			cout << "empty" << endl;
		}
		else {
			int min = head->data;
			Node* cur = head->next;
			while (cur != NULL) {
				if (min > cur->data) {
					min = cur->data;
				}
				cur = cur->next;
			}
			cout << min << endl;
		}
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
			List.Print();
		}
		if (command == "Delete") {
			cin >> idx;
			List.Delete(idx);
		}
		if (command == "Insert") {
			cin >> idx >> value;
			List.Insert(idx, value);
		}
		if (command == "Min") {
			List.Min();
		}
	}
	return 0;
}
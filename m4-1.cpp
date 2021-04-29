#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node(int data) {
		this->data = data;
		next = NULL;
	}
};

class Queue {
public:
	Node* front;
	Node* rear;
	int size;
	Queue() {
		front = rear = NULL;
		size = 0;
	}

	bool empty() {
		return size == 0;
	}

	void enqueue(int v) {
		Node* node = new Node(v);
		if (empty()) {
			front = rear = node;
		}
		else {
			rear->next = node;
			rear = node;
		}
		size++;
	}

	void dqeueue() {
		if (empty()) {
			cout << "Empty" << endl;
		}
		else {
			cout << front->data << endl;
			front = front->next;
			size--;
		}
	}

	void isEmpty() {
		if (empty()) {
			cout << "True" << endl;
		}
		else {
			cout << "False" << endl;
		}
	}

	void gsize() {
		cout << size << endl;
	}

	void gfront() {
		if (empty()) {
			cout << "Empty" << endl;
			return;
		}
		cout << front->data << endl;
	}

	void grear() {
		if (empty()) {
			cout << "Empty" << endl;
			return;
		}
		cout << rear->data << endl;
	}
};

int main() {
	int N, data;
	string command;

	cin >> N;
	Queue q;

	for (int i = 0; i < N; i++) {
		cin >> command;
		if (command == "size") {
			q.gsize();
		}
		else if (command == "isEmpty") {
			q.isEmpty();
		}
		else if (command == "front") {
			q.gfront();
		}
		else if (command == "rear") {
			q.grear();
		}
		else if (command == "enqueue") {
			cin >> data;
			q.enqueue(data);
		}
		else if (command == "dequeue") {
			q.dqeueue();
		}
	}
}
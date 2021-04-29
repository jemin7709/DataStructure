#include <iostream>
#include <string>
using namespace std;

class Queue {
public:
	int front;
	int rear;
	int capa;
	int size;
	int* Q;

	Queue(int size) {
		capa = size + 1;
		front = rear = this->size = 0;
		Q = new int[size + 1];
	}

	bool full() {
		return size + 1 == capa;
	}

	bool empty() {
		return size == 0;
	}

	void enqueue(int v) {
		if (full()) {
			cout << "Full" << endl;
			return;
		}
		rear = (rear + 1) % capa;
		Q[rear] = v;
		size++;
	}

	void dequeue() {
		if (empty()) {
			cout << "Empty" << endl;
			return;
		}
		front = (front + 1) % capa;
		cout << Q[front] << endl;
		size--;
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
		cout << Q[front + 1] << endl;
	}

	void grear() {
		if (empty()) {
			cout << "Empty" << endl;
			return;
		}
		cout << Q[rear] << endl;
	}
};

int main() {
	int N, T, data;
	string command;

	cin >>N>>T;
	Queue q(N);

	for (int i = 0; i < T; i++) {
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
			q.dequeue();
		}
	}
}
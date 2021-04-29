#include <iostream>
#include <string>
using namespace std;

class CircularQueue {
private:
	int data;
	int size;
	int capa;
	int front;
	int rear;
	int* CQ;
public:
	CircularQueue(int size) {
		this->data = 0;
		CQ = new int[size];
		front = rear = 0;
		this->size = 0;
		capa = size;
	}
	bool isEmpty() {
		return this->size == 0;
	}
	bool isFull() {
		return this->size == this->capa - 1;
	}
	int getSize() {
		return this->size;
	}
	int getFront() {
		return CQ[front + 1];
	}
	int getRear() {
		return CQ[rear];
	}
	void enQueue(int data) {
		if (isFull()) {
			cout << "Full" << endl;
		}
		else {
			rear = (rear + 1) % capa;
			CQ[rear] = data;
			this->size++;
		}
	}
	int deQueue() {
		if (isEmpty()) {
			cout << "Empty" << endl;
			return 0;
		}
		else {
			front = (front + 1) % capa;
			this->size--;
			return CQ[front];
		}
	}
};

int main() {
	int N, data, size;
	string command;

	cin >> N >> size;
	CircularQueue q(size);

	for (int i = 0; i < N; i++) {
		cin >> command;
		if (command == "size") {
			cout << q.getSize() << endl;
		}
		else if (command == "isEmpty") {
			cout << boolalpha << q.isEmpty() << endl;
		}
		else if (command == "front") {
			cout << q.getFront() << endl;
		}
		else if (command == "rear") {
			cout << q.getRear() << endl;
		}
		else if (command == "enqueue") {
			cin >> data;
			q.enQueue(data);
		}
		else if (command == "dequeue") {
			cout << q.deQueue() << endl;
		}
		else {
			cout << "error" << endl;
		}
	}
}
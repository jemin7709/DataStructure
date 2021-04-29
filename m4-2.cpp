#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node() {}
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

	int dequeue() {
		if (empty()) {
			return 0;
		}
		int temp = front->data;
		front = front->next;
		size--;
		return temp;
	}

	void setfront(int v) {
		if (!empty()) {
			front->data = v;
		}
	}
	
	int getfront() {
		return front->data;
	}

};

int main() {
	int t, n, p1, p2, temp, p1p, p2p;
	cin >> t;
	while (t--) {
		p1p = p2p = 0;
		cin >> n;
		Queue Q1;
		Queue Q2;

		for (int i = 0; i < n; i++) {
			cin >> p1;
			Q1.enqueue(p1);
		}
		for (int i = 0; i < n; i++) {
			cin >> p2;
			Q2.enqueue(p2);
		}

		while (!Q1.empty()) {
			p1 = Q1.dequeue();
			p2 = Q2.dequeue();
			temp = p1 - p2;
			if (temp > 0) {
				p1p++;
				if (!Q1.empty()) {
					Q1.setfront(Q1.getfront() + temp);
				}
			}
			else if (temp < 0) {
				p2p++;
				if (!Q2.empty()) {
					Q2.setfront(Q2.getfront() + abs(temp));
				}
			}
		}
		if (p1p > p2p) {
			cout << 1 << endl;
		}
		else if (p1p < p2p) {
			cout << 2 << endl;
		}
		else {
			cout << 0 << endl;
		}

	}

}
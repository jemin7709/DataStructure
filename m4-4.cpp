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
		Q = new int[size + 1];
		front = rear = this->size = 0;
	}

	bool empty() {
		return size == 0;
	}

	void enqueue(int v) {
		rear = (rear + 1) % capa;
		Q[rear] = v;
		size++;
	}

	int dequeue() {
		front = (front + 1) % capa;
		size--;
		return Q[front];
	}

	void setfront(int v) {
		Q[front+1] = v;
	}

	int getfront() {
		return Q[front + 1];
	}
};

int main() {
	int t, n, p1,p2, temp, p1p, p2p;
	cin >> t;
	while (t--) {
		cin >> n;
		p1p = p2p = 0;
		Queue q1(100);
		Queue q2(100);
		for (int i = 0; i < n; i++) {
			cin >> p1;
			q1.enqueue(p1);
		}
		for (int i = 0; i < n; i++) {
			cin >> p2;
			q2.enqueue(p2);
		}

		while (true) {
			p1 = q1.dequeue();
			p2 = q2.dequeue();
			temp = p1 - p2;
			if (temp > 0) {
				p1p++;
				if (q1.empty()) {
					break;
				}
				q2.setfront(q2.getfront() + temp);
			}
			else if (temp < 0) {
				p2p++;
				if (q2.empty()) {
					break;
				}
				q1.setfront(q1.getfront() + abs(temp));
			}
			else {
				if (q1.empty()) {
					break;
				}
			}
		}

		if (p1p > p2p) {
			cout << p1p << endl;
		}
		else {
			cout << p2p << endl;
		}
	}

	return 0;
}
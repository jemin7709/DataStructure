#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int data;
	Node* up;
	Node* down;
	Node() {}
	Node(int data) {
		this->data = data;
		up = NULL;
		down = NULL;
	}
};

class Stack {
public:
	Node* top;
	Stack() {
		top = NULL;
	}

	int empty() {
		return top == NULL;
	}

	void Top() {
		if (empty()) {
			cout << -1 << endl;
			return;
		}
		cout << top->data << endl;
	}

	void push(int v) {
		Node* node = new Node(v);
		if (empty()) {
			top = node;
		}
		else {
			top->up = node;
			node->down = top;
			top = node;
		}
	}

	int pop() {
		if (empty()) {
			return 0;
		}
		else {
			int temp;
			temp = top->data;
			top = top->down;
			return temp;
		}
	}
};

int main() {
	int t, length, a, b;
	string y;
	cin >> t;
	while (t--) {
		cin >> y;
		length = y.size();
		Stack num;
		for (int i = 0; i < length; i++) {
			if (y[i] == '+') {
				b = num.pop();
				a = num.pop();
				num.push(a + b);
			}
			else if (y[i] == '-') {
				b = num.pop();
				a = num.pop();
				num.push(a - b);
			}
			else if (y[i] == '*') {
				b = num.pop();
				a = num.pop();
				num.push(a * b);
			}
			else {
				num.push(y[i] - '0');
			}
		}

		a = num.pop();
		cout << a << endl;
	}

}
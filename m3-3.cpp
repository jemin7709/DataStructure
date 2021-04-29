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
		if(empty()){
			top = node;
		}
		else {
			top->up = node;
			node->down = top;
			top = node;
		}
	}

	void pop() {
		if (empty()) {
			cout << -1 << endl;
		}
		else {
			cout << top->data << endl;
			top = top->down;
		}
	}
};


int main() {
	int N, data;
	string command;

	cin >> N;
	Stack stack;

	for (int i = 0; i < N; i++) {
		cin >> command;
		if (command == "empty") {
			cout << stack.empty() << endl;
		}
		else if (command == "top") {
			stack.Top();
		}
		else if (command == "push") {
			cin >> data;
			stack.push(data);
		}
		else if (command == "pop") {
			stack.pop();
		}
	}
}
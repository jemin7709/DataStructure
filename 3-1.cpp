#include <iostream>
#include <string>
using namespace std;

class Stack {
public:
	int top;
	int capacity;
	int* stack;

	Stack(int t) {
		stack = new int[t];
		top = -1;
		capacity = t;
	}

	int size() {
		return this->top + 1;
	}

	bool empty() {
		return this->top + 1 == 0;
	}

	bool full() {
		return this->top + 1 == capacity;
	}

	int ptop() {
		return this->stack[this->top];
	}

	void push(int data) {
		if (!full()) {
			this->stack[++this->top] = data;
		}
		else {
			cout << "FULL!" << endl;
		}
	}

	int pop() {
		if (!empty()) {
			return this->stack[this->top--];
		}
		else {
			return -1;
		}
	}

	void print() {
		if (this->empty()) {
			cout << "EMPTY!" << endl;
		}
		else {
			for (int i = 0; i < top+1; i++) {
				cout << stack[i] << ' ';
			}
			cout << '\n';
		}
	}

};

int main() {
	int t, N, data;
	string command;

	cin >> t >> N;
	Stack stack(t);

	for (int i = 0; i < N; i++) {
		cin >> command;
		if (command == "size") {
			cout << stack.size() << endl;
		}
		else if (command == "empty") {
			cout << boolalpha << stack.empty() << endl;
		}
		else if (command == "full") {
			cout << boolalpha << stack.full() << endl;
		}
		else if (command == "top") {
			cout << stack.ptop() << endl;
		}
		else if (command == "push") {
			cin >> data;
			stack.push(data);
		}
		else if (command == "pop") {
			cout << stack.pop() << endl;
		}
		else if (command == "print") {
			stack.print();
		}
	}
}
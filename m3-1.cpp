#include <iostream>
#include <string>
using namespace std;

class Stack {
public:
	int size;
	int capa;
	int* stack;
	Stack(int size) {
		this->size = -1;
		capa = size;
		stack = new int[size];
	}

	int empty() {
		return size == -1;
	}
	
	int full() {
		return size + 1 == capa;
	}

	void top() {
		if (empty()) {
			cout << -1 << endl;
		}
		else {
			cout << stack[size] << endl;
		}
	}

	void push(int v) {
		if (full()) {
			cout << "FULL" << endl;
		}
		else {
			size += 1;
			stack[size] = v;
		}
	}

	void pop() {
		if (empty()) {
			cout << -1 << endl;
		}
		else {
			cout << stack[size] << endl;
			size -= 1;
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
		if (command == "empty") {
			cout << stack.empty() << endl;
		}
		else if (command == "top") {
			stack.top();
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
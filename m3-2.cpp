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

	void push(int v) {
		if (full()) {

		}
		else {
			size++;
			stack[size] = v;
		}
	}

	int pop() {
		if (empty()) {
			return 0;
		}
		else {
			return stack[size--];
		}
	}
};

int main() {
	int t, a, b, size;
	string at;
	cin >> t;
	while (t--) {
		cin >> at;
		size = at.size();
		Stack s(100);

		for (int i = 0; i < size; i++) {
			if (at[i] == '+') {
				a = s.pop();
				b = s.pop();
				s.push(a + b);
			}
			else if (at[i] == '-') {
				a = s.pop();
				b = s.pop();
				s.push(b - a);
			}
			else if (at[i] == '*') {
				a = s.pop();
				b = s.pop();
				s.push(a * b);
			}
			else {
				s.push(at[i] - '0');
			}
		}

		a = b = s.pop();
		a = abs(a);
		while (a >= 10) {
			a = a % 10;
		}
		if (b < 0) {
			a *= -1;
		}
		cout << a << endl;
	}
}
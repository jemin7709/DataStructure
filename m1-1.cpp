#include <iostream>
#include <string>
using namespace std;

class Array {
public:
	int size;
	int capa;
	int* arr;
	Array(int s) {
		size = 0;
		capa = s;
		arr = new int[s] {0};
	}

	void at(int i) {
		cout << arr[i] << endl;
	}

	void add(int i, int v) {
		for (int in = capa - 2; in >= i; in--) {
			arr[in + 1] = arr[in];
		}
		arr[i] = v;
	}

	void remove(int i) {
		for (int in = i + 1; in <= capa - 1; in++) {
			arr[in - 1] = arr[in];
		}
		arr[capa-1] = 0;
	}

	void set(int i, int v) {
		arr[i] = v;
		cout << arr[i] << endl;
	}

	void print() {
		for (int i = 0; i < capa; i++) {
			cout << arr[i] << ' ';
		}
		cout << endl;
	}

	void find_max() {
		int max = arr[0];
		for (int i = 1; i < capa; i++) {
			if (max < arr[i]) {
				max = arr[i];
			}
		}
		cout << max << endl;
	}
};

int main() {
	int s, t;
	int i, v;
	string c;
	cin >> s >> t;
	Array arr(s);
	while (t--) {
		cin >> c;
		if (c == "at") {
			cin >> i;
			arr.at(i);
		}
		else if (c == "add") {
			cin >> i >> v;
			arr.add(i, v);
		}
		else if (c == "remove") {
			cin >> i;
			arr.remove(i);
		}
		else if (c == "set") {
			cin >> i >> v;
			arr.set(i, v);
		}
		else if (c == "print") {
			arr.print();
		}
		else if (c == "find_max") {
			arr.find_max();
		}
	}
}
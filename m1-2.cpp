#include <iostream>
#include <string>

using namespace std;

class Array {
public:
	int capa;
	int* arr;
	Array(int size) {
		capa = size;
		arr = new int[size];
	}

	void add(int index, int v) {
		for (int i = capa - 2; i >= index; i--) {
			arr[i + 1] = arr[i];
		}
		arr[index] = v;
	}

	void set(int index, int v) {
		arr[index] = v;
	}

	int at(int index) {
		return arr[index];
	}

	void print() {
		for (int i = 0; i < capa; i++) {
			cout << arr[i] << ' ';
		}
		cout << endl;
	}
};

int main() {
	int t, d, n, temp;
	cin >> t;
	while (t--) {
		cin >> n >> d;
		while (d > n) {
			d -= n;
		}
		Array N(n);
		Array D(d);

		for (int i = d; i < n; i++) {
			cin >> temp;
			N.add(i, temp);
		}
		for (int i = 0; i < d; i++) {
			cin >> temp;
			D.add(i, temp);
		}
		for (int i = 0; i < d; i++) {
			N.set(i, D.at(i));
		}
		N.print();
	}
	return 0;
}
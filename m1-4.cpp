#include <iostream>
using namespace std;

class Array {
public:
	int capa;
	int* arr;
	Array(int size) {
		capa = size;
		arr = new int[size];
	}

	void add(int i, int v) {
		for (int in = capa - 2; in >= i; in--) {
			arr[in + 1] = arr[in];
		}
		arr[i] = v;
	}

	void set(int i, int v) {
		arr[i] = v;
	}

	int at(int i) {
		return arr[i];
	}

	void print() {
		for (int i = 0; i < capa; i++) {
			cout << arr[i] << ' ';
		}
		cout << endl;
	}
};

int main() {
	int t, n, d, temp;
	cin >> t;
	while (t--) {
		cin >> n >> d;
		while (d > n) {
			d -= n;
		}
		Array N(n);
		Array D(d);
		for (int i = 0; i < d; i++) {
			cin >> temp;
			D.add(i, temp);
		}
		for (int i = 0; i < n-d; i++) {
			cin >> temp;
			N.add(i, temp);
		}
		for (int i = n-d; i < n; i++) {
			N.set(i, D.at(i - n + d));
		}
		N.print();
	}

}
#include <iostream>
#include <vector>
using namespace std;

enum { MIN = 1, MAX = -1 };

class Heap {
private:
	vector<int>v;
	int size;
	int root;
	int direction;
public:
	Heap(int direction) {
		v.push_back(-1);
		size = 0;
		root = 1;
		this->direction = direction;
	}
	void swap(int i1, int i2) {
		v[0] = v[i1];
		v[i1] = v[i2];
		v[i2] = v[0];
	}
	void upHeap(int i) {
		if (i == root) {
			return;
		}
		int parent = i / 2;
		if (v[i] * direction < v[parent] * direction) {
			swap(parent, i);
			upHeap(parent);
		}
	}
	void downHeap(int i) {
		int left = 2 * i;
		int right = 2 * i + 1;
		if (right <= size) {
			if (v[left] * direction <= v[right] * direction) {
				if (v[left] * direction < v[i] * direction) {
					swap(left, i);
					downHeap(left);
				}
				else { return; }
			}
			else{
				if (v[right] * direction < v[i] * direction) {
					swap(right, i);
					downHeap(right);
				}
				else { return; }
			}
		}
		else if (left <= size) {
			if (v[left] * direction < v[i] * direction) {
				swap(left, i);
				downHeap(left);
			}
			else { return; }
		}
		else { return; }
	}
	void insert(int e) {
		v.push_back(e);
		size++;
		upHeap(size);
	}
	int getSize() {
		return size;
	}
	bool isEmpty() {
		return size == 0;
	}
	void print() {
		if (isEmpty()) {
			cout << -1 << endl;
			return;
		}
		for (int i = 1; i <= size; i++) {
			cout << v[i] << " ";
		}
		cout << endl;
	}
	int top() {
		if (isEmpty()) {
			return -1;
		}
		return v[root];
	}
	void pop() {
		if (isEmpty()) {
			cout << -1 << endl;
			return;
		}
		int top = v[root];
		v[root] = v[size];
		v.pop_back();
		size--;
		downHeap(root);
		cout << top << endl;
	}
};

int main() {
	int n, temp;
	string c;
	Heap h(MIN);
	cin >> n;
	while (n--) {
		cin >> c;
		if (c == "insert") {
			cin >> temp;
			h.insert(temp);
		}
		else if (c == "size") {
			cout << h.getSize() << endl;
		}
		else if (c == "isEmpty") {
			cout << h.isEmpty() << endl;
		}
		else if (c == "print") {
			h.print();
		}
		else if (c == "top") {
			cout << h.top() << endl;
		}
		else if (c == "pop") {
			h.pop();
		}
	}
}
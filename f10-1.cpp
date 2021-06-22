#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define MIN 1
#define MAX -1

class Heap {
private:
	vector<int>v;
	int size;
	int root;
	int direction;
public:
	Heap(int direction) {
		v.push_back(-1);
		this->size = 0;
		this->root = 1;
		this->direction = direction;
	}
	void swap(int idx1, int idx2) {
		v[0] = v[idx1];
		v[idx1] = v[idx2];
		v[idx2] = v[0];
	}
	void upHeap(int idx) {
		if (idx == root) {
			return;
		}
		int parent = idx / 2;
		if (v[parent] * direction > v[idx] * direction) {
			swap(parent, idx);
			upHeap(parent);
		}
	}
	void downHeap(int idx) {
		int left = idx * 2;
		int right = idx * 2 + 1;
		if (right <= size) {
			if (v[left] * direction <= v[right] * direction) {
				if (v[left] * direction < v[idx] * direction) {
					swap(idx, left);
					downHeap(left);
				}
				else { return; }
			}
			else {
				if (v[right] * direction < v[idx] * direction) {
					swap(idx, right);
					downHeap(right);
				}
				else { return; }
			}
		}
		else if (left <= size) {
			if (v[left] * direction < v[idx] * direction) {
				swap(left, idx);
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

	int pop() {
		if (isEmpty()) {
			return -1;
		}
		int top = v[root];
		v[root] = v[size];
		size--;
		v.pop_back();
		downHeap(root);
		return top;
	}

	int top() {
		if (isEmpty()) {
			return -1;
		}
		return v[root];
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
		for (int i = root; i <= size; i++) {
			cout << v[i] << " ";
		}
		cout << endl;
	}
};

int main() {
	int t, e;
	string c;
	Heap h(MAX);

	cin >> t;

	while (t--) {
		cin >> c;

		if (c == "insert") {
			cin >> e;
			h.insert(e);
		}
		else if (c == "size") {
			cout << h.getSize() << endl;
		}
		else if (c == "isEmpty") {
			if (h.isEmpty()) {
				cout << 1 << endl;
			}
			else {
				cout << 0 << endl;
			}
		}
		else if (c == "pop") {
			cout << h.pop() << endl;
		}
		else if (c == "top") {
			cout << h.top() << endl;
		}
		else {
			h.print();
		}
	}
}
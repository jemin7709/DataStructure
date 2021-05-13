#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum direction { MIN = 1, MAX = -1 };

class Heap {
private:
	vector<int>v;
	int size;
	int root_index;
	int direction;

public:
	Heap(int direction) {
		v.push_back(-1);
		this->size = 0;
		this->root_index = 1;
		this->direction = direction;
	}

	void swap(int idx1, int idx2) {
		v[0] = v[idx1];
		v[idx1] = v[idx2];
		v[idx2] = v[0];
	}

	void upHeap(int idx) {
		if (idx == root_index) {
			return;
		}
		int parentidx = idx / 2;
		if (v[parentidx] * direction > v[idx] * direction) {
			swap(parentidx, idx);
			upHeap(parentidx);
		}
	}

	void downHeap(int idx) {
		int left = idx * 2;
		int right = idx * 2 + 1;
		if (right <= size) {
			if (v[left] * direction <= v[right] * direction) {
				if (v[left] * direction < v[idx] * direction) {
					swap(left, idx);
					downHeap(left);
				}
				else {
					return;
				}
			}
			else {
				if (v[right] * direction < v[idx] * direction) {
					swap(right, idx);
					downHeap(right);
				}
				else {
					return;
				}
			}
		}
		else if (left <= size) {
			if (v[left] * direction < v[idx] * direction) {
				swap(left, idx);
				downHeap(left);
			}
			else {
				return;
			}
		}
		else {
			return;
		}
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
		int top = v[root_index];
		v[root_index] = v[size];
		size--;
		v.pop_back();
		downHeap(root_index);
		return top;
	}

	int top() {
		if (isEmpty()) {
			return -1;
		}
		return v[root_index];
	}

	int Size() {
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
		for (int i = root_index; i <= size; i++) {
			cout << v[i] << ' ';
		}
		cout << endl;
	}
};

int main() {
	int t, e;
	string c;
	Heap h(MIN);

	cin >> t;

	while (t--) {
		cin >> c;

		if (c == "insert") {
			cin >> e;
			h.insert(e);
		}
		else if (c == "size") {
			cout << h.Size() << endl;
		}
		else if (c == "isEmpty") {
			cout << h.isEmpty() << endl;
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
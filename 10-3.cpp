#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum direction { MIN = 1, MAX = -1 };

class Heap{
private:
	vector<int> v;
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

	int getSize() {
		return size;
	}

	bool empty() {
		return size == 0;
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
		int paridx = idx / 2;
		if (v[paridx] * direction > v[idx] * direction) {
			swap(paridx, idx);
			upHeap(paridx);
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

	void insert(int data) {
		v.push_back(data);
		size++;
		upHeap(size);
	}

	int pop() {
		if (empty()) {
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
		if (empty()) {
			return -1;
		}
		return v[root];
	}

	void print() {
		if (empty()) {
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
	Heap h(MIN);

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
			cout << h.empty() << endl;
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
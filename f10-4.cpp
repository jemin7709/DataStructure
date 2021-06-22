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
		int left = 2 * idx;
		int right = 2 * idx + 1;
		if (right <= size) {
			if (v[left] * direction <= v[right] * direction) {
				if (v[left] * direction < v[idx] * direction) {
					swap(left, idx);
					downHeap(left);
				}
				else { return; }
			}
			else {
				if (v[right] * direction < v[idx] * direction) {
					swap(right, idx);
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
	bool isEmpty() {
		return size == 0;
	}
	int getSize() {
		return size;
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
		v.pop_back();
		size--;
		downHeap(root);
		return top;
	}
	int top() {
		return v[root];
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
	int t, temp, in, temp1, temp2, size;
	cin >> t;
	while (t--) {
		Heap h(MIN);
		cin >> size >> temp;
		for (int i = 0; i < size; i++) {
			cin >> in;
			h.insert(in);
		}
		while (h.top() < temp) {
			if (h.getSize() == 1) {
				break;
			}
			temp1 = h.pop();
			temp2 = h.pop();
			h.insert((temp1 + temp2) / 2);
		}
		if (h.top() < temp) {
			cout << "False" << endl;
		}
		else {
			cout << "True" << endl;
			h.print();
		}
	}
}
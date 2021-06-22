#include <iostream>
#include <vector>
using namespace std;

enum { MIN = 1, MAX = -1 };

class Heap {
public:
	vector<int>v;
	int size;
	int root;
	int direction;
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
		if (v[parent] * direction > v[i] * direction) {
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
			else {
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
	void push(int e) {
		v.push_back(e);
		size++;
		upHeap(size);
	}
	int pop() {
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
		for (int i = 1; i <= size; i++) {
			cout << v[i] << " ";
		}
		cout << endl;
	}
};

int main() {
	int t, k, n, p;
	cin >> t;
	while (t--) {
		Heap h(MIN);
		cin >> n >> p;
		for (int i = 0; i < n; i++) {
			cin >> k;
			h.push(k);
		}
		while (h.top() < p) {
			if (h.size == 1) {
				break;
			}
			int t1 = h.pop();
			int t2 = h.pop();
			h.push((t1 + t2) / 2);
		}
		if (h.top() > p) {
			cout << "True" << endl;
			h.print();
		}
		else {
			cout << "False" << endl;
		}
	}
}
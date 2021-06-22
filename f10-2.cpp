#include <iostream>
#include <vector>
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
	void downHaep(int idx) {
		int left = idx * 2;
		int right = idx * 2 + 1;
		if (right <= size) {
			if (v[left] * direction <= v[right] * direction) {
				if (v[left] * direction < v[idx] * direction) {
					swap(left, idx);
					downHaep(left);
				}
				else { return; }
			}
			else {
				if (v[right] * direction < v[idx] * direction) {
					swap(right, idx);
					downHaep(right);
				}
				else { return; }
			}
		}
		else if (left <= size) {
			if (v[left] * direction < v[idx] * direction) {
				swap(left, idx);
				downHaep(left);
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
		downHaep(root);
		return top;
	}
	int top() {
		if (isEmpty()) {
			return -1;
		}
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
		int count = 0;
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
			count++;
		}
		if (h.top() < temp) {
			cout << "False" << endl;
		}
		else {
			cout << count << endl;
			h.print();
		}
	}
}
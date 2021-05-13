#include <iostream>
#include <vector>

using namespace std;

class isLess {
public:
	bool operator()(int a, int b) {
		return a < b;
	}
};

class NSPQ {
public:
	vector<int> v;

	int size() {
		return v.size();
	}

	bool empty() {
		return v.empty();
	}

	void insert(int e) {
		vector<int>::iterator p = v.begin();
		isLess c;
		if (empty()) {
			v.insert(p, e);
		}
		else {
			while (p != v.end() && c(e, *p)) {
				++p;
			}
			v.insert(p, e);
		}
	}

	int min() {
		return v.back();
	}

	void removemin() {
		v.pop_back();

	}

	void print() {
		for (vector<int>::iterator iter = --v.end(); iter != v.begin(); --iter) {
			cout << *iter << ' ';
		}
		cout << v.front() << endl;
	}
};

int main() {
	int t, n, temp;
	cin >> t;
	while (t--) {
		cin >> n;
		NSPQ q;
		for (int i = 0; i < n; i++) {
			cin >> temp;
			q.insert(temp);
		}
		q.print();
	}

}
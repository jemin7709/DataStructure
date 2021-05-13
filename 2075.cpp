#include <iostream>
#include <vector>

using namespace std;

class isMore {
public:
	bool operator()(int a, int b) {
		return a > b;
	}
};

class NSPQ {
public:
	vector<long> v;

	int size() {
		return v.size();
	}

	bool empty() {
		return v.empty();
	}

	void insert(long e) {
		vector<long>::iterator p = v.begin();
		isMore c;
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

	int max() {
		return v.back();
	}

	void removemax() {
		v.pop_back();

	}

	void print() {
		for (vector<long>::iterator iter = --v.end(); iter != v.begin(); --iter) {
			cout << *iter << ' ';
		}
		cout << v.front() << endl;
	}
};

int main() {
	int n;
	long temp;
	cin >> n;
	NSPQ q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> temp;
			if (q.size() < n) {
				q.insert(temp);
			}
			else {
				if (temp > q.max()) {
					q.removemax();
					q.insert(temp);
				}
			}
		}
	}
	cout << q.v.at(n - 1);
	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

class isLess {
public:
	bool operator()(int a, int b) {
		return a < b;
	}
};

class SPQ {
public:
	vector<int>v;

	int size() {
		return v.size();
	}

	bool empty() {
		return v.empty();
	}

	void insert(int data) {
		vector<int>::iterator i = v.begin();
		isLess c;
		if (empty()) {
			v.push_back(data);
			return;
		}
		else {
			while (i != v.end() && c(data, *i)) {
				i++;
			}
			v.insert(i, data);
		}
		return;
	}

	int min() {
		return v.back();
	}

	void removemin() {
		v.pop_back();
	}

	void print() {
		for (vector<int>::iterator i = --v.end(); i != v.begin(); i--) {
			cout << *i << " ";
		}
		cout << v.front() << endl;
		return;
	}
};

int main() {
	int t, n, temp;
	cin >> t;
	while (t--) {
		cin >> n;
		SPQ q;
		for (int i = 0; i < n; i++) {
			cin >> temp;
			q.insert(temp);
		}
		q.print();
	}
}
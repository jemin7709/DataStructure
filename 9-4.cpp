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
	vector<int>v;

	int size() {
		return v.size();
	}

	bool empty() {
		return v.empty();
	}

	void insert(int data) {
		v.push_back(data);
	}

	int min() {
		int min = v.front();
		vector<int>::iterator p = v.begin();
		for (vector<int>::iterator i = v.begin(); i != v.end(); i++) {
			if (min > *i) {
				min = *i;
				p = i;
			}
		}
		return min;
	}

	void removemin() {
		int min = v.front();
		vector<int>::iterator p = v.begin();
		for (vector<int>::iterator i = v.begin(); i != v.end(); i++) {
			if (min > *i) {
				min = *i;
				p = i;
			}
		}
		v.erase(p);
	}
};

int main() {
	int t, n, temp;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> s;
		NSPQ q;
		for (int i = 0; i < n; i++) {
			cin >> temp;
			q.insert(temp);
		}
		for (int i = 0; i < n; i++) {
			s.push_back(q.min());
			q.removemin();
		}
		for (vector<int>::iterator iter = --s.end(); iter != s.begin(); --iter) {
			cout << *iter << ' ';
		}
		cout << s.front() << endl;
	}
}
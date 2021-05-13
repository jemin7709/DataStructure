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
	vector<int> v;

	int size() {
		return v.size();
	}

	bool empty() {
		return v.empty();
	}

	void insert(int e) {
		v.push_back(e);
	}

	int min() {
		vector<int>::iterator p = v.begin();
		isLess c;
		int mini = v.front();
		for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++) {
			if (!c(mini, *iter)) {
				mini = *iter;
				p = iter;
			}
		}
		return *p;
	}

	void removemin() {
		vector<int>::iterator p = v.begin();
		isLess c;
		int mini = v.front();
		for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++) {
			if (!c(mini, *iter)) {
				mini = *iter;
				p = iter;
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
		SPQ q;
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
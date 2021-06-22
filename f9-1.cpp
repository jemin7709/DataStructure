#include <iostream>
#include <vector>

using namespace std;

class isLess {
public:
	bool operator()(int a, int b){
		return a < b;
	}
};

class PQ {
public:
	vector<int>v;
	int size(){
		return v.size();
	}
	bool empty() {
		return v.empty();
	}
	void insert(int e) {
		vector<int>::iterator p = v.begin();
		if (empty()) {
			v.push_back(e);
		}
		else {
			while (p != v.end() && e < *p) {
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
		for (vector<int>::iterator iter = --v.end(); iter != v.begin();--iter) {
			cout << *iter << " ";
		}
		cout << v.front() << endl;
	}
};

int main() {
	int t, n, temp;
	cin >> t;
	while (t--) {
		cin >> n;
		PQ q;
		for (int i = 0; i < n; i++) {
			cin >> temp;
			q.insert(temp);
		}
		q.print();
	}
}
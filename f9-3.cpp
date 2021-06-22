#include <iostream>
#include <vector>
using namespace std;

class PQ {
public:
	vector<int>v;

	void insert(int e) {
		if (v.empty()) {
			v.push_back(e);
		}
		else {
			vector<int>::iterator p = v.begin();
			while (p != v.end() && e > *p) {
				p++;
			}
			v.insert(p, e);
		}
	}
	void print() {
		for (int i : v) {
			cout << i << " ";
		}
		cout << endl;
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
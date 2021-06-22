#include <iostream>
#include <vector>
using namespace std;

class PQ {
public:
	vector<int>q;
	void insert(int e) {
		if (q.empty()) {
			q.push_back(e);
			return;
		}
		vector<int>::iterator iter = q.begin();
		while (iter != q.end()&& e < *iter) {
			++iter;
		}
		q.insert(iter, e);
	}
	void print() {
		for (int i : q) {
			cout << i << " ";
		}
		cout << endl;
	}
};
int main() {
	int t, n, num;
	cin >> t;
	while (t--) {
		PQ q;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> num;
			q.insert(num);
		}
		q.print();
	}
}
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t, n, z, i;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int>x;
		vector<int>y;
		for (int j = 0; j < n; j++) {
			cin >> z;
			x.push_back(z);
		}
		for (int j = 0; j < n; j++) {
			cin >> z;
			y.push_back(z);
		}
		y.push_back(0);
		i = 0;
		while (y.size() != 1) {
			if (y[i] < y[i + 1]) {
				i++;
			}
			else {
				cout << x[i] << ' ';
				x.erase(x.begin() + i);
				y.erase(y.begin() + i);
				i--;
			}
		}
		cout << endl;
	}
}
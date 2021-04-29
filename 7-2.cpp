#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int t, s, temp;
	cin >> t;
	while (t--) {
		cin >> s;
		vector<int>x;
		vector<int>y;

		for (int i = 0; i< s; i++) {
			cin >> temp;
			x.push_back(temp);
		}
		for (int i = 0; i < s; i++) {
			cin >> temp;
			y.push_back(temp);
		}
		y.push_back(0);
		int i = 0;
		while (true) {
			if (y[i] >= y[i+1]) {
				cout << x[i] << ' ';
				x.erase(x.begin()+ i);
				y.erase(y.begin() + i);
				i--;
			}
			else {
				i++;
			}
			if (x.size() == 2) {
				cout << x.back() << ' ';
				x.pop_back();
				cout << x.back() << endl;
				break;
			}
		}
	}
}
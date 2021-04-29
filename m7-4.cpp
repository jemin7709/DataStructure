#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t, n, temp;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int>x;
		vector<int>y;
		vector<int>z;
		for (int i = 0; i < n; i++) {
			cin >> temp;
			x.push_back(temp);
		}
		for (int i = 0; i < n; i++) {
			cin >> temp;
			y.push_back(temp);
		}
		int left = 0;
		int right = x.size() - 1;
		for (int i = 0; i < x.size() / 2; i++) {
			temp = x[left];
			x[left] = x[right];
			x[right] = temp;
			temp = y[left];
			y[left] = y[right];
			y[right] = temp;
			left++;
			right--;
		}

		y.push_back(0);
		int i = 0;
		while (y.size() != 1) {
			if (y[i] < y[i + 1]) {
				i++;
			}
			else {
				z.push_back(x[i]);
				x.erase(x.begin() + i);
				y.erase(y.begin() + i);
				i--;
			}
		}
		left = 0;
		right = z.size() - 1;
		for (int j = 0; j < z.size() / 2; j++) {
			temp = z[left];
			z[left] = z[right];
			z[right] = temp;
			left++;
			right--;
		}
		for (int o : z) {
			cout << o << ' ';
		}
		cout << endl;
	}
}
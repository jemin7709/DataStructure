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
		vector<int>z;

		for (int i = 0; i < s; i++) {
			cin >> temp;
			x.push_back(temp);
		}
		for (int i = 0; i < s; i++) {
			cin >> temp;
			y.push_back(temp);
		}
		int left = 0;
		int right = x.size() - 1;
		int temp;
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

		//for (int i : x) {
		//	cout << i << ' ';
		//}
		//cout << endl;
		//for (int i : y) {
		//	cout << i << ' ';
		//}
		//cout << endl;

		
		y.push_back(0);
		int i = 0;
		while (true) {
			if (y[i] >= y[i + 1]) {
				z.push_back(x[i]);
				x.erase(x.begin() + i);
				y.erase(y.begin() + i);
				i--;
			}
			else {
				i++;
			}
			if (x.size() == 2) {
				z.push_back(x.back());
				x.pop_back();
				z.push_back(x.back());
				break;
			}
		}
		left = 0;
		right = z.size() - 1;
		for (int i = 0; i < z.size() / 2; i++) {
			temp = z[left];
			z[left] = z[right];
			z[right] = temp;
			left++;
			right--;
		}
		for (int i : z) {
			cout << i << ' ';
		}
		cout << endl;
	}
}
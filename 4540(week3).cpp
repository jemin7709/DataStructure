#include <iostream>
#include <string>
//#include "Queue.h"
using namespace std;

int main() {
	int t, m, n, target, goal;
	string item, temp;
	cin >> t;
	//Queue<string> queue;

	for (int i = 0; i < t; i++) {
		cin >> m >> n;
		string* q = new string[m];
		for (int j = 0; j < m; j++) {
			cin >> item;
			q[j] = item;
		}
		for (int k = 0; k < n; k++) {
			cin >> target >> goal;
			temp = q[target - 1];

			if (target > goal) {
				for (int x = target - 1; x > goal - 1; x--) {
					q[x] = q[x - 1];
				}
			}
			else {
				for (int x = target; x < goal; x++) {
					q[x - 1] = q[x];
				}
			}
			q[goal - 1] = temp;
			for (int z = 0; z < m; z++) {
				cout << q[z] << ' ';
			}
			cout << '\n';
		}
		/*for (int z = 0; z < m; z++) {
			cout << q[z] << ' ';
		}
		cout << '\n';*/
	}
	return 0;
}
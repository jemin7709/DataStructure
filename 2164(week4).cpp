#include <iostream>
//#include <queue>
#include "Queue.h"
using namespace std;

int main() {
	int n, answer;
	queue<int> q;
	cin >> n;
	for (int i = 0; i < n; i++) {
		q.push(i+1);
	}
	while (true) {
		if (q.size() == 1) {
			answer = q.front();
			q.pop();
			break;
		}
		q.pop();
		answer = q.front();
		q.pop();
		q.push(answer);
	}
	cout << answer << '\n';
	return 0;
}
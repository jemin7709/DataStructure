#include <iostream>
#include <queue>
//#include "Queue.h"
using namespace std;

int main() {
	int n;
	double score, bouble;
	
	cin >> n;
	queue<double> q;

	for (int i = 0; i < n; i++) {
		cin >> score;
		if (q.size() < 7) {
			q.push(score);
		}
		else {
			if(score)
		}
	}

	for (int i = 0; i < 7; i++) {
		cout.precision(3);
		cout << fixed << temp[i] << '\n';
	}

	return 0;
}
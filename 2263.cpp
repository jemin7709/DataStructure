#include <iostream>
#include <vector>
using namespace std;

void pre(vector<int>in, vector<int>post, int n) {
	if (in.empty() || post.empty()) {
		return;
	}
	if (in.size() == 1 || post.empty()) {
		cout << post[0] << ' ';
		return;
	}

	int root = post.back();
	int middle = -1;
	for (int i = 0; i < n; i++) {
		if (in[i] == root) {
			middle = i;
			break;
		}
	}

	cout << root << ' ';

	vector<int>leftin;
	vector<int>leftpost;
	for (int i = 0; i < middle; i++) {
		leftin.push_back(in[i]);
		leftpost.push_back(post[i]);
	}

	vector<int>rightin;
	vector<int>rightpost;
	for (int i = middle + 1; i < n; i++) {
		rightin.push_back(in[i]);
	}
	for (int i = middle; i < n - 1; i++) {
		rightpost.push_back(post[i]);
	}

	pre(leftin, leftpost, middle);
	pre(rightin, rightpost, n - middle - 1);
}

int main() {
	int n, temp;
	vector<int> in;
	vector<int> post;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		in.push_back(temp);
	}
	for (int i = 0; i < n; i++) {
		cin >> temp;
		post.push_back(temp);
	}
	pre(in, post, n);
	return 0;
}
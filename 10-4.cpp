#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum direction { MIN = 1, MAX = -1 };

class Heap {
private:
	vector<int>v;
	int size;
	int root;
	int direction;
public:
	Heap(int direction){
		v.push_back(0);
		this->size = 0;
		this->root = 1;
		this->direction = direction;
	}

	void swap(int idx1, int idx2) {
		v[0] = v[idx1];
		v[idx1] = v[idx2];
		v[idx2] = v[0];
	}

	void upHeap(int idx) {
		int paridx = idx / 2;
		if (paridx * direction > idx * direction) {

		}
	}
};
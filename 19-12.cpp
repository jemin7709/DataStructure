#include <iostream>
using namespace std;

enum { UP = 0, IT = 1, GA = -1 };
class Entry {
public:
	int key, value, status;
	Entry() {
		key = 0;
		value = 0;
		status = UP;
	}
	Entry(int key, int value) {
		this->key = 0;
		this->value = 0;
		status = IT;
	}
	void erase() {
		status = GA;
	}
};
class HashTable {
private:
	Entry* hashTable;
	int capa;
	int hashfunc(int key){
		return key % capa;
	}
public:
	int cur;
	HashTable(int capa) {
		cur = 1;
		this->capa = capa;
		hashTable = new Entry[capa];
	}
	int rotate(int start, int key) {
		int index = 0;
		if (key >= 0) {
			index = start + hashfunc(abs(key));
		}
		else {
			index = start + (capa - hashfunc(abs(key)));
		}
		if (index > capa) {
			index %= capa;
			if (index == 0) {
				index = capa;
			}
		}
		return index;
	}
	bool put(int index) {
		if (hashTable[index].status == IT) {
			return false;
		}
		else {
			hashTable[index] = Entry(index, index);
			return true;
		}
	}
};

int check(HashTable* A, HashTable* B, int count) {
	A->cur = A->rotate(A->cur, count);
	B->cur = B->rotate(B->cur, -count);
	if (A->put(A->cur)) {
		return A->cur;
	}
	else {
		A->cur = A->rotate(A->cur, B->cur);
		B->cur = B->rotate(B->cur, -B->cur);
		if (A->put(A->cur)) {
			return A->cur;
		}
		else {
			while (!A->put(A->cur)) {
				A->cur = A->rotate(A->cur, 1);
				B->cur = B->rotate(B->cur, -1);
			}
			return A->cur;
		}
	}
}

int main() {
	int t, a, b, c, n;
	cin >> t;
	while (t--) {
		cin >> a >> b >> c;
		HashTable* A = new HashTable(a);
		HashTable* B = new HashTable(b);
		while (c--) {
			cin >> n;
			cout << check(A, B, n) << " ";
		}
	}
	cout << endl;
}
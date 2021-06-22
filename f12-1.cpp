#include <iostream>
#include <string>
using namespace std;

enum { E = 0, F = 1, A = -1 };

class Item {
public:
	int key;
	string value;
	int status;
	Item() {
		this->key = 0;
		this->value = "";
		this->status = E;
	}
	Item(int key, string value) {
		this->key = key;
		this->value = value;
		this->status = F;
	}
	void erase() {
		this->status = A;
	}
};
class HashTable {
private:
	Item* hashTable;
	int capa;
	int hashfunc(int key) {
		return key % capa;
	}
public:
	HashTable(int capa) {
		this->capa = capa;
		hashTable = new Item[capa];
	}

	void put(int key, string value) {
		int index = hashfunc(key);
		int probing = 1;
		while (hashTable[index].status == F && probing <= capa) {
			index = hashfunc(index + 1);
			probing++;
		}
		if (probing > capa) {
			return;
		}
		hashTable[index] = Item(key, value);
		cout << probing << endl;
	}

	void erase(int key) {
		int index = hashfunc(key);
		int probing = 1;
		while (hashTable[index].status != E && probing <= capa) {
			if (hashTable[index].status == F && hashTable[index].key == key) {
				hashTable[index].erase();
				return;
			}
			index = hashfunc(index + 1);
			probing++;
		}
		cout << "None" << endl;
	}
	
	string find(int key) {
		int index = hashfunc(key);
		int probing = 1;
		while (hashTable[index].status != E && probing <= capa) {
			if (hashTable[index].status == F && hashTable[index].key == key) {
				return hashTable[index].value;
			}
			index = hashfunc(index + 1);
			probing++;
		}
		return "None";
	}
};

int main() {
	int t, n, k;
	string c, v;
	cin >> t >> n;
	HashTable h(n);
	while (t--) {
		cin >> c;
		if (c == "put") {
			cin >> k >> v;
			h.put(k, v);
		}
		else if (c == "erase") {
			cin >> k;
			h.erase(k);
		}
		else if (c == "find") {
			cin >> k;
			cout << h.find(k) << endl;
		}
	}
}
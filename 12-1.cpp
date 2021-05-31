#include <iostream>
#include <string>

#define NOITEM 0
#define ISITEM 1
#define AVAILABLE 2

using namespace std;

class Entry {
public:
	int key;
	string value;
	int valid;

	Entry() {
		this->key = 0;
		this->value = "";
		this->valid = NOITEM;
	}

	Entry(int key, string value) {
		this->key = key;
		this->value = value;
		this->valid = ISITEM;
	}

	void erase() {
		this->valid = AVAILABLE;
	}
};

class HashTable {
private:
	Entry* hashTable;
	int capacity;

	int hashFunc(int key) {
		return key % capacity;
	}
public:
	HashTable(int N) {
		this->capacity = N;
		hashTable = new Entry[capacity];
		return;
	}

	void put(int key, string value) {
		int index = hashFunc(key);
		int probing = 1;

		while (hashTable[index].valid == ISITEM && probing <= capacity) {
			index = hashFunc(index + 1);
			probing++;
		}

		if (probing > capacity) {
			return;
		}
		hashTable[index] = Entry(key, value);
		cout << probing << endl;
		return;
	}

	void erase(int key) {
		int index = hashFunc(key);
		int probing = 1;

		while (hashTable[index].valid != NOITEM && probing <= capacity) {
			if (hashTable[index].valid == ISITEM && hashTable[index].key == key) {
				hashTable[index].erase();
				return;
			}
			
			index = hashFunc(index + 1);
			probing++;
		}
		cout << "None" << endl;
		return;
	}

	string find(int key) {
		int index = hashFunc(key);
		int probing = 1;

		while (hashTable[index].valid != NOITEM && probing <= capacity) {
			if (hashTable[index].valid == ISITEM && hashTable[index].key == key) {
				return hashTable[index].value;
			}
			index = hashFunc(index + 1);
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
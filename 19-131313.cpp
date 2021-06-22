#include <iostream>
#include <string>
using namespace std;

enum { UP = 0, IT = 1, GA = -1 };
class Entry {
public:
	int key;
	string value;
	int status;
	Entry() {
		key = 0;
		value = "";
		status = UP;
	}
	Entry(int key, string value) {
		this->key = key;
		this->value = value;
		status = IT;
	}
	void erase() {
		status = GA;
	}
};
class HashTable {
private:
	Entry* hashtable;
	int capa;
	int hashNum;
	int hashfunc1(int key) {
		return key % capa;
	}
	int hashfunc2(int key) {
		return hashNum - (key % hashNum);
	}
public:
	HashTable(int capa, int hashNum) {
		hashtable = new Entry[capa];
		this->capa = capa;
		this->hashNum = hashNum;
	}
	void put(int key, string value) {
		int index = hashfunc1(key);
		int probing = 1;
		while (hashtable[index].status == IT && probing <= capa) {
			index = hashfunc1(index + hashfunc2(key));
			probing++;
		}
		hashtable[index] = Entry(key, value);
		cout << probing << endl;
	}
	void erase(int key) {
		int index = hashfunc1(key);
		int probing = 1;
		while (hashtable[index].status != UP && probing <= capa) {
			if (hashtable[index].status == IT && hashtable[index].key == key) {
				hashtable[index].erase();
				return;
			}
			index = hashfunc1(index + hashfunc2(key));
			probing++;
		}
		cout << "None" << endl;
	}
	string find(int key) {
		int index = hashfunc1(key);
		int probing = 1;
		while (hashtable[index].status != UP && probing <= capa) {
			if (hashtable[index].status == IT && hashtable[index].key == key) {
				return hashtable[index].value;
			}
			index = hashfunc1(index + hashfunc2(key));
			probing++;
		}
		return "None";
	}
};

int main() {
	int t, n, k, num;
	string c, v;
	cin >> t >> n >> num;
	HashTable h(n, num);
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
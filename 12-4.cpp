#include <iostream>
#include <string>
#define NOITEM 0 //�ش� ��Ʈ���� �ѹ��� ���Ե��� ���� ����
#define ISITEM 1 //�ش� ��Ʈ���� ���� ���Ե� ����
#define AVAILABLE 2 //�ش� ��Ʈ���� ������ ���� �־�����, ������ ������ ����
using namespace std;

struct Entry {
	int key; //��Ʈ���� key
	int value; //��Ʈ���� value
	int valid; //��Ʈ���� ���� ����

	Entry() { //�ʱ�ȭ �ϴ� ������ �Լ�
		key = 0;
		value = 0;
		valid = NOITEM;
	}
	Entry(int key, int value) { //�����ϴ� ������ �Լ�
		this->key = key;
		this->value = value;
		valid = ISITEM;
	}
	void erase() { //����
		valid = AVAILABLE;
	}
};

//���� ��������� �浹�� �����ϴ� �ؽ����̺�
class HashTable {
	Entry* hash_table; //entry�� �迭�� �ؽ����̺�
	int capacity; //�ؽ����̺��� ũ��

	int hash_func(int key) { //�ؽ��Լ�
		return key % capacity;
	}
public:
	int cur; //���� ����� ��� ��ȣ

	HashTable(int N) { //������ �Լ�
		cur = 1;
		capacity = N;
		hash_table = new Entry[capacity + 1]; //�����Ҵ����� �迭 ����
		return;
	}

	int rotate(int start, int key) { //start�� ȸ���� ������ ��� ��ȣ, key�� ȸ���� Ƚ��
		int index = 0; //�ؽð� =  ȸ�� �� �¹��� ��ȣ

		//�� key��ŭ ȸ��
		if (key >= 0) { //key�� ����� ��� �ݽð����
			index = start + hash_func(abs(key));
		}
		else { //key�� ������ ��� �ð���� 
			index = start + (capacity - hash_func(abs(key)));
		}
		// index�� ����� sz���� ũ�� %capacity
		if (index > capacity) {
			index %= capacity;
			if (index == 0) {
				index = capacity;
			}
		}
		return index;
	}

	bool put(int idx) { //��� ��ȣ idx�� ���� ����, �̹� �����ϸ� false
		if (hash_table[idx].valid == ISITEM) {
			return false;
		}
		else {
			hash_table[idx] = Entry(idx, idx);
			return true;
		}
	}
};

int check(HashTable* A, HashTable* B, int cnt) {
	//1. ���A�� �ݽð�������� cntĭ ȸ�� -> ���B �ð���� ȸ��
	A->cur = A->rotate(A->cur, cnt);
	B->cur = B->rotate(B->cur, -cnt);

	//1-1. A�� �¹��� ��Ͽ� ���˽�ƼĿ ���� �� ����(ISITEM)
	if (A->put(A->cur)) return A->cur;

	//1-2. �̹� ������ ��� 2�ܰ��
	else {
		//2. ���B�� �¹��� ��� ���ڸ�ŭ �ð���� ȸ�� -> ���A �ݽð���� ȸ��
		A->cur = A->rotate(A->cur, -B->cur);
		B->cur = B->rotate(B->cur, B->cur);

		//2-1. A�� �¹��� ��Ͽ� ���˽�ƼĿ ���� �� ���� (ISITEM)
		if (A->put(A->cur)) return A->cur;

		//2-2. �̹� ������ ��� 3�ܰ��
		else {
			//3. A�� �¹��� ��Ͽ� ��ƼĿ�� ���� ������ B�� �ݽð���� ȸ�� -> ���A �ð���� ȸ��
			//3-1. ��ƼĿ�� �������� ���� ��ϸ� ������ ��ƼĿ ������ ���� (ISITEM)
			while (A->put(A->cur) != true) {
				A->cur = A->rotate(A->cur, 1);
				B->cur = B->rotate(B->cur, -1);
			}
			return A->cur;
		}
	}
}
int main() {
	int c_count = 0; //��ɾ� ����
	int sz_A = 0; //��� A�� ��� ����
	int sz_B = 0; //��� B�� ��� ����
	int count = 0; //������ Ƚ��
	int num = 0; //ȸ�� Ƚ��

	cin >> c_count;
	for (int i = 0; i < c_count; i++) {
		cin >> sz_A >> sz_B >> count;

		//��� ����
		HashTable* A = new HashTable(sz_A);
		HashTable* B = new HashTable(sz_B);

		//����Ƚ�� ��ŭ ���� �ݺ�
		for (int j = 0; j < count; j++) {
			cin >> num;
			cout << check(A, B, num) << " ";
		}
		cout << "\n";

		//��� ����
		delete A;
		delete B;
	}
}
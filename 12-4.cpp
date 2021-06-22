#include <iostream>
#include <string>
#define NOITEM 0 //해당 엔트리에 한번도 삽입되지 않은 상태
#define ISITEM 1 //해당 엔트리에 값이 삽입된 상태
#define AVAILABLE 2 //해당 엔트리에 이전에 값이 있었으나, 지금은 지워진 상태
using namespace std;

struct Entry {
	int key; //엔트리의 key
	int value; //엔트리의 value
	int valid; //엔트리의 생태 변수

	Entry() { //초기화 하는 생성자 함수
		key = 0;
		value = 0;
		valid = NOITEM;
	}
	Entry(int key, int value) { //삽입하는 생성자 함수
		this->key = key;
		this->value = value;
		valid = ISITEM;
	}
	void erase() { //삭제
		valid = AVAILABLE;
	}
};

//선형 조사법으로 충돌을 관리하는 해시테이블
class HashTable {
	Entry* hash_table; //entry의 배열인 해시테이블
	int capacity; //해시테이블의 크기

	int hash_func(int key) { //해시함수
		return key % capacity;
	}
public:
	int cur; //현재 기어의 톱니 번호

	HashTable(int N) { //생성자 함수
		cur = 1;
		capacity = N;
		hash_table = new Entry[capacity + 1]; //동적할당으로 배열 생성
		return;
	}

	int rotate(int start, int key) { //start는 회전을 시작할 톱니 번호, key는 회전할 횟수
		int index = 0; //해시값 =  회전 후 맞물린 번호

		//기어를 key만큼 회전
		if (key >= 0) { //key가 양수일 경우 반시계방향
			index = start + hash_func(abs(key));
		}
		else { //key가 음수일 경우 시계방향 
			index = start + (capacity - hash_func(abs(key)));
		}
		// index가 기어의 sz보다 크면 %capacity
		if (index > capacity) {
			index %= capacity;
			if (index == 0) {
				index = capacity;
			}
		}
		return index;
	}

	bool put(int idx) { //톱니 번호 idx에 점검 부착, 이미 존재하면 false
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
	//1. 기어A를 반시계방향으로 cnt칸 회전 -> 기어B 시계방향 회전
	A->cur = A->rotate(A->cur, cnt);
	B->cur = B->rotate(B->cur, -cnt);

	//1-1. A의 맞물린 톱니에 점검스티커 부착 후 종료(ISITEM)
	if (A->put(A->cur)) return A->cur;

	//1-2. 이미 부착된 경우 2단계로
	else {
		//2. 기어B의 맞물린 톱니 숫자만큼 시계방향 회전 -> 기어A 반시계방향 회전
		A->cur = A->rotate(A->cur, -B->cur);
		B->cur = B->rotate(B->cur, B->cur);

		//2-1. A의 맞물린 톱니에 점검스티커 부착 후 종료 (ISITEM)
		if (A->put(A->cur)) return A->cur;

		//2-2. 이미 부착된 경우 3단계로
		else {
			//3. A의 맞물린 톱니에 스티커가 없을 때까지 B를 반시계방향 회전 -> 기어A 시계방향 회전
			//3-1. 스티커가 부착되지 않은 톱니를 만나면 스티커 부착후 종료 (ISITEM)
			while (A->put(A->cur) != true) {
				A->cur = A->rotate(A->cur, 1);
				B->cur = B->rotate(B->cur, -1);
			}
			return A->cur;
		}
	}
}
int main() {
	int c_count = 0; //명령어 개수
	int sz_A = 0; //기어 A의 톱니 개수
	int sz_B = 0; //기어 B의 톱니 개수
	int count = 0; //점검할 횟수
	int num = 0; //회전 횟수

	cin >> c_count;
	for (int i = 0; i < c_count; i++) {
		cin >> sz_A >> sz_B >> count;

		//기어 생성
		HashTable* A = new HashTable(sz_A);
		HashTable* B = new HashTable(sz_B);

		//점검횟수 만큼 점검 반복
		for (int j = 0; j < count; j++) {
			cin >> num;
			cout << check(A, B, num) << " ";
		}
		cout << "\n";

		//기어 삭제
		delete A;
		delete B;
	}
}
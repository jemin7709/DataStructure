#include <iostream>
#include <string>

using namespace std;

class Array {
private:
	int* arr;
	int size;
public:
	//Array 클래스 생성자
	Array(int Isize) {
		this->size = Isize;
		this->arr = new int[size];
		for (int i = 0; i < size; i++) {
			arr[i] = 0;
		}
	}

	//at 함수
	int at(int idx) {
		return arr[idx];
	}

	//add 함수
	void add(int idx, int value) {
		for (int i = size - 2; i >= idx; i--) {
			arr[i + 1] = arr[i];
		}
		arr[idx] = value;
	}

	//remove 함수
	void remove(int idx) {
		for (int i = idx + 1; i < size; i++) {
			arr[i - 1] = arr[i];
		}
		arr[size - 1] = 0;
	}

	//set함수
	int set(int idx, int value) {
		arr[idx] = value;
		return arr[idx];
	}

	//print 함수
	void print() {
		for (int i = 0; i < size; i++) {
			cout << arr[i] << " ";
		}
	}

	//find 함수
	int find_max() {
		int max = arr[0];
		for (int i = 1; i < size; i++) {
			if (max < arr[i]) {
				max = arr[i];
			}
		}
		return max;
	}
};



int main() {
	//변수 선언
	int N, T, idx, value;
	string command;

	//배열길이 N, 테스트케이스 T 입력
	cin >> N >> T;

	//N을 크기로 가지는 배열 생성
	Array arr(N);

	//T번만큼 command를 입력받아 command에 맞게 실행
	for (int i = 0; i < T; i++) {
		cin >> command;

		if (command == "at") {
			cin >> idx;
			cout << arr.at(idx) << endl;
		}
		if (command == "add") {
			cin >> idx >> value;
			arr.add(idx, value);
		}
		if (command == "remove") {
			cin >> idx;
			arr.remove(idx);
		}
		if (command == "set") {
			cin >> idx >> value;
			cout << arr.set(idx, value) << endl;
		}
		if (command == "print") {
			arr.print();
			cout << endl;
		}
		if (command == "find_max") {
			cout << arr.find_max() << endl;
		}
	}
}

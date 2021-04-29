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
		if (idx > size) {
			cout << "입력된 인덱스가 사이즈보다 큽니다" << endl;
		}
		return arr[idx];
	}

	//add 함수
	void add(int idx, int value) {
		for (int i = size - 2; i >= idx; i--) {
			arr[i + 1] = arr[i];
		}
		arr[idx] = value;
	}

	//set 함수
	void set(int idx, int value) {
		arr[idx] = value;
	}

	//print 함수
	void print() {
		for (int i = 0; i < size; i++) {
			cout << arr[i] << " ";
		}
	}
};

int main() {
	//변수 선언
	int T, N, D, tmp;
	string num;

	//테스트 케이스 T 입력
	cin >> T;

	//T번만큼 반복
	for (int i = 0; i < T; i++) {
		//배열의 길이 N과 시프트할 횟수 D 입력
		cin >> N >> D;

		//D가 배열의 길이보다 길다면 D = D-N의 값으로 할당
		if (N < D) {
			D = D - N;
		}

		//입력받을 N의 크기를 가진 배열과 임시로 값을 저장할 D의 크기를 가진 배열 생성 
		Array arr(N);
		Array temp(D);

		//입력받은 수열을 원 배열에 추가
		for (int i = 0; i < N; i++) {
			cin >> tmp;
			arr.add(i, tmp);
		}

		//시프트 시작점부터 원 배열의 끝까지 임시 배열로 복사
		for (int i = 0; i < D; i++) {
			temp.set(i, arr.at(N - D + i));
		}

		//원 배열의 처음부터 시프트 시작점 전까지 뒤에서부터 D만큼 시프트 하기
		for (int i = N - D - 1; i >= 0; i--) {
			arr.set(i + D, arr.at(i));
		}

		//임시 배열의 있던 값을 원래 배열의 처음으로 복사
		for (int i = 0; i < D; i++) {
			arr.set(i, temp.at(i));
		}
		//원 배열 프린트후 줄바꿈
		arr.print();
		cout << endl;
	}
}
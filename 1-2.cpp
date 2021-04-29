#include <iostream>
#include <string>

using namespace std;

class Array {
private:
	int* arr;
	int size;
public:
	//Array Ŭ���� ������
	Array(int Isize) {
		this->size = Isize;
		this->arr = new int[size];
		for (int i = 0; i < size; i++) {
			arr[i] = 0;
		}
	}

	//at �Լ�
	int at(int idx) {
		if (idx > size) {
			cout << "�Էµ� �ε����� ������� Ů�ϴ�" << endl;
		}
		return arr[idx];
	}

	//add �Լ�
	void add(int idx, int value) {
		for (int i = size - 2; i >= idx; i--) {
			arr[i + 1] = arr[i];
		}
		arr[idx] = value;
	}

	//set �Լ�
	void set(int idx, int value) {
		arr[idx] = value;
	}

	//print �Լ�
	void print() {
		for (int i = 0; i < size; i++) {
			cout << arr[i] << " ";
		}
	}
};

int main() {
	//���� ����
	int T, N, D, tmp;
	string num;

	//�׽�Ʈ ���̽� T �Է�
	cin >> T;

	//T����ŭ �ݺ�
	for (int i = 0; i < T; i++) {
		//�迭�� ���� N�� ����Ʈ�� Ƚ�� D �Է�
		cin >> N >> D;

		//D�� �迭�� ���̺��� ��ٸ� D = D-N�� ������ �Ҵ�
		if (N < D) {
			D = D - N;
		}

		//�Է¹��� N�� ũ�⸦ ���� �迭�� �ӽ÷� ���� ������ D�� ũ�⸦ ���� �迭 ���� 
		Array arr(N);
		Array temp(D);

		//�Է¹��� ������ �� �迭�� �߰�
		for (int i = 0; i < N; i++) {
			cin >> tmp;
			arr.add(i, tmp);
		}

		//����Ʈ ���������� �� �迭�� ������ �ӽ� �迭�� ����
		for (int i = 0; i < D; i++) {
			temp.set(i, arr.at(N - D + i));
		}

		//�� �迭�� ó������ ����Ʈ ������ ������ �ڿ������� D��ŭ ����Ʈ �ϱ�
		for (int i = N - D - 1; i >= 0; i--) {
			arr.set(i + D, arr.at(i));
		}

		//�ӽ� �迭�� �ִ� ���� ���� �迭�� ó������ ����
		for (int i = 0; i < D; i++) {
			arr.set(i, temp.at(i));
		}
		//�� �迭 ����Ʈ�� �ٹٲ�
		arr.print();
		cout << endl;
	}
}
#include <iostream>
#include <string>
using namespace std;

class Node {
private:
	int data;
	Node* next;
	friend class queue;
};

//QueueŬ����
class queue {
private:
	Node* Front; // �� ���� ����Ű�� ������ ������ ����
	Node* Rear; // �� �ڸ� ����Ű�� ������ �߰��� ����
	int Size; // ť�� ũ��
public:
	queue() :Front(nullptr), Rear(nullptr), Size(0) {}; // front�� rear�� nullptr�� Size�� 0���� �ʱ�ȭ
	//size �Լ� 
	int size() {
		return Size;
	}

	//empty �Լ�
	bool empty() {
		return Size == 0;
	}

	void setfront(int value) {
		Front->data = value;
	}

	// front �Լ�
	int  front() {
		if (empty()) {
			cout << "Empty" << endl;
			return 0;
		}
		else {
			return Front->data; // ���� �տ����� ����
		}
	}

	// rear �Լ�
	int back() {
		if (empty()) {
			cout << "Empty" << endl;
			return 0;
		}
		else {
			return Rear->data; // ���� �ڿ����� ����
		}
	}

	// push �Լ�
	void push(int value) {
		Node* node = new Node; // �� ��带 ����
		node->data = value; // ��忡 �Ҵ�
		node->next = nullptr;

		if (empty()) { // Queue�� ����ִ°��
			Front = node;
			Rear = node;
		}
		else { // Queue�� ������� ���� ���
			Rear->next = node;
			Rear = node;
		}
		Size++;
	}

	// pop �Լ�
	int pop() {
		if (empty()) {
			return 0;
		}
		Node* cur = Front; // �޸� ������ �����Ϳ� front�� �ּҸ� �Ҵ�
		int data = Front->data;
		Front = Front->next; // front�� ��ĭ ������ �Ű��ֱ�

		Size--;
		delete cur; // �޸� ����
		return data;
	}
};

int main() {
	int t, n;
	cin >> t;

	while (t--) { // t�� �ݺ�
		cin >> n;

		int temp = 0, p1p = 0, p2p = 0; // ���� �ӽ� ������ temp�� p1����Ʈ p1p, p2����Ʈ p2p ����
		queue p1, p2; // p1, p2 ť ����

		for (int j = 0; j < n; j++) { // p1 �� �Է�
			cin >> temp;
			p1.push(temp);
		}

		for (int j = 0; j < n; j++) { // p2 �� �Է�
			cin >> temp;
			p2.push(temp);
		}

		while (!p1.empty()) { // p1�̳� p2�� ũ��� �����Ƿ� �ƹ��ų� ���
			temp = p1.pop() - p2.pop(); // temp�� p1 - p2�� ��
			if (temp > 0) { // temp�� ����� p1>p2
				if (!p1.empty()) { // p1�� �������� �ƴ϶��
					p1.setfront(p1.front() + temp); // ���� p1�� ������ ���� ü�� �����ֱ�
				}
				p1p++; // p1����Ʈ�� +1
			}
			else if (temp < 0) { // temp�� ������ p2>p1
				if (!p2.empty()) { // p2�� �������� �ƴ϶�� 
					p2.setfront(p2.front() + abs(temp)); // ���� p2�� ������ ���� ü�� �����ֱ�
				}
				p2p++; // p2����Ʈ�� +1
			}
		} // �����ϰ�쿡�� �׳� ������

		if (p1p > p2p) { // p1p>p2p�� ��� 1 ���
			cout << "1" << endl;
		}
		else if (p2p > p1p) { // p2p>p1p�� ��� 2 ���
			cout << "2" << endl;
		}
		else { // �����ϰ�� 0 ���
			cout << "0" << endl;
		}
	}

	return 0;
}
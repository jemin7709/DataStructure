#include <iostream>
//#include "CircularQueue.h"
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node* prev;
};

//����QueueŬ����
class Cqueue {
private:

public:
	Node* Front; // �� ���� ����Ű�� ������ ������ ����
	Node* Rear; // �� �ڸ� ����Ű�� ������ �߰��� ����
	int Size; // ť�� ũ��
	Cqueue() :Front(NULL), Rear(NULL), Size(0) {}; // front�� rear�� nullptr�� Size�� 0���� �ʱ�ȭ

	//size �Լ� 
	int size() {
		return Size;
	}

	//empty �Լ�
	bool empty() {
		return Size == 0;
	}

	// front �Լ�
	int front() {
		if (empty()) {
			return -1;
		}
		return Front->data; // ���� �տ����� ����
	}

	// rear �Լ�
	int back() {
		if (empty()) {
			return -1;
		}
		return Rear->data; // ���� �ڿ����� ����
	}

	// push �Լ�
	void push(int value) {
		Node* node = new Node; // �� ��带 ����
		node->data = value; // ��忡 �Ҵ�
		node->next = NULL;
		node->prev = NULL;

		if (empty()) { // Queue�� ����ִ°��
			Front = node;
			Rear = node;
		}
		else { // Queue�� ������� ���� ���
			node->next = Rear;
			Rear->prev = node;
			Rear = node;
			Rear->prev = Front;
			Front->next = Rear;
		}
		Size++;
	}

	// pop �Լ�
	int pop() {
		if (empty()) {
			return -1;
		}
		Node* cur = Front; // �޸� ������ �����Ϳ� front�� �ּҸ� �Ҵ�

		Front = Front->prev; // front�� ��ĭ ������ �Ű��ֱ�
		Rear->prev = Front;
		Front->next = Rear;

		Size--;
		delete cur; // �޸� ����
		return 1;
	}

	void left() {
		Rear = Rear->prev;
		Front = Front->prev;
	}

	void right() {
		Front = Front->next;
		Rear = Rear->next;
	}

};

int main() {
	int n, m, target, target_index = 0, count = 0;
	Cqueue cq;
	cin >> n >> m;

	for (int i = 0; i < n; i++) { // n��ŭ �־��ֱ�
		cq.push(i + 1);
	}
	
	for (int i = 0; i < m; i++) {
		cin >> target;
		Node* cur = cq.Front;

		for (int j = 0; j < cq.size(); j++) { // �ε��� Ȯ�ο�
			if (cur->data == target) { // cur�� target�� ���ٸ�
				target_index = j; // �׶��� �ε����� target_index�� �־��ְ�
				break; // ���߱�
			}
			if (cur != NULL) { // �ƴ϶��
				cur = cur->next; // ���� �ε����� �̵�
			}
		}

		if (target_index < cq.size() - target_index) { // target_index�� ť�� ũ�� - target_index���� �۴ٸ�
			while (cq.front() != target) { // front�� target�� ������������
				cq.right(); // cq�� ���������� �̷�
				count++;
			}
			cq.pop(); // �� �̷�ٸ� pop���ֱ�
		}
		else { // target_index�� ť�� ũ�� - target_index���� ũ�ٸ�
			while (cq.front() != target) { // front�� target�� ������������
				cq.left(); // cq�� �������� �̷�
				count++;
			}
			cq.pop(); // �� �̷�ٸ� pop ���ֱ�
		}
	}
	cout << count; // �̷궧���� ������� count�� ����ϱ�
	return 0;
}
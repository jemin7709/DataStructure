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

	// front �Լ�
	void front() {
		if (empty()) {
			cout << "Empty" << endl;;
		}
		else {
			cout << Front->data << endl; // ���� �տ����� ����
		}
	}

	// rear �Լ�
	void back() {
		if (empty()) {
			cout << "Empty" << endl;
		}
		else {
			cout << Rear->data << endl; // ���� �ڿ����� ����
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
			cout << "Empty" << endl;
			return 0;
		}
		Node* cur = Front; // �޸� ������ �����Ϳ� front�� �ּҸ� �Ҵ�
		int data = Front->data;
		Front = Front->next; // front�� ��ĭ ������ �Ű��ֱ�

		Size--;
		delete cur; // �޸� ����
		cout << data << endl;
		return 0;
	}
};

int main() {
	int N, data;
	string command;

	cin >> N;
	queue q;

	for (int i = 0; i < N; i++) {
		cin >> command;
		if (command == "size") {
			cout << q.size() << endl;
		}
		else if (command == "isEmpty") {
			if (q.empty()) {
				cout << "True" << endl;
			}
			else {
				cout << "False" << endl;
			}
		}
		else if (command == "front") {
			q.front();
		}
		else if (command == "rear") {
			q.back();
		}
		else if (command == "enqueue") {
			cin >> data;
			q.push(data);
		}
		else if (command == "dequeue") {
			q.pop();
		}
	}
}
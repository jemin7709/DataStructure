#pragma once

template <typename T>
class Node {
private:
	T data;
	Node<T>* next;
	template <typename T> friend class queue;
};

//QueueŬ����
template <typename T>
class queue {
private:
	Node<T>* Front; // �� ���� ����Ű�� ������ ������ ����
	Node<T>* Rear; // �� �ڸ� ����Ű�� ������ �߰��� ����
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
	T front() {
		if (empty()) {
			return -1;
		}
		return Front->data; // ���� �տ����� ����
	}
	
	// rear �Լ�
	T back() {
		if (empty()) {
			return -1;
		}
		return Rear->data; // ���� �ڿ����� ����
	}

	// push �Լ�
	void push(T value) {
		Node<T>* node = new Node<T>; // �� ��带 ����
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
			return -1;
		}
		Node<T>* cur = Front; // �޸� ������ �����Ϳ� front�� �ּҸ� �Ҵ�

		Front = Front->next; // front�� ��ĭ ������ �Ű��ֱ�

		Size--;
		delete cur; // �޸� ����
		return 1;
	}
};
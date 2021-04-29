#pragma once

template <typename T>
class Node {
public:
	T data;
	Node<T>* next;
	Node<T>* prev;
	template <typename T> friend class Cqueue;
};

//QueueŬ����
template <typename T>
class Cqueue {
private:
	
public:
	Node<T>* Front; // �� ���� ����Ű�� ������ ������ ����
	Node<T>* Rear; // �� �ڸ� ����Ű�� ������ �߰��� ����
	int Size; // ť�� ũ��
	Cqueue() :Front(nullptr), Rear(nullptr), Size(0) {}; // front�� rear�� nullptr�� Size�� 0���� �ʱ�ȭ

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
		node->prev = nullptr;

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
		Node<T>* cur = Front; // �޸� ������ �����Ϳ� front�� �ּҸ� �Ҵ�

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

	int* get_Front() {
		return Front;
	}
};
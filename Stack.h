#pragma once
class Node {
private:
	int data;
	Node* next;
	friend class Stack;
};

//StackŬ����
class Stack {
private:
	Node* head; // �� ���� ����Ű�� ������
	int Size; // ������ ũ��
public:
	Stack() :head(nullptr), Size(0) {}; // head�� NULL�� Size�� 0���� �ʱ�ȭ

	//size �Լ� 
	int size() {
		return Size;
	}

	//empty �Լ�
	bool empty() {
		return Size == 0;
	}

	// top �Լ�
	int top() {
		if (empty()) {
			return -1;
		}
		return head->data; // ���� �������� ����
	}

	// push �Լ�
	void push(int value) {
		Node* node = new Node; // �� ��带 ����
		node->data = value; // ��忡 �Ҵ�
		node->next = nullptr;

		if (empty()) { // Stack�� ����ִ°��
			head = node;
		}
		else { // Stack�� ������� ���� ���
			node->next = head;
			head = node;
		}
		Size++;
	}

	// pop �Լ�
	int pop() {
		if (empty()) {
			return -1;
		}
		Node* cur = head; // �޸� ������ �����Ϳ� ���� �޸��� �ּҸ� �Ҵ�
		int temp; // �� ����� int ����

		head = head->next; // head�� ��ĭ �Ʒ��� �Ű��ֱ�
		temp = cur->data; // ���� �޸��� ���� int������ �־��ֱ�

		Size--;
		delete cur; // �޸� ����
		return temp; // ����� �� ��ȯ
	}
};
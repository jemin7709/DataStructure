#include <iostream>
#include <string>
using namespace std;

// ��� Ŭ����(Stack Ŭ������ friend �Լ��� ����)
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
	Stack() :head(NULL), Size(0) {}; // head�� NULL�� Size�� 0���� �ʱ�ȭ

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
			cout << "Empty Error" << endl;
			return -1;
		}
		return head->data; // ���� �������� ����
	}

	// push �Լ�
	void push(int value) {
		Node* node = new Node; // �� ��带 ����
		node->data = value; // ��忡 �Ҵ�
		node->next = NULL;

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
			cout << "Empty Error" << endl;
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

	// print �Լ� (�� �־�� �ϴ°� �ƴ�)
	void print() {
		if (empty()) {
			cout << "Empty Error" << endl;
		}
		Node* cur = head; // ó������ ����
		while (cur != NULL) { // NULL ������ -> ������ ������
			cout << cur->data << endl; // ���� �����Ͱ� ����Ű���ִ� ����� ������ ���
			cur = cur->next; // ���� �����͸� ���� ���� �ٲٱ�
		}
	}
};

int main() {
	int t, size, temp1 = -1, temp2 = -1;
	string me; // �Է¹��� ����
	Stack stack;

	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> me; // ���� �Է�
		size = me.size(); // ������ string ũ�⸦ size�� �Ҵ�
		for (int j = 0; j < size; j++) {
			if (me[j] == '+') { // ������ ������ +�϶�
				temp2 = stack.pop();
				temp1 = stack.pop();
				stack.push(temp1 + temp2);
			}
			else if (me[j] == '-') { // ������ ������ -�϶�
				temp2 = stack.pop();
				temp1 = stack.pop();
				stack.push(temp1 - temp2);
			}
			else if (me[j] == '*') { // ������ ������ *�϶�
				temp2 = stack.pop();
				temp1 = stack.pop();
				stack.push(temp1 * temp2);
			}
			else { // ������ �����϶�
				stack.push(me[j] - '0');
			}
		}

		temp1, temp2 = stack.pop(); // ������ ������� temp1, temp2�� �Ҵ�
		temp1 = abs(temp1); // temp1�� ����� ������ֱ�

		while (temp1 >= 10) { // temp1�� 10���� ũ�ų� ���ٸ�
<<<<<<< HEAD
			temp1 = temp1 % 10; // temp1�� temp1�� mod10���� ���Ҵ�(1�� �ڸ��� ����������)
=======
			temp1 = temp1 % 10; // temp1�� temp1�� mod10���� �����ֱ�(1�� �ڸ��� ����������)
>>>>>>> 748c32bee8e8b305ea82cd789c39ffd4de711be7
		}

		if (temp2 < 0) { // ������ ������� �������ٸ�
			temp1 *= -1; // 1�� �ڸ��� ���� ����� -1 �����ֱ�
		}
<<<<<<< HEAD

=======
>>>>>>> 748c32bee8e8b305ea82cd789c39ffd4de711be7
		cout << temp1 << endl; // ���� ����� ���
	}
}
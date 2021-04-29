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
	int n, num, count = 1; // n, ����, ���������� �Է¹��� ���� ����
	string answer; // ������ �Է¹��� ���� ����
	Stack stack; // ���������� ������ Stack ����

	cin >> n; // n �Է�

	for (int i = 0; i < n; i++) { // n����ŭ �ݺ�
		cin >> num; // ������ �ϳ��� �Է�
		
		// ����ó���κ�
		if (stack.top() < num && num < count) { // ���� �Է¹��� ���� ������������ ������ ������ �ִ񰪺��� ũ�ٸ�
			answer = "NO"; // �Ұ����� ����̹Ƿ� NO ���
			break; // for�� Ż��
		}
		
		// ���κ�
		while (num >= count) { // �Է¹��� ���� ������������ ũ�ų� ���ٸ�
			stack.push(count++); // Stack�� ���������� push�ϰ�
			answer += '+'; // ���信 + �߰�
		}
		while (num <= stack.top()) { // �Է¹������� ���������� �ִ밪���� �۰ų� ���ٸ�
			stack.pop(); // �ִ� ����
			answer += '-'; // ���信 -�߰�
		}
	}

	if (answer == "NO") { // ������ NO���
		cout << "NO"; // NO���
	}
	else{ // ������ NO�� �ƴ϶��
		for (char elem : answer) { // ������ �� ���ھ� ���
			cout << elem << '\n'; // ����ӵ��� ������ �ϱ� ���� endl��� \n���
		}
	}

	return 0;
}
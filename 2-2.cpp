#include <iostream>
#include <string>

using namespace std;

// ��� Ŭ����
class Node {
public:
	int data;
	Node* next;
	Node* prev;
};

class LikedList :public Node { // ��� Ŭ���� ���
private:
	Node* header;
	Node* trailer;
	int size = 0;
public:
	LikedList() : header(NULL), trailer(NULL) {} // �����ڷ� head�� tail�� NULL�� �ʱ�ȭ

	// Size �Լ�
	int Size() {
		return size;
	}

	// Empty �Լ�
	bool Empty() {
		if (header == NULL && trailer == NULL) {
			return true;
		}
		else {
			return false;
		}
	}

	// Print �Լ�
	void Print() {
		if (Empty()) { // ����ִ��� Ȯ��
			cout << "empty" << endl;
		}
		else {
			Node* cur = header;
			while (cur->next != NULL) { // ������ ������ NULL�� �ƴҰ�� -> trailer ������
				cout << cur->data << ' ';
				cur = cur->next;
			}
			cout << cur->data << endl; // trailer�϶�
		}
	}

	void Print_reverse() {
		if (Empty()) { // ����ִ��� Ȯ��
			cout << "empty" << endl;
		}
		else {
			Node* cur = trailer;
			while (cur->prev != NULL) {
				cout << cur->data << ' ';
				cur = cur->prev;
			}
			cout << cur->data << endl;
		}
	}

	//append �Լ�
	void Append(int value) {
		Node* node = new Node; // �� ��� �����Ҵ�

		//����� ���� �����ּ� �Ҵ�
		node->data = value;
		node->next = NULL;
		node->prev = NULL;

		if (header == NULL) { // node�� ù��° ���ϰ�� header�� trailer ��� node
			header = node;
			trailer = node;
		}
		else { // node�� ù��° ���� �ƴҰ�� trailer�� next�� node�� ���ϰ� �ϰ� node�� prev�� trailer�� ���ϰ� �ϰ� trailer�� node�� �Ҵ�
			trailer->next = node;
			node->prev = trailer;
			trailer = node;
			trailer->next = NULL;
		}

		size++; // ����Ʈ�� ����� +1���ֱ�
	}

	// Delete �Լ�
	int Delete(int idx) { 
		int temp = -1;
		int middle = Size() / 2; //����Ʈ�� �߰� �ε��� 
		Node* cur;
		Node* pre;

		if (Empty() || Size() <= idx) {
			return -1;
		}
		else if (idx == 0) { // ù ���� �����Ҷ�
			if (size == 1) { // ��尡 �ϳ��� �������
				cur = header;
				temp = cur->data;
				header = NULL;
				trailer = NULL;
				delete cur;
			}
			else { // ��尡 �ϳ� �̻��� ���
				cur = header;
				temp = cur->data;
				header = header->next;
				delete cur;
			}
			size--; // ����Ʈ�� ũ�⸦ -1 ���ֱ�
		}
		// ���� �ӵ��� ������ ���� �ε����� ����Ʈ�� �߰������� �۰ų� ������ �տ������� ����
		else if (idx <= middle) { // �ε����� ����Ʈ�� �߰������� �۰ų� ���� ���
			pre = cur = header;
			for (int i = 0; i < idx; i++) { // �տ������� �ε������� �̵�
				pre = cur;
				cur = cur->next;
			}
			temp = cur->data;
			pre->next = cur->next; // pre�� next�� cur�� next�� ����
			if (cur == trailer) { // cur�� trailer�� ���
				trailer = pre; // trailer�� pre�� �Ҵ�
			}
			else { // �ƴҰ�� 
				(cur->next)->prev = pre; // cur�� next�� prev�� pre�� ����
			}
			delete cur; // cur ����
			size--; // ����Ʈ�� ����� -1 ���ֱ�
		}
		// ����Ʈ�� �߰������� ũ�� �ڿ������� ����
		else if (idx > middle) { // �ε����� ����Ʈ�� �߰������� ū ���
			pre = cur = trailer;
			for (int i = Size(); i > idx; i--) { // �ڿ������� �ε������� �̵�
				cur = pre;
				pre = pre->prev;
			}
			temp = cur->data;
			pre->next = cur->next; // pre�� next�� cur�� next�� ����
			if (cur == trailer) { // cur�� trailer�� ���
				trailer = pre; // trailer�� pre�� �Ҵ�
			}
			else { // �ƴҰ��
				(cur->next)->prev = pre; // cur�� next�� prev�� pre�� ����
			}
			delete cur; // cur ����
			size--; // ����Ʈ�� ����� -1 ���ֱ�
		}
		return temp; // ������ �� temp ����
	}

	//Max �Լ�
	void Max() {
		int max;
		if (Empty()) { // ����Ʈ�� ����ִ� ���
			cout << "empty" << endl;
		}
		else {
			Node* cur = header->next; // ó������
			max = header->data;
			while (cur != NULL) { // ����������
				if (cur->data > max) { // ���� �����Ͱ� max���� ũ�ٸ�
					max = cur->data; // max �ٲٱ�
				}
				cur = cur->next;
			}
			cout << max << endl; // max ���
		}
	}
};

int main() {
	int M, idx, value;
	string command;
	LikedList List;
	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> command;
		if (command == "Print") {
			List.Print();
		}
		if (command == "Print_reverse") {
			List.Print_reverse();
		}
		if (command == "Append") {
			cin >> value;
			List.Append(value);
			List.Print();
		}
		if (command == "Delete") {
			cin >> idx;
			cout << List.Delete(idx) << endl;
		}
		if (command == "Max") {
			List.Max();
		}
	}
	return 0;
}
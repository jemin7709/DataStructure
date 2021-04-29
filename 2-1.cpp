#include <iostream>
#include <string>

using namespace std;

// ��� Ŭ����
class Node {
public:
	int data;
	Node* next;
};

class LikedList :public Node { // ��� Ŭ���� ���
private:
	Node* head;
	Node* tail;
	int size = 0;
public:
	LikedList() : head(NULL), tail(NULL) {} // �����ڷ� head�� tail�� NULL�� �ʱ�ȭ

	// Size �Լ�
	int Size() {
		return size;
	}

	// Empty �Լ�
	bool Empty() {
		if (head == NULL && tail == NULL) {
			return true;
		}
		else {
			return false;
		}
	}

	// Print �Լ�
	void Print() {
		if (Empty()) {
			cout << "empty" << endl;
		}
		else {
			Node* cur = head;
			while (cur->next != NULL) { // ������ ������ NULL�� �ƴҰ�� -> tail ������
				cout << cur->data << ' ';
				cur = cur->next;
			}
			cout << cur->data << endl; // tail�϶�
		}
	}

	// append �Լ�
	void Append(int value) {
		Node* node = new Node; // �� ��� �����Ҵ�

		//����� ���� �����ּ� �Ҵ�
		node->data = value;
		node->next = NULL;

		if (head == NULL) { // node�� ù��° ���ϰ�� head�� trailer ��� node
			head = node;
			tail = node;
		}
		else { // node�� ù��° ���� �ƴҰ�� tail�� ������ node�� ���ϰ� �ϰ� tail�� node�� �Ҵ�
			tail->next = node;
			tail = node;
		}

		size++; // ����Ʈ�� ����� +1���ֱ�
	}

	// Delete �Լ�
	int Delete(int idx) {
		int temp;
		Node* cur;
		Node* pre;

		if (Empty() || Size() <= idx) {
			return -1;
		}
		else if (idx == 0) { // ù��° �����͸� ����� ���
			if (size == 1) {
				cur = head;
				temp = cur->data; 
				head = NULL; // head�� NULL�� ����Ű�� ��
				tail = NULL; // tail�� NULL�� ����Ű�� ��
				delete cur; //ù ��� ����
			}
			else {
				cur = head;
				temp = cur->data;
				head = head->next; // head�� ��ĭ ������ �ű��
				delete cur; // ù ��� ����
			}
			size--; // ����Ʈ�� ����� -1 ���ֱ�
		}
		else { // ù��°�� �ƴ� �����͸� ����� ���
			pre = cur = head;
			for (int i = 0; i < idx; i++) { // �Է¹��� �ε������� �� ���, ���� ��� �ű��
				pre = cur;
				cur = cur->next;
			}
			temp = cur->data; // ���簪�� temp�� ����
			pre->next = cur->next; // �� ����� next�� ���� ����� ���� ���� ����
			if (cur == tail) { // if ���� ��尡 tail�̶��
				tail = pre; // tail�� �� ���� �ٲٱ�
			}
			delete cur; //���� ��� �����
			size--; // ����Ʈ�� ����� -1 ���ֱ�
		}
		return temp; // temp �������ֱ�
	}

	// Insert �Լ�
	int Insert(int idx, int value) {
		Node* node = new Node; // �� ��� ����
		node->data = value;
		node->next = NULL;

		Node* pre;
		Node* cur;

		if (idx<0 || idx>Size()) { //�ε����� 0���� �۰ų� ����Ʈ�� ũ�⸦ ����°��
			cout << "Index Error" << endl;
			return -1;
		}
		else if (idx == 0) { // ��带 ó���� �����ϴ� ���
			if (Empty()) { // ����Ʈ�� ����ִ� ���
				head = node;
				tail = node;
			}
			else { // �ƴѰ��
				node->next = head; //����� next�� head�� �ٲٱ�
				head = node; // head�� ���� �ٲٱ�
			}
			size++; // ����Ʈ�� ����� +1 ���ֱ�
		}
		else if (idx == Size()) { // ����Ʈ�� ���� �߰��ϴ� ���
			Append(value); // Append �Լ� ���
		}
		else { // �߰��� �����ϴ� ���
			pre = cur = head;
			for (int i = 0; i < idx; i++) { // �ε��� ��ġ���� �̵�
				pre = cur;
				cur = cur->next;
			}
			pre->next = node; // pre�� next�� ��带 ����Ű�� �ϱ�
			node->next = cur; // ����� next�� cur�� ����Ű�� �ϱ�
			size++; // ����Ʈ�� ����� +1 ���ֱ�
		}
		return 0;
	}

	// Sum �Լ�
	int Sum() {
		int sum = 0;
		if (!Empty()) { // ����Ʈ�� ������� �ʴٸ�
			Node* cur = head; // ����Ʈ�� ó������
			while (cur!= NULL) { // ����Ʈ�� ������
				sum = sum + cur->data; // ���� sum�� �����ֱ�
				cur = cur->next; // ��ĭ�� ������ �ű��
			}
		}
		return sum; // sum ����
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
		if (command == "Append") {
			cin >> value;
			List.Append(value);
			List.Print();
		}
		if (command == "Delete") {
			cin >> idx;
			cout << List.Delete(idx) << endl;
		}
		if (command == "Insert") {
			cin >> idx >> value;
			if (List.Insert(idx, value) == 0) {
				List.Print();
			}
		}
		if (command == "Sum") {
			cout << List.Sum() << endl;
		}
	}
	return 0;
}
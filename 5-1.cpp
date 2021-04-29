#include <iostream>
#include <string>
using namespace std;

class List { // List Ŭ����(���߿��� ����Ʈ)
private:
	struct Node { // Node ����ü
		int e;
		Node* prev;
		Node* next;
	};

public:
	class Iterator { // Iterator Ŭ����
	private:
		Node* v; // ����� ������ v
		Iterator(Node* u) { // ����� �����͸� �޴� ������
			v = u;
		}
	public:
		int& operator*() { // * ������ �����ε�
			return v->e; // iterator�� ���� ����
		}
		bool operator==(const Iterator& p)const { // == ������ �����ε�
			return v == p.v; // iterator������ �ּҰ� ������ Ȯ��
		}
		bool operator!=(const Iterator& p)const { // != ������ �����ε�
			return v != p.v; // iterator������ �ּҰ� �ٸ��� Ȯ��
		}
		Iterator& operator++() { // ++ ������ �����ε�(����)
			v = v->next; // iterator�� �ּҸ� next�� ����
			return *this; // iterator ����
		}
		Iterator& operator--() { // -- ������ �����ε�(����)
			v = v->prev; // iterator�� �ּҸ� prev�� ����
			return *this; // iterator ����
		}
		friend class List; // List Ŭ������ friend ����
	};
private:
	int n; // List�� ������ n
	Node* header; // header ������
	Node* trailer; // trailer ������
public:
	List() { // ������
		n = 0;
		header = new Node;
		trailer = new Node;
		header->next = trailer;
		trailer->prev = header;
	}
	int size() const { // size �Լ�
		return n;
	}
	bool empty() const { // empty �Լ�
		return size() == 0;
	}
	Iterator begin() const { // begin �Լ� 
		return Iterator(header->next); // iterator�� begin���� ��ġ��Ų��
	}
	Iterator end() const { // end �Լ�
		return Iterator(trailer); // iterator�� end�� ��ġ��Ų��
	}
	void insertFront(const int& e) { // insertFront �Լ�
		insert(begin(), e);
	}
	void insertBack(const int& e) { // insertBack �Լ�
		insert(end(), e);
	}
	void insert(const Iterator& p, const int& e) { // insert �Լ�
		Node* w = p.v; // insert �ϰ���� �ּҸ� ������ w�� �Ҵ�
		Node* u = w->prev; // insert �ϰ���� �ּ��� �� �ּҸ� u�� �Ҵ�
		Node* v = new Node; // ������ ����� �� ��� ����
		v->e = e; // �� ����� �����͸� �Է°� e�� �Ҵ�
		v->next = w; // �� ����� next�� w�� ����
		w->prev = v; // w�� prev�� �� ���� ����
		v->prev = u; // �� ����� prev�� u�� ����
		u->next = v; // u�� next�� �� ���� ����
		this->n++; // List�� ũ�⸦ +1
	}
	void eraseFront() { // eraseFront �Լ�
		erase(begin());
	}
	void eraseBack() { // eraseBack �Լ�
		erase(--end()); // end�� ����ֱ⶧���� end ���� ��带 ����
	}
	void erase(const Iterator& p) { // erase �Լ�
		Node* v = p.v; // ���� ����� �ּҸ� v�� �Ҵ�
		Node* w = v->next; // v�� ���� ��� �ּҸ� w�� �Ҵ�
		Node* u = v->prev; // v�� �� ��� �ּҸ� u�� �Ҵ�
		u->next = w; // u�� next�� w�� ����
		w->prev = u; // w�� prev�� u�� ����
		delete v; // ��带 ����
		this->n--; // List�� ũ�⸦ -1
	}
	Iterator atIndex(int i) const { // atIndex �Լ�
		Iterator p = begin(); // iterator�� begin���� ����
		for (int j = 0; j < i; j++) { // index i���� iterator�� ������ �Ű��ֱ�
			++p;
		}
		return p; // index i�� �ּ� p ��ȯ
	}
	int indexOf(const Iterator& p) const { // indexOf �Լ�
		Iterator q = begin(); // iterator q�� begin���� ����
		int j = 0; // index ����� j���� 
		while (q != p) { // q�� p�� ������������ q�� �Ű��ְ� j+1 ���ֱ�
			++q;
			++j;
		}
		return j++; // j-1�� ���¿����Ƿ� ��ȯ�ÿ� +1 ���ֱ�
	}
	void print() { // print �Լ�
		Iterator iter = this->begin(); // iterator�� begin���� ����
		while (iter != this->end()) { // iterator�� end�� �ƴҶ�����
			cout << *iter << ' '; // iterator�� �ּҿ� �ִ� ���� ���
			++iter; // iterator�� ������ �Ű��ֱ�
		}
	}
	int find(int e) { // find �Լ�
		Iterator iter = this->begin(); // iterator�� begin���� ����
		for (int i = 0; i < n; i++) { // List�� ������
			if (*iter == e) { // iterator�� �ּҿ� �ִ� ���� ���� ã�� ���̶��
				return i; // �׶��� index�� ��ȯ
			}
			++iter; // iterator�� ������ �Ű��ֱ�
		}
		return -1; // ���ٸ� -1�� ��ȯ
	}
};

int main() {
	int T, e;
	cin >> T;
	List l;
	List::Iterator iter = l.begin();

	for (int i = 0; i < T; i++) {
		string command;
		cin >> command;
		if (command == "begin") {
			iter = l.begin();
		}
		else if (command == "end") {
			iter = l.end();
		}
		else if (command == "insert") {
			cin >> e;
			l.insertBack(e);
		}
		else if (command == "erase") {
			if (l.empty()) {
				cout << "Empty" << endl;
			}
			else {
				l.eraseFront();
			}
		}
		else if (command == "++") {
			++iter;
		}
		else if (command == "--") {
			--iter;
		}
		else if (command == "print") {
			if (l.empty()) {
				cout << "Empty" << endl;
			}
			else {
				l.print();
				cout << endl;
			}
		}
		else if (command == "find") {
			cin >> e;
			if (l.empty()) {
				cout << "Empty" << endl;
			}
			else {
				cout << l.find(e) << endl;
			}
		}
		else if (command == "at") { // at
			cout << *iter << endl; // ���� iterator�� ���� ��ȯ
		}
	}
}
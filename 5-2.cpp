#include <iostream>
#include <string>
using namespace std;

class List {
private:
	class Node {
	public:
		int e;
		Node* prev;
		Node* next;
	};

public:
	class Iterator {
	private:
		Node* v;
		Iterator(Node* u) {
			v = u;
		}
	public:
		int& operator*() {
			return v->e;
		}
		bool operator==(const Iterator& p)const {
			return v == p.v;
		}
		bool operator!=(const Iterator& p)const {
			return v != p.v;
		}
		Iterator& operator++() {
			v = v->next;
			return *this;
		}
		Iterator& operator--() {
			v = v->prev;
			return *this;
		}
		friend class List;
	};
private:
	int n;
	Node* header;
	Node* trailer;
public:
	List() {
		n = 0;
		header = new Node;
		trailer = new Node;
		header->next = trailer;
		trailer->prev = header;
	}
	int size() const {
		return n;
	}
	bool empty() const {
		return size() == 0;
	}
	Iterator begin() const {
		return Iterator(header->next);
	}
	Iterator end() const {
		return Iterator(trailer);
	}
	void insertFront(const int& e) {
		insert(begin(), e);
	}
	void insertBack(const int& e) {
		insert(end(), e);
	}
	void insert(const Iterator& p, const int& e) {
		Node* w = p.v;
		Node* u = w->prev;
		Node* v = new Node;
		v->e = e;
		v->next = w;
		w->prev = v;
		v->prev = u;
		u->next = v;
		this->n++;
	}
	void eraseFront() {
		erase(begin());
	}
	void eraseBack() {
		erase(--end());
	}
	void erase(const Iterator& p) {
		Node* v = p.v;
		Node* w = v->next;
		Node* u = v->prev;
		u->next = w;
		w->prev = u;
		delete v;
		this->n--;
	}
	Iterator atIndex(int i) const {
		Iterator p = begin();
		for (int j = 0; j < i; j++) {
			++p;
		}
		return p;
	}
	int indexOf(const Iterator& p) const {
		Iterator q = begin();
		int j = 0;
		while (q != p) {
			++q;
			++j;
		}
		return j++;
	}
	void print() {
		Node* cur = header->next;
		for (int i = 0; i < n; i++) {
			cout << cur->e << ' ';
			cur = cur->next;
		}
	}
	int find(int e) {
		Node* cur = header->next;
		for (int i = 0; i < n; i++) {
			if (e == cur->e) {
				return i;
			}
			cur = cur->next;
		}
		return -1;
	}
	void maxpooling(int i) { // maxpooling �Լ�
		Node* back = header; // ������ �� ���
		Node* cur = header->next; // ���� ���
		Node* front = header->next->next; // ������ ���� ���
		for (int j = 0; j < i; j++) { // List�� ���� i��ŭ �ݺ�
			if (back->e > cur->e) { // back > cur�� ���
				if (back->e > front->e) { // back > front���
					cout << back->e << ' '; // back�� �ִ밪
				}
				else if (front->e > back->e) { // front > back�̶��
					cout << front->e << ' '; // front�� �ִ밪
				}
			}
			else if (cur->e > back->e) { // cur > back�� ���
				if (cur->e > front->e) { // cur > front�� ���
					cout << cur->e << ' '; // cur�� �ִ밪
				}
				else{ // front > cur�ΰ��
					cout << front->e << ' '; // front�� �ִ밪
				}
			}
			back = back->next; // back�� ������ �Ű��ֱ�
			cur = cur->next; // cur�� ������ �Ű��ֱ�
			front = front->next; // front�� ������ �Ű��ֱ�
		}
		cout << '\n'; // ��� ��� �� �ٹٲ�
	}
};

int main() {
	int T, z, n;
	cin >> T;
	
	for (int i = 0; i < T; i++) {
		List l;
		cin >> z;
		for (int j = 0; j < z; j++) {
			cin >> n;
			l.insertBack(n);
		}
		l.maxpooling(z);
	}
}
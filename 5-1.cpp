#include <iostream>
#include <string>
using namespace std;

class List { // List 클래스(이중연결 리스트)
private:
	struct Node { // Node 구조체
		int e;
		Node* prev;
		Node* next;
	};

public:
	class Iterator { // Iterator 클래스
	private:
		Node* v; // 노드형 포인터 v
		Iterator(Node* u) { // 노드형 포인터를 받는 생성자
			v = u;
		}
	public:
		int& operator*() { // * 연산자 오버로딩
			return v->e; // iterator의 값을 리턴
		}
		bool operator==(const Iterator& p)const { // == 연산자 오버로딩
			return v == p.v; // iterator끼리의 주소가 같은지 확인
		}
		bool operator!=(const Iterator& p)const { // != 연산자 오버로딩
			return v != p.v; // iterator끼리의 주소가 다른지 확인
		}
		Iterator& operator++() { // ++ 연산자 오버로딩(전위)
			v = v->next; // iterator의 주소를 next로 변경
			return *this; // iterator 리턴
		}
		Iterator& operator--() { // -- 연산자 오버로딩(전위)
			v = v->prev; // iterator의 주소를 prev로 변경
			return *this; // iterator 리턴
		}
		friend class List; // List 클래스와 friend 선언
	};
private:
	int n; // List의 사이즈 n
	Node* header; // header 포인터
	Node* trailer; // trailer 포인터
public:
	List() { // 생성자
		n = 0;
		header = new Node;
		trailer = new Node;
		header->next = trailer;
		trailer->prev = header;
	}
	int size() const { // size 함수
		return n;
	}
	bool empty() const { // empty 함수
		return size() == 0;
	}
	Iterator begin() const { // begin 함수 
		return Iterator(header->next); // iterator를 begin으로 위치시킨다
	}
	Iterator end() const { // end 함수
		return Iterator(trailer); // iterator를 end로 위치시킨다
	}
	void insertFront(const int& e) { // insertFront 함수
		insert(begin(), e);
	}
	void insertBack(const int& e) { // insertBack 함수
		insert(end(), e);
	}
	void insert(const Iterator& p, const int& e) { // insert 함수
		Node* w = p.v; // insert 하고싶은 주소를 포인터 w에 할당
		Node* u = w->prev; // insert 하고싶은 주소의 전 주소를 u에 할당
		Node* v = new Node; // 데이터 저장용 새 노드 생성
		v->e = e; // 새 노드의 데이터를 입력값 e로 할당
		v->next = w; // 새 노드의 next를 w로 연결
		w->prev = v; // w의 prev를 새 노드로 연결
		v->prev = u; // 새 노드의 prev를 u로 연결
		u->next = v; // u의 next를 새 노드로 연결
		this->n++; // List의 크기를 +1
	}
	void eraseFront() { // eraseFront 함수
		erase(begin());
	}
	void eraseBack() { // eraseBack 함수
		erase(--end()); // end는 비어있기때문에 end 전의 노드를 삭제
	}
	void erase(const Iterator& p) { // erase 함수
		Node* v = p.v; // 지울 노드의 주소를 v에 할당
		Node* w = v->next; // v의 다음 노드 주소를 w에 할당
		Node* u = v->prev; // v의 전 노드 주소를 u에 할당
		u->next = w; // u의 next를 w로 연결
		w->prev = u; // w의 prev를 u로 연결
		delete v; // 노드를 삭제
		this->n--; // List의 크기를 -1
	}
	Iterator atIndex(int i) const { // atIndex 함수
		Iterator p = begin(); // iterator를 begin부터 시작
		for (int j = 0; j < i; j++) { // index i까지 iterator를 옆으로 옮겨주기
			++p;
		}
		return p; // index i의 주소 p 반환
	}
	int indexOf(const Iterator& p) const { // indexOf 함수
		Iterator q = begin(); // iterator q를 begin부터 시작
		int j = 0; // index 저장용 j변수 
		while (q != p) { // q가 p와 같아질때까지 q를 옮겨주고 j+1 해주기
			++q;
			++j;
		}
		return j++; // j-1인 상태였으므로 반환시에 +1 해주기
	}
	void print() { // print 함수
		Iterator iter = this->begin(); // iterator를 begin부터 시작
		while (iter != this->end()) { // iterator가 end가 아닐때까지
			cout << *iter << ' '; // iterator의 주소에 있는 값을 출력
			++iter; // iterator를 옆으로 옮겨주기
		}
	}
	int find(int e) { // find 함수
		Iterator iter = this->begin(); // iterator를 begin부터 시작
		for (int i = 0; i < n; i++) { // List의 끝까지
			if (*iter == e) { // iterator의 주소에 있는 값이 내가 찾는 값이라면
				return i; // 그때의 index를 반환
			}
			++iter; // iterator를 옆으로 옮겨주기
		}
		return -1; // 없다면 -1을 반환
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
			cout << *iter << endl; // 현재 iterator의 값을 반환
		}
	}
}
#include <iostream>
#include <string>

using namespace std;

// 노드 클래스
class Node {
public:
	int data;
	Node* next;
	Node* prev;
};

class LikedList :public Node { // 노드 클래스 상속
private:
	Node* header;
	Node* trailer;
	int size = 0;
public:
	LikedList() : header(NULL), trailer(NULL) {} // 생성자로 head와 tail을 NULL로 초기화

	// Size 함수
	int Size() {
		return size;
	}

	// Empty 함수
	bool Empty() {
		if (header == NULL && trailer == NULL) {
			return true;
		}
		else {
			return false;
		}
	}

	// Print 함수
	void Print() {
		if (Empty()) { // 비어있는지 확인
			cout << "empty" << endl;
		}
		else {
			Node* cur = header;
			while (cur->next != NULL) { // 현재의 다음이 NULL이 아닐경우 -> trailer 전까지
				cout << cur->data << ' ';
				cur = cur->next;
			}
			cout << cur->data << endl; // trailer일때
		}
	}

	void Print_reverse() {
		if (Empty()) { // 비어있는지 확인
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

	//append 함수
	void Append(int value) {
		Node* node = new Node; // 새 노드 동적할당

		//노드의 값과 다음주소 할당
		node->data = value;
		node->next = NULL;
		node->prev = NULL;

		if (header == NULL) { // node가 첫번째 값일경우 header와 trailer 모두 node
			header = node;
			trailer = node;
		}
		else { // node가 첫번째 값이 아닐경우 trailer의 next를 node를 향하게 하고 node의 prev를 trailer를 향하게 하고 trailer를 node로 할당
			trailer->next = node;
			node->prev = trailer;
			trailer = node;
			trailer->next = NULL;
		}

		size++; // 리스트의 사이즈를 +1해주기
	}

	// Delete 함수
	int Delete(int idx) { 
		int temp = -1;
		int middle = Size() / 2; //리스트의 중간 인덱스 
		Node* cur;
		Node* pre;

		if (Empty() || Size() <= idx) {
			return -1;
		}
		else if (idx == 0) { // 첫 값을 삭제할때
			if (size == 1) { // 노드가 하나만 있을경우
				cur = header;
				temp = cur->data;
				header = NULL;
				trailer = NULL;
				delete cur;
			}
			else { // 노드가 하나 이상인 경우
				cur = header;
				temp = cur->data;
				header = header->next;
				delete cur;
			}
			size--; // 리스트의 크기를 -1 해주기
		}
		// 실행 속도를 높히기 위해 인덱스가 리스트의 중간값보다 작거나 같으면 앞에서부터 시작
		else if (idx <= middle) { // 인덱스가 리스트의 중간값보다 작거나 같은 경우
			pre = cur = header;
			for (int i = 0; i < idx; i++) { // 앞에서부터 인덱스까지 이동
				pre = cur;
				cur = cur->next;
			}
			temp = cur->data;
			pre->next = cur->next; // pre의 next를 cur의 next로 연결
			if (cur == trailer) { // cur이 trailer일 경우
				trailer = pre; // trailer를 pre로 할당
			}
			else { // 아닐경우 
				(cur->next)->prev = pre; // cur의 next의 prev를 pre로 지정
			}
			delete cur; // cur 제거
			size--; // 리스트의 사이즈를 -1 해주기
		}
		// 리스트의 중간값보다 크면 뒤에서부터 시작
		else if (idx > middle) { // 인덱스가 리스트의 중간값보다 큰 경우
			pre = cur = trailer;
			for (int i = Size(); i > idx; i--) { // 뒤에서부터 인덱스까지 이동
				cur = pre;
				pre = pre->prev;
			}
			temp = cur->data;
			pre->next = cur->next; // pre의 next를 cur의 next로 연결
			if (cur == trailer) { // cur이 trailer일 경우
				trailer = pre; // trailer를 pre로 할당
			}
			else { // 아닐경우
				(cur->next)->prev = pre; // cur의 next의 prev를 pre로 지정
			}
			delete cur; // cur 제거
			size--; // 리스트의 사이즈를 -1 해주기
		}
		return temp; // 삭제한 값 temp 리턴
	}

	//Max 함수
	void Max() {
		int max;
		if (Empty()) { // 리스트가 비어있는 경우
			cout << "empty" << endl;
		}
		else {
			Node* cur = header->next; // 처음부터
			max = header->data;
			while (cur != NULL) { // 마지막까지
				if (cur->data > max) { // 현재 데이터가 max보다 크다면
					max = cur->data; // max 바꾸기
				}
				cur = cur->next;
			}
			cout << max << endl; // max 출력
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
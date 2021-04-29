#include <iostream>
#include <string>

using namespace std;

// 노드 클래스
class Node {
public:
	int data;
	Node* next;
};

class LikedList :public Node { // 노드 클래스 상속
private:
	Node* head;
	Node* tail;
	int size = 0;
public:
	LikedList() : head(NULL), tail(NULL) {} // 생성자로 head와 tail을 NULL로 초기화

	// Size 함수
	int Size() {
		return size;
	}

	// Empty 함수
	bool Empty() {
		if (head == NULL && tail == NULL) {
			return true;
		}
		else {
			return false;
		}
	}

	// Print 함수
	void Print() {
		if (Empty()) {
			cout << "empty" << endl;
		}
		else {
			Node* cur = head;
			while (cur->next != NULL) { // 현재의 다음이 NULL이 아닐경우 -> tail 전까지
				cout << cur->data << ' ';
				cur = cur->next;
			}
			cout << cur->data << endl; // tail일때
		}
	}

	// append 함수
	void Append(int value) {
		Node* node = new Node; // 새 노드 동적할당

		//노드의 값과 다음주소 할당
		node->data = value;
		node->next = NULL;

		if (head == NULL) { // node가 첫번째 값일경우 head와 trailer 모두 node
			head = node;
			tail = node;
		}
		else { // node가 첫번째 값이 아닐경우 tail의 다음을 node를 향하게 하고 tail을 node로 할당
			tail->next = node;
			tail = node;
		}

		size++; // 리스트의 사이즈를 +1해주기
	}

	// Delete 함수
	int Delete(int idx) {
		int temp;
		Node* cur;
		Node* pre;

		if (Empty() || Size() <= idx) {
			return -1;
		}
		else if (idx == 0) { // 첫번째 데이터를 지우는 경우
			if (size == 1) {
				cur = head;
				temp = cur->data; 
				head = NULL; // head가 NULL을 가리키게 함
				tail = NULL; // tail도 NULL을 가리키게 함
				delete cur; //첫 노드 삭제
			}
			else {
				cur = head;
				temp = cur->data;
				head = head->next; // head를 한칸 옆으로 옮기기
				delete cur; // 첫 노드 삭제
			}
			size--; // 리스트의 사이즈를 -1 해주기
		}
		else { // 첫번째가 아닌 데이터를 지우는 경우
			pre = cur = head;
			for (int i = 0; i < idx; i++) { // 입력받은 인덱스까지 전 노드, 현재 노드 옮기기
				pre = cur;
				cur = cur->next;
			}
			temp = cur->data; // 현재값을 temp에 저장
			pre->next = cur->next; // 전 노드의 next를 현재 노드의 다음 노드로 연결
			if (cur == tail) { // if 현재 노드가 tail이라면
				tail = pre; // tail을 전 노드로 바꾸기
			}
			delete cur; //현재 노드 지우기
			size--; // 리스트의 사이즈를 -1 해주기
		}
		return temp; // temp 리턴해주기
	}

	// Insert 함수
	int Insert(int idx, int value) {
		Node* node = new Node; // 새 노드 생성
		node->data = value;
		node->next = NULL;

		Node* pre;
		Node* cur;

		if (idx<0 || idx>Size()) { //인덱스가 0보다 작거나 리스트의 크기를 벗어나는경우
			cout << "Index Error" << endl;
			return -1;
		}
		else if (idx == 0) { // 노드를 처음에 삽입하는 경우
			if (Empty()) { // 리스트가 비어있는 경우
				head = node;
				tail = node;
			}
			else { // 아닌경우
				node->next = head; //노드의 next를 head로 바꾸기
				head = node; // head를 노드로 바꾸기
			}
			size++; // 리스트의 사이즈를 +1 해주기
		}
		else if (idx == Size()) { // 리스트의 끝에 추가하는 경우
			Append(value); // Append 함수 사용
		}
		else { // 중간에 삽입하는 경우
			pre = cur = head;
			for (int i = 0; i < idx; i++) { // 인덱스 위치까지 이동
				pre = cur;
				cur = cur->next;
			}
			pre->next = node; // pre의 next가 노드를 가리키게 하기
			node->next = cur; // 노드의 next가 cur을 가리키게 하기
			size++; // 리스트의 사이즈를 +1 해주기
		}
		return 0;
	}

	// Sum 함수
	int Sum() {
		int sum = 0;
		if (!Empty()) { // 리스트가 비어있지 않다면
			Node* cur = head; // 리스트의 처음부터
			while (cur!= NULL) { // 리스트의 끝까지
				sum = sum + cur->data; // 값을 sum에 더해주기
				cur = cur->next; // 한칸씩 옆으로 옮기기
			}
		}
		return sum; // sum 리턴
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
#include <iostream>
#include <string>
using namespace std;

class Node {
private:
	int data;
	Node* next;
	friend class queue;
};

//Queue클래스
class queue {
private:
	Node* Front; // 맨 앞을 가리키는 포인터 삭제만 가능
	Node* Rear; // 맨 뒤를 가리키는 포인터 추가만 가능
	int Size; // 큐의 크기
public:
	queue() :Front(nullptr), Rear(nullptr), Size(0) {}; // front와 rear를 nullptr로 Size를 0으로 초기화

	//size 함수 
	int size() {
		return Size;
	}

	//empty 함수
	bool empty() {
		return Size == 0;
	}

	// front 함수
	void front() {
		if (empty()) {
			cout << "Empty" << endl;;
		}
		else {
			cout << Front->data << endl; // 제일 앞에값을 리턴
		}
	}

	// rear 함수
	void back() {
		if (empty()) {
			cout << "Empty" << endl;
		}
		else {
			cout << Rear->data << endl; // 제일 뒤에값을 리턴
		}
	}

	// push 함수
	void push(int value) {
		Node* node = new Node; // 새 노드를 만듦
		node->data = value; // 노드에 할당
		node->next = nullptr;

		if (empty()) { // Queue가 비어있는경우
			Front = node;
			Rear = node;
		}
		else { // Queue가 비어있지 않은 경우
			Rear->next = node;
			Rear = node;
		}
		Size++;
	}

	// pop 함수
	int pop() {
		if (empty()) {
			cout << "Empty" << endl;
			return 0;
		}
		Node* cur = Front; // 메모리 해제용 포인터에 front의 주소를 할당
		int data = Front->data;
		Front = Front->next; // front를 한칸 옆으로 옮겨주기

		Size--;
		delete cur; // 메모리 해제
		cout << data << endl;
		return 0;
	}
};

int main() {
	int N, data;
	string command;

	cin >> N;
	queue q;

	for (int i = 0; i < N; i++) {
		cin >> command;
		if (command == "size") {
			cout << q.size() << endl;
		}
		else if (command == "isEmpty") {
			if (q.empty()) {
				cout << "True" << endl;
			}
			else {
				cout << "False" << endl;
			}
		}
		else if (command == "front") {
			q.front();
		}
		else if (command == "rear") {
			q.back();
		}
		else if (command == "enqueue") {
			cin >> data;
			q.push(data);
		}
		else if (command == "dequeue") {
			q.pop();
		}
	}
}
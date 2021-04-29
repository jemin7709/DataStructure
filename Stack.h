#pragma once
class Node {
private:
	int data;
	Node* next;
	friend class Stack;
};

//Stack클래스
class Stack {
private:
	Node* head; // 맨 위를 가리키는 포인터
	int Size; // 스택의 크기
public:
	Stack() :head(nullptr), Size(0) {}; // head를 NULL로 Size를 0으로 초기화

	//size 함수 
	int size() {
		return Size;
	}

	//empty 함수
	bool empty() {
		return Size == 0;
	}

	// top 함수
	int top() {
		if (empty()) {
			return -1;
		}
		return head->data; // 제일 위에값을 리턴
	}

	// push 함수
	void push(int value) {
		Node* node = new Node; // 새 노드를 만듦
		node->data = value; // 노드에 할당
		node->next = nullptr;

		if (empty()) { // Stack이 비어있는경우
			head = node;
		}
		else { // Stack이 비어있지 않은 경우
			node->next = head;
			head = node;
		}
		Size++;
	}

	// pop 함수
	int pop() {
		if (empty()) {
			return -1;
		}
		Node* cur = head; // 메모리 해제용 포인터에 지울 메모리의 주소를 할당
		int temp; // 값 저장용 int 변수

		head = head->next; // head를 한칸 아래로 옮겨주기
		temp = cur->data; // 지울 메모리의 값을 int변수에 넣어주기

		Size--;
		delete cur; // 메모리 해제
		return temp; // 저장된 값 반환
	}
};
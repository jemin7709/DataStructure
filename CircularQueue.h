#pragma once

template <typename T>
class Node {
public:
	T data;
	Node<T>* next;
	Node<T>* prev;
	template <typename T> friend class Cqueue;
};

//Queue클래스
template <typename T>
class Cqueue {
private:
	
public:
	Node<T>* Front; // 맨 앞을 가리키는 포인터 삭제만 가능
	Node<T>* Rear; // 맨 뒤를 가리키는 포인터 추가만 가능
	int Size; // 큐의 크기
	Cqueue() :Front(nullptr), Rear(nullptr), Size(0) {}; // front와 rear를 nullptr로 Size를 0으로 초기화

	//size 함수 
	int size() {
		return Size;
	}

	//empty 함수
	bool empty() {
		return Size == 0;
	}

	// front 함수
	T front() {
		if (empty()) {
			return -1;
		}
		return Front->data; // 제일 앞에값을 리턴
	}

	// rear 함수
	T back() {
		if (empty()) {
			return -1;
		}
		return Rear->data; // 제일 뒤에값을 리턴
	}

	// push 함수
	void push(T value) {
		Node<T>* node = new Node<T>; // 새 노드를 만듦
		node->data = value; // 노드에 할당
		node->next = nullptr;
		node->prev = nullptr;

		if (empty()) { // Queue가 비어있는경우
			Front = node;
			Rear = node;
		}
		else { // Queue가 비어있지 않은 경우
			node->next = Rear;
			Rear->prev = node;
			Rear = node;
			Rear->prev = Front;
			Front->next = Rear;
		}
		Size++;
	}

	// pop 함수
	int pop() {
		if (empty()) {
			return -1;
		}
		Node<T>* cur = Front; // 메모리 해제용 포인터에 front의 주소를 할당

		Front = Front->prev; // front를 한칸 옆으로 옮겨주기
		Rear->prev = Front;
		Front->next = Rear;

		Size--;
		delete cur; // 메모리 해제
		return 1;
	}

	void left() {
		Rear = Rear->prev;
		Front = Front->prev;
	}

	void right() {
		Front = Front->next;
		Rear = Rear->next;
	}

	int* get_Front() {
		return Front;
	}
};
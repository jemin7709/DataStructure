#include <iostream>
//#include "CircularQueue.h"
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node* prev;
};

//원형Queue클래스
class Cqueue {
private:

public:
	Node* Front; // 맨 앞을 가리키는 포인터 삭제만 가능
	Node* Rear; // 맨 뒤를 가리키는 포인터 추가만 가능
	int Size; // 큐의 크기
	Cqueue() :Front(NULL), Rear(NULL), Size(0) {}; // front와 rear를 nullptr로 Size를 0으로 초기화

	//size 함수 
	int size() {
		return Size;
	}

	//empty 함수
	bool empty() {
		return Size == 0;
	}

	// front 함수
	int front() {
		if (empty()) {
			return -1;
		}
		return Front->data; // 제일 앞에값을 리턴
	}

	// rear 함수
	int back() {
		if (empty()) {
			return -1;
		}
		return Rear->data; // 제일 뒤에값을 리턴
	}

	// push 함수
	void push(int value) {
		Node* node = new Node; // 새 노드를 만듦
		node->data = value; // 노드에 할당
		node->next = NULL;
		node->prev = NULL;

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
		Node* cur = Front; // 메모리 해제용 포인터에 front의 주소를 할당

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

};

int main() {
	int n, m, target, target_index = 0, count = 0;
	Cqueue cq;
	cin >> n >> m;

	for (int i = 0; i < n; i++) { // n만큼 넣어주기
		cq.push(i + 1);
	}
	
	for (int i = 0; i < m; i++) {
		cin >> target;
		Node* cur = cq.Front;

		for (int j = 0; j < cq.size(); j++) { // 인덱스 확인용
			if (cur->data == target) { // cur이 target과 같다면
				target_index = j; // 그때의 인덱스를 target_index에 넣어주고
				break; // 멈추기
			}
			if (cur != NULL) { // 아니라면
				cur = cur->next; // 다음 인덱스로 이동
			}
		}

		if (target_index < cq.size() - target_index) { // target_index가 큐의 크기 - target_index보다 작다면
			while (cq.front() != target) { // front가 target과 같아질때까지
				cq.right(); // cq를 오른쪽으로 미룸
				count++;
			}
			cq.pop(); // 다 미뤘다면 pop해주기
		}
		else { // target_index가 큐의 크기 - target_index보다 크다면
			while (cq.front() != target) { // front가 target과 같아질때까지
				cq.left(); // cq를 왼쪽으로 미룸
				count++;
			}
			cq.pop(); // 다 미뤘다면 pop 해주기
		}
	}
	cout << count; // 미룰때마다 더해줬던 count를 출력하기
	return 0;
}
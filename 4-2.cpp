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

	void setfront(int value) {
		Front->data = value;
	}

	// front 함수
	int  front() {
		if (empty()) {
			cout << "Empty" << endl;
			return 0;
		}
		else {
			return Front->data; // 제일 앞에값을 리턴
		}
	}

	// rear 함수
	int back() {
		if (empty()) {
			cout << "Empty" << endl;
			return 0;
		}
		else {
			return Rear->data; // 제일 뒤에값을 리턴
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
			return 0;
		}
		Node* cur = Front; // 메모리 해제용 포인터에 front의 주소를 할당
		int data = Front->data;
		Front = Front->next; // front를 한칸 옆으로 옮겨주기

		Size--;
		delete cur; // 메모리 해제
		return data;
	}
};

int main() {
	int t, n;
	cin >> t;

	while (t--) { // t번 반복
		cin >> n;

		int temp = 0, p1p = 0, p2p = 0; // 값을 임시 저장할 temp와 p1포인트 p1p, p2포인트 p2p 선언
		queue p1, p2; // p1, p2 큐 선언

		for (int j = 0; j < n; j++) { // p1 덱 입력
			cin >> temp;
			p1.push(temp);
		}

		for (int j = 0; j < n; j++) { // p2 덱 입력
			cin >> temp;
			p2.push(temp);
		}

		while (!p1.empty()) { // p1이나 p2나 크기는 같으므로 아무거나 사용
			temp = p1.pop() - p2.pop(); // temp는 p1 - p2의 값
			if (temp > 0) { // temp가 양수면 p1>p2
				if (!p1.empty()) { // p1의 마지막이 아니라면
					p1.setfront(p1.front() + temp); // 현재 p1의 점수에 남은 체력 더해주기
				}
				p1p++; // p1포인트를 +1
			}
			else if (temp < 0) { // temp가 음수면 p2>p1
				if (!p2.empty()) { // p2의 마지막이 아니라면 
					p2.setfront(p2.front() + abs(temp)); // 현재 p2의 점수에 남은 체력 더해주기
				}
				p2p++; // p2포인트를 +1
			}
		} // 동점일경우에는 그냥 지나감

		if (p1p > p2p) { // p1p>p2p일 경우 1 출력
			cout << "1" << endl;
		}
		else if (p2p > p1p) { // p2p>p1p일 경우 2 출력
			cout << "2" << endl;
		}
		else { // 동점일경우 0 출력
			cout << "0" << endl;
		}
	}

	return 0;
}
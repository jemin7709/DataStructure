#include <iostream>
#include <string>
using namespace std;

// 노드 클래스(Stack 클래스를 friend 함수로 가짐)
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
	Stack() :head(NULL), Size(0) {}; // head를 NULL로 Size를 0으로 초기화

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
			cout << "Empty Error" << endl;
			return -1;
		}
		return head->data; // 제일 위에값을 리턴
	}

	// push 함수
	void push(int value) {
		Node* node = new Node; // 새 노드를 만듦
		node->data = value; // 노드에 할당
		node->next = NULL;

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
			cout << "Empty Error" << endl;
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

	// print 함수 (꼭 있어야 하는건 아님)
	void print() {
		if (empty()) {
			cout << "Empty Error" << endl;
		}
		Node* cur = head; // 처음부터 시작
		while (cur != NULL) { // NULL 전까지 -> 마지막 값까지
			cout << cur->data << endl; // 현재 포인터가 가리키고있는 노드의 데이터 출력
			cur = cur->next; // 현재 포인터를 다음 노드로 바꾸기
		}
	}
};

int main() {
	int t, size, temp1 = -1, temp2 = -1;
	string me; // 입력받을 수식
	Stack stack;

	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> me; // 수식 입력
		size = me.size(); // 수식의 string 크기를 size에 할당
		for (int j = 0; j < size; j++) {
			if (me[j] == '+') { // 수식이 연산자 +일때
				temp2 = stack.pop();
				temp1 = stack.pop();
				stack.push(temp1 + temp2);
			}
			else if (me[j] == '-') { // 수식이 연산자 -일때
				temp2 = stack.pop();
				temp1 = stack.pop();
				stack.push(temp1 - temp2);
			}
			else if (me[j] == '*') { // 수식이 연산자 *일때
				temp2 = stack.pop();
				temp1 = stack.pop();
				stack.push(temp1 * temp2);
			}
			else { // 수식이 정수일때
				stack.push(me[j] - '0');
			}
		}

		temp1, temp2 = stack.pop(); // 마지막 결과값을 temp1, temp2에 할당
		temp1 = abs(temp1); // temp1을 양수로 만들어주기

		while (temp1 >= 10) { // temp1이 10보다 크거나 같다면
<<<<<<< HEAD
			temp1 = temp1 % 10; // temp1을 temp1의 mod10으로 재할당(1의 자리만 남을때까지)
=======
			temp1 = temp1 % 10; // temp1을 temp1의 mod10으로 나눠주기(1의 자리만 남을때까지)
>>>>>>> 748c32bee8e8b305ea82cd789c39ffd4de711be7
		}

		if (temp2 < 0) { // 마지막 결과값이 음수였다면
			temp1 *= -1; // 1의 자리만 남은 결과에 -1 곱해주기
		}
<<<<<<< HEAD

=======
>>>>>>> 748c32bee8e8b305ea82cd789c39ffd4de711be7
		cout << temp1 << endl; // 최종 결과값 출력
	}
}
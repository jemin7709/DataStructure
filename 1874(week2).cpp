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
	int n, num, count = 1; // n, 숫자, 오름차수를 입력받을 변수 선언
	string answer; // 정답을 입력받을 변수 선언
	Stack stack; // 오름차수를 관리할 Stack 선언

	cin >> n; // n 입력

	for (int i = 0; i < n; i++) { // n번만큼 반복
		cin >> num; // 수열을 하나씩 입력
		
		// 예외처리부분
		if (stack.top() < num && num < count) { // 만약 입력받은 수가 오름차수보다 작지만 스택의 최댓값보다 크다면
			answer = "NO"; // 불가능한 경우이므로 NO 출력
			break; // for문 탈출
		}
		
		// 계산부분
		while (num >= count) { // 입력받은 수가 오름차수보다 크거나 같다면
			stack.push(count++); // Stack에 오름차수를 push하고
			answer += '+'; // 정답에 + 추가
		}
		while (num <= stack.top()) { // 입력받은수가 오름차수의 최대값보다 작거나 같다면
			stack.pop(); // 최댓값 제거
			answer += '-'; // 정답에 -추가
		}
	}

	if (answer == "NO") { // 정답이 NO라면
		cout << "NO"; // NO출력
	}
	else{ // 정답이 NO가 아니라면
		for (char elem : answer) { // 정답을 한 문자씩 출력
			cout << elem << '\n'; // 실행속도를 빠르게 하기 위해 endl대신 \n사용
		}
	}

	return 0;
}
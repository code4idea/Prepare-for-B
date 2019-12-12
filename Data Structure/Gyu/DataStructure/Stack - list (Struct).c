/* 
** 스택 - 연결리스트 (구조체-C언어)
** ADT
** - push
** - pop
** - peak
** - empty
*/

#include <malloc.h>
#define NULL 0

typedef struct node
{
	struct node* next;
	int data;
} Node;

typedef struct stack
{
	Node* topNode;

	void initStack();
	void push(int value);
	int pop();
	int top();
	bool isEmpty();
} Stack;

void Stack::initStack() {
	topNode = NULL;
}

void Stack::push(int value) {
	Node* newNode = (Node *)malloc(sizeof(Node));
	newNode->next = topNode;
	newNode->data = value;
	topNode = newNode;
};

int Stack::pop() {
	if (empty()) return 0;

	Node * delNode = topNode;
	int returnData = topNode->data;
	topNode = topNode->next;
	free(delNode);
	return returnData;
}

int Stack::top() {
	return topNode->data;
}

bool Stack::empty() {
	return topNode == NULL ? true : false;
}

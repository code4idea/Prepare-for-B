/* 
** 스택 - 연결리스트 (구조체-C언어)
** ADT
** - push
** - pop
** - peak
** - isEmpty
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
	Node* top;

	void initStack();
	void push(int value);
	int pop();
	int peak();
	bool isEmpty();
} Stack;

void Stack::initStack() {
	top = NULL;
}

void Stack::push(int value) {
	Node* newNode = (Node *)malloc(sizeof(Node));
	newNode->next = top;
	newNode->data = value;
	top = newNode;
};

int Stack::pop() {
	if (isEmpty()) return 0;

	Node * delNode = top;
	int returnData = top->data;
	top = top->next;
	free(delNode);
	return returnData;
}

int Stack::peak() {
	return top->next->data;
}

bool Stack::isEmpty() {
	return top == NULL ? true : false;
}

/* 
** 큐 - 연결리스트 (구조체)
** ADT
** - push
** - pop
** - front
** - back
** - empty
*/

#include <malloc.h>
#define NULL 0

typedef struct node {
	struct node* next;
	int data;
}Node;

typedef struct queue {
	Node* frontNode;
	Node* backNode;
	
	void init();
	void push(int value);
	int pop();
	int front();
	int back();
	int empty();
} Queue;

void Queue::init() {
	frontNode = NULL;
	backNode = NULL;
}

void Queue::push(int value) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->next = backNode;
	newNode->data = value;

	backNode = newNode;
	if (frontNode == NULL) frontNode = newNode;
}

int Queue::pop() {
	if (empty()) return 0;

	Node* delNode = frontNode;
	int ret = frontNode->data;
	frontNode = frontNode->next;
	free(delNode);
	return ret;
}

int Queue::front() {
	return frontNode == NULL ? 0 : frontNode->data;
}

int Queue::back() {
	return backNode == NULL ? 0 : backNode->data;
}

int Queue::empty() {
	return (frontNode == backNode && frontNode == NULL) ? true : false;
}

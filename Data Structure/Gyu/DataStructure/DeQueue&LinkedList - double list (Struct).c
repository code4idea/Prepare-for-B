/* 
** 링크드 리스트 - 연결리스트 (구조체)
** ADT
** - push_front
** - push_back
** - pop_front
** - pop_back
** - insert
** - remove
** - front
** - back
** - empty
*/


#include <malloc.h>
#define NULL 0

typedef struct node {
	struct node* prev;
	struct node* next;
	int data;
}Node;

typedef struct list {
	Node* frontNode;
	Node* backNode;
	
	void init();
	void push_front(int value);
	void push_back(int value);
	int pop_front();
	int pop_back();
	Node* search_front(int value);
	bool insert(int value);
	bool remove(int value);
	int front();
	int back();
	int empty();
} List;

void List::init() {
	frontNode = NULL;
	backNode = NULL;
}

void List::push_front(int value) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->prev = NULL;
	newNode->next = frontNode;
	newNode->data = value;

	frontNode = newNode;
	if (frontNode == NULL) backNode = newNode;
}

void List::push_back(int value) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->prev = backNode;
	newNode->next = NULL;
	newNode->data = value;

	backNode = newNode;
	if (frontNode == NULL) frontNode = newNode;
}

int List::pop_front() {
	if (empty()) return 0;

	Node* delNode = frontNode;
	int ret = frontNode->data;
	frontNode = frontNode->next;
	frontNode->prev = NULL;
	free(delNode);
	return ret;
}

int List::pop_back() {
	if (empty()) return 0;

	Node* delNode = backNode;
	int ret = backNode->data;
	backNode = backNode->prev;
	backNode->next = NULL;
	free(delNode);
	return ret;
}

Node* List::search_front(int value) {
	Node* ret = frontNode;
	while (ret != NULL) {
		if (ret->data == value) break;
		ret = ret->next;
	}
	return ret;
}

bool insert(int value) {
	Node* searchNode = search_front(value);

}

int List::front() {
	return frontNode == NULL ? 0 : frontNode->data;
}

int List::back() {
	return backNode == NULL ? 0 : backNode->data;
}

int List::empty() {
	return (frontNode == backNode && frontNode == NULL) ? true : false;
}

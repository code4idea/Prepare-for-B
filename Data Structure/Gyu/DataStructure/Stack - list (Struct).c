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

using namespace std;

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
	bool insert(Node* inputNode, int value);
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

	frontNode->prev = newNode;
	frontNode = newNode;
	if (backNode == NULL) backNode = newNode;
}

void List::push_back(int value) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->prev = backNode;
	newNode->next = NULL;
	newNode->data = value;

	if(backNode != NULL) backNode->next = newNode;
	backNode = newNode;
	if (frontNode == NULL) frontNode = newNode;
}

int List::pop_front() {
	if (empty()) return 0;

	Node* delNode = frontNode;
	int ret = frontNode->data;
	frontNode = frontNode->next;
	if (frontNode != NULL) frontNode->prev = NULL;
	free(delNode);
	return ret;
}

int List::pop_back() {
	if (empty()) return 0;

	Node* delNode = backNode;
	int ret = backNode->data;
	backNode = backNode->prev;
	if (backNode != NULL) backNode->next = NULL;
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

bool List::insert(Node* inputNode, int value) {
	if (inputNode == NULL) return false;
	else {
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->next = inputNode;
		newNode->prev = inputNode->prev;
		newNode->data = value;

		inputNode->prev = newNode;

		return true;
	}
}

bool List::remove(int value) {
	Node* searchNode = search_front(value);
	if (searchNode == NULL) return false;
	else {
		while (searchNode != NULL) {
			searchNode->prev->next = searchNode->next;
			searchNode->next->prev = searchNode->prev;
			
			free(searchNode);

			searchNode = search_front(value);
		}
	}
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

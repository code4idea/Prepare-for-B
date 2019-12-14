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

using namespace std;

typedef struct node {
	struct node* prev;
	struct node* next;
	int data;
}Node;

template <typename T>
struct List {
	Node* frontNode;
	Node* backNode;

	List();

	void push_front(T value);
	void push_back(T value);
	T pop_front();
	T pop_back();
	Node* search_front(T value);
	bool insert(Node* inputNode, T value);
	bool remove(T value);
	T front();
	T back();
	int empty();
};

template <typename T>
List<T>::List() {
	frontNode = NULL;
	backNode = NULL;
}

template <typename T>
void List<T>::push_front(T value) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->prev = NULL;
	newNode->next = frontNode;
	newNode->data = value;

	frontNode->prev = newNode;
	frontNode = newNode;
	if (backNode == NULL) backNode = newNode;
}

template <typename T>
void List<T>::push_back(T value) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->prev = backNode;
	newNode->next = NULL;
	newNode->data = value;

	if (backNode != NULL) backNode->next = newNode;
	backNode = newNode;
	if (frontNode == NULL) frontNode = newNode;
}

template <typename T>
T List<T>::pop_front() {
	if (empty()) return 0;

	Node* delNode = frontNode;
	T ret = frontNode->data;
	frontNode = frontNode->next;
	if (frontNode != NULL) frontNode->prev = NULL;
	free(delNode);
	return ret;
}

template <typename T>
T List<T>::pop_back() {
	if (empty()) return 0;

	Node* delNode = backNode;
	T ret = backNode->data;
	backNode = backNode->prev;
	if (backNode != NULL) backNode->next = NULL;
	free(delNode);
	return ret;
}

template <typename T>
Node* List<T>::search_front(T value) {
	Node* ret = frontNode;
	while (ret != NULL) {
		if (ret->data == value) break;
		ret = ret->next;
	}
	return ret;
}

template <typename T>
bool List<T>::insert(Node* inputNode, T value) {
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

template <typename T>
bool List<T>::remove(T value) {
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

template <typename T>
T List<T>::front() {
	return frontNode == NULL ? 0 : frontNode->data;
}

template <typename T>
T List<T>::back() {
	return backNode == NULL ? 0 : backNode->data;
}

template <typename T>
int List<T>::empty() {
	return (frontNode == backNode && frontNode == NULL) ? true : false;
}

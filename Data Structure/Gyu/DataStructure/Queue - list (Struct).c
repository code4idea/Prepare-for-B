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

template <typename T>
struct Node {
	Node<T>* next;
	T data;
};

template <typename T>
struct Queue {
	Node<T>* frontNode;
	Node<T>* backNode;

	Queue();

	void push(T value);
	T pop();
	T front();
	T back();
	bool empty();
};

template <typename T>
Queue<T>::Queue() {
	frontNode = backNode = NULL;
}

template <typename T>
void Queue<T>::push(T value) {
	Node<T>* newNode = (Node<T>*)malloc(sizeof(Node<T>));
	newNode->next = NULL;
	newNode->data = value;

	if (empty()) frontNode = newNode;
	else backNode->next = newNode;
	backNode = newNode;
}

template <typename T>
T Queue<T>::pop() {
	if (empty()) return 0;

	Node<T>* delNode = frontNode;
	T ret = frontNode->data;
	frontNode = frontNode->next;
	free(delNode);
	delNode->next = NULL;
	return ret;
}

template <typename T>
T Queue<T>::front() {
	return frontNode == NULL ? 0 : frontNode->data;
}

template <typename T>
T Queue<T>::back() {
	return backNode == NULL ? 0 : backNode->data;
}

template <typename T>
bool Queue<T>::empty() {
	return (frontNode == backNode && frontNode == NULL) ? true : false;
}

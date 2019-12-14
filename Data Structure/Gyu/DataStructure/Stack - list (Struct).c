/* 
** 스택 - 연결리스트 (구조체)
** ADT
** - push
** - pop
** - top
** - empty
*/

#include <malloc.h>
#define NULL 0

template <typename T>
struct Node
{
	Node<T>* next;
	T data;
};

template <typename T>
struct Stack
{
	Node<T>* topNode;

	Stack();

	void push(T value);
	T pop();
	T top();
	bool empty();
};

template <typename T>
Stack<T>::Stack() {
	topNode = NULL;
}

template <typename T>
void Stack<T>::push(T value) {
	Node<T>* newNode = (Node<T> *)malloc(sizeof(Node<T>));
	newNode->next = topNode;
	newNode->data = value;
	topNode = newNode;
};

template <typename T>
T Stack<T>::pop() {
	if (empty()) return 0;

	Node<T> * delNode = topNode;
	T ret = topNode->data;
	topNode = topNode->next;
	free(delNode);
	delNode->next = NULL;
	return ret;
}

template <typename T>
T Stack<T>::top() {
	return empty() ? 0 : topNode->data;
}

template <typename T>
bool Stack<T>::empty() {
	return topNode == NULL ? true : false;
}

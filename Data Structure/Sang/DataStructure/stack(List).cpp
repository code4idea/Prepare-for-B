/*
	Stack

	ADT	- size
		- push
		- pop
		- top
		- empty
*/

#include <iostream>

using namespace std;

template<typename T>
class Node
{
public:
	T data;
	Node* next;
};

template<typename T>
class _stack
{
private:
	int size;
	Node<T>* top;

public:
	_stack()
	{
		this->size = 0;
		this->top = NULL;
	}

	~_stack()
	{
		while (!this->empty()) this->pop();
	}

	void push(T _data)
	{
		Node<T>* newNode = new Node<T>();
		newNode->data = _data;
		newNode->next = top;
		top = newNode;
		this->size++;
	}

	void pop()
	{
		if (empty()) return;

		Node<T>* delNode = top;
		top = top->next;

		delete delNode;
		delNode = 
		this->size--;
	}

	bool empty()
	{
		if (this->top == NULL)
		{
			cout << "EMPTY" << endl;
			return true;
		}
		return false;
	}

	T _top()
	{
		if (empty()) return -1;

		return top->data;
	}

	int _size()
	{
		return this->size;
	}
};

int main(void)
{
	_stack<int> s = _stack<int>();

	for (int i = 5; i > 0; i--)
	{
		s.push(i);
		printf("Push(%d) , Top : %d\n", i, s._top());
	}
	printf("Size : %d\n", s._size());

	for (int i = 0; i < 6; i++)
	{
		if (!s.empty())
		{
			printf("pop() , Top : %d\n", s._top());
			s.pop();
		}
	}

	return 0;
}

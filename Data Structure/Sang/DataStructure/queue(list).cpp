/*
	Queue

	ADT	- size
		- push
		- pop
		- top
		- empty
		- front
*/

#include <iostream>
using namespace std;

template<typename T>
class Node
{
public:
	T data;
	Node<T>* next;
};

template<typename T>
class _queue
{
private:
	int size;
	Node<T>* frontNode;
	Node<T>* backNode;

public:
	_queue()
	{
		size = 0;
		frontNode = NULL;
		backNode = NULL;
	}

	~_queue()
	{

	}

	void _push(T _data)
	{
		Node<T>* newNode = new Node<T>();
		newNode->data = _data;
		if (frontNode == NULL)
		{
			frontNode = newNode;
		}
		else
		{
			backNode->next = newNode;
		}
		backNode = newNode;
		size++;
	}

	void _pop()
	{
		if (_empty()) return;

		Node<T>* delNode = frontNode;
		frontNode = frontNode->next;

		delete delNode;
		delNode = NULL;
		size--;
	}

	T _front()
	{
		if (_empty()) return -1;
	
		return frontNode->data;
	}

	bool _empty()
	{
		if (frontNode == NULL)
		{
			cout << "EMPTY" << endl;
			return true;
		}
		return false;
	}

	int _size()
	{
		return size;
	}

	void print() {
		Node<T>* nowNode = frontNode;
		while (nowNode != NULL) {
			cout << nowNode->data << " " << "-> ";
			nowNode = nowNode->next;
		}
		cout << endl;
	}
};



int main(void)
{
	_queue<int> q = _queue<int>();

	for (int i = 1; i <= 10; i++)
	{
		q._push(i);
		printf("Push(%d) , front : %d\n", i, q._front());
	}
	printf("size : %d\n", q._size());

	q.print();
	
	for (int i = 1; i <= 11; i++)
	{
		printf("Pop() , front : %d\n", q._front());
		q._pop();
	}

	return 0;
}

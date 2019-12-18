/*
	Doubly Linked List
	ADT	- size
		- push_back
		- pop_back
		- push_front
		- pop_front
		- pop(index)
		- push(index, data)
		- empty
*/

#include <iostream>

using namespace std;

template <typename T>
class Node
{
public:
	T data;
	Node<T>* next;
	Node<T>* prev;
};

template <typename T>
class _DLinkedList
{
private:
	int size;
	Node<T>* head;
	Node<T>* tail;

public:
	_DLinkedList()
	{
		size = 0;
		head = NULL;
		tail = NULL;
	}

	void _push_back(T _data)
	{
		Node<T> *newNode = new Node<T>();
		newNode->data = _data;
		if(head == NULL)
		{
			head = newNode;
		}
		else
		{
			newNode->prev = tail;
			tail->next = newNode;
		}
		tail = newNode;
		size++;
	}

	T _pop_back()
	{
		if(_empty()) 
		{
			cout << "EMPTY" << endl;
			return -1;
		}

		Node<T> *delNode = tail;
		T res = delNode->data;

		if(size!=1)
		{
			tail->prev->next = delNode;
			tail = delNode->prev;
		}
		
		delete delNode;
		delNode = NULL;
		size--;
		return res;
	}

	void _push_front(T _data)
	{
		Node<T> *newNode = new Node<T>();
		newNode->data = _data;
		if(head == NULL)
		{
			tail = newNode;
		}
		else
		{
			newNode->next = head;
			head->prev = newNode;
		}
		head = newNode;
		size++;
	}

	T _pop_front()
	{
		if(_empty()) 
		{
			cout << "EMPTY" << endl;
			return -1;
		}

		Node<T> *delNode = head;
		T res = delNode->data;

		if(size != 1)
		{
			head->next->prev = delNode;
			head = delNode->next;
		}
		
		delete delNode;
		delNode = NULL;
		size--;
		return res;
	}

	void _push(int index, T _data)
	{
		Node<T> *newNode = new Node<T>();
		if(index == 0)
		{
			_push_front(_data);
		}
		else if(index == size)
		{
			_push_back(_data);
		}
		else if(index > size)
		{
			cout <<"PUSH INDEX NG"<<endl;
			return;
		}
		newNode->data = _data;
		Node<T> *tempNode = head;
		for(int i=0;i<index;i++)
		{
			tempNode = tempNode->next;
		}
		tempNode->next->prev = newNode;
		newNode->next = tempNode->next;
		newNode->prev = tempNode;
		tempNode->next = newNode;

		size++;
	}

	T _pop(int index)
	{
		if(_empty()) 
		{
			cout << "EMPTY" << endl;
			return -1;
		}

		if(index == 0)
		{
			_pop_front();
		}
		else if(index == size)
		{
			_pop_back();
		}
		else if(index > size)
		{
			cout <<"POP INDEX NG"<<endl;
			return -1;
		}

		Node<T> *delNode = head;
		for(int i=0;i<index;i++)
		{
			delNode = delNode->next;
		}

		T res = delNode->data;
		delNode->next->prev = delNode->prev;
		delNode->prev->next = delNode->next;
		
		delete delNode;
		delNode = NULL;
		size--;
		return res;
	}

	bool _empty()
	{ return size == 0 ? true : false;}

	int _size()
	{ return this->size;}

	void print()
	{
		Node<int>* temp = head;
		for(int i =0;i<size;i++)
		{
			cout << temp->data << " ";
			temp= temp->next;
		}
	}

};

int main(void)
{
	_DLinkedList<int> DLL = _DLinkedList<int>();

	for(int i=6;i<=10;i++)
	DLL._push_back(i);

	for(int i=5;i>=0;i--)
	DLL._push_front(i);

	//for(int i=0;i<11;i++)
	//cout << DLL._pop_front() << " ";

	DLL._pop(3);
	DLL.print();

	return 0;
}

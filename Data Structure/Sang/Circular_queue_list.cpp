#include <iostream>

using namespace std;

template <typename T>
class Node
{
public:
	T data;
	Node<T>* next;
};

template <typename T>
class queue
{
private:
	Node<T>* front;
	Node<T>* rear;
	int size;

public:
	queue()
	{
		front = new Node<T>();
		rear = new Node<T>();
		size = 0;
	}

	bool isfull()
	{
		if (size >= 50)
		{
			cout << "FULL" << endl;
			return true;
		}
		else return false;
	}

	bool isempty()
	{
		if (size <= 0)
		{
			cout << "EMPTY" << endl;
			return true;
		}
		else return false;
	}

	int _size()
	{
		return size;
	}

	bool push(T data)
	{
		if (this->isfull())	return false;

		Node<T>* tmp = new Node<T>();

		if (size == 0)
		{
			front->data = data;
			rear = front;
			front->next = NULL;
		}
		else
		{
			tmp->data = data;
			tmp->next = rear->next;
			rear->next = tmp;
			rear = tmp;
		}
		size++;

		return true;
	}

	bool pop()
	{
		if (this->isempty()) return false;

		front = front->next;
		rear->next = front;

		size--;
		return true;
	}

	T _front()
	{
		if (isempty()) return false;
		return front->data;
	}

	T _back()
	{
		if (isempty()) return false;
		return rear->data;
	}
};

int main(void)
{
	queue<int> q = queue<int>();

	q.push(1);
	cout << "1 : " << q._back() << endl;
	q.push(2);
	cout << "2 : " << q._back() << endl;
	q.push(3);
	cout << "3 : " << q._back() << endl;
	q.push(4);
	cout << "4 : " << q._back() << endl;
	q.pop();
	q.pop();
	q.push(5);
	cout << "5 : " << q._back() << endl;
	cout << "size 3 : " << q._size() << endl;
	q.push(6);
	cout << "6 : " << q._back() << endl;
	q.push(7);
	cout << "7 : " << q._back() << endl;

	cout << "size : " << q._size() << endl;

	while (!q.isempty())
	{
		cout << q._front() << endl;
		q.pop();
	}

	return 0;
}

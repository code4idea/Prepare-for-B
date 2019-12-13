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
class stacks
{
private:
	Node<T>* top = new Node<T>();
	int size;

public:
	stacks()
	{
		size = 0;
	}

	bool isfull()
	{
		if (size >= 50) return true;
		else return false;
	}

	bool isempty()
	{
		if (size <= 0) return true;
		else return false;
	}

	int _size()
	{
		return size;
	}

	bool push(T data)
	{
		if (this->isfull()) return false;

		Node<T>* tmp = new Node<T>();

		if (size == 0)
		{
			tmp->data = data;
			top->next = tmp;
		}
		else
		{
			tmp->data = data;
			tmp->next = top->next;
			top->next = tmp;
		}
		size++;
	}

	bool pop()
	{
		if (this->isempty()) return false;
		Node<T>* tmp = top->next;
		top->next = top->next->next;
		delete tmp;
		size--;
	}

	T tops()
	{
		if (isempty()) return false;
		return top->next->data;
	}
};

int main(void)
{
	stacks<int> s = stacks<int>();

	s.push(3);
	s.push(7);
	s.push(67);
	cout << s.tops() << endl;
	s.pop();
	cout << s.tops() << endl;
	cout << s._size() << endl;

	return 0;
}

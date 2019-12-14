/*
	Vector

	ADT	- size
		- push_back
		- pop_back
		- empty
		- clear
		- []
*/

#include <iostream>
using namespace std;

template<typename T>
class _vector
{
private:
	T capacity;
	T* data;
	int size;

public:
	_vector()
	{
		size = 0;
		capacity = 10;
		data = new T[capacity];
	}

	~_vector()
	{
		delete[] data;
		data = NULL;
	}

	void _push_back(T _data)
	{
		if (size == capacity)
		{
			capacity *= 2;
			T* tmp = new T[capacity];

			for (int i = 0; i < size; i++)
				tmp[i] = data[i];

			delete[] data;
			data = NULL;

			data = new T[capacity]; //재 선언을 하면안되고 메모리 할당만 해야된다.
			for (int i = 0; i < size; i++)
				data[i] = tmp[i];

			delete[] tmp;
			tmp = NULL;
		}
		data[size++] = _data;
	}

	void _pop_back()
	{
		if (_empty())
		{
			cout << "EMPTY" << endl;
			return;
		}

		size--;
	}

	void _clear()
	{
		delete[] data;
		data = NULL;
		capacity = 10;
		data = new T[capacity];
		size = 0;
	}

	bool _empty()
	{
		return size == 0 ? true : false;
	}

	int _size()
	{
		return size;
	}

	T& operator[](int i)
	{
		return data[i];
	}
};



int main(void)
{
	_vector<int> v = _vector<int>();

	for (int i = 1; i <= 105; i++)
	{
		v._push_back(i);
	}
	v._pop_back();
	v._pop_back();

	for (int i = 0; i < v._size(); i++)
		cout << v[i] << endl;

	v._clear();
	v._pop_back();
	v._pop_back();

	for (int i = 105; i >= 1; i--)
	{
		v._push_back(i);
	}
	for (int i = 0; i < v._size(); i++)
		cout << v[i] << endl;

	for (int i = 1; i <= 105; i++)
	{
		v._pop_back();
	}

	cout << "Size : " << v._size() << endl;

	return 0;
}

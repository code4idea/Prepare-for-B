#include <iostream>

using namespace std;

template <typename T>
class _vector
{
private:
	int _capacity;
	T* data;
	int back;

public:
	_vector()
	{
		_capacity = 10;
		data = new T[_capacity];
		back = 0;
	}

	~_vector()
	{
		delete[] data;
	}

	bool isempty()
	{
		if (back == 0) return true;
		else return false;
	}

	bool isfull()
	{
		if (back >= 100) return true;
		else return false;
	}

	void push_back(T val)
	{
		if (isfull())
		{
			cout << "FULL" << endl;
			return;
		}

		if (back == _capacity)
		{
			_capacity *= 2;
			T* tmp = new T[_capacity];
			for (int i = 0; i < back; i++)
				tmp[i] = data[i];

			delete[] data;
			data = new T[_capacity];

			for (int i = 0; i < back; i++)
				data[i] = tmp[i];

			delete[] tmp;
		}
		data[back++] = val;
	}

	void pop_back()
	{
		if (isempty())
		{
			cout << "EMPTY" << endl;
			return;
		}

		back--;
	}

	int size()
	{
		return back;
	}

	void clear()
	{
		_capacity = 10;
		back = 0;
		delete[] data;

		data = new T[_capacity];
	}

	T &operator [](int i) {
		return data[i];
	}
};

int main(void)
{
	_vector<int> v;

	for (int i = 1; i <= 105; i++)
	{
		v.push_back(i);
	}
	v.pop_back();
	v.pop_back();

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << endl;

	v.clear();
	v.pop_back();
	v.pop_back();

	for (int i = 105; i >= 1; i--)
	{
		v.push_back(i);
	}
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << endl;

	for (int i = 1; i <= 105; i++)
	{
		v.pop_back();
	}

	return 0;
}

#include <iostream>

using namespace std;

void _swap(int *data, int a, int b)
{
	int tmp;
	tmp = data[a];
	data[a] = data[b];
	data[b] = tmp;
}

template <typename T>
class maxheap
{
private:
	T data[11];
	int size;
public:
	maxheap()
	{
		size = 0;
	}
	~maxheap()
	{}

	bool isFull()
	{
		if (size >= 10)
		{
			cout << "FULL" << endl;
			return true;
		}
		return false;
	}

	bool isEmpty()
	{
		if (size <= 0)
		{
			cout << "EMPTY" << endl;
			return true;
		}
		return false;
	}

	void push(T _data)
	{
		if (isFull()) return;

		size++;
		data[size] = _data;

		int child = size;
		int parent = child / 2;

		while (data[child] > data[parent] && parent >= 1)
		{
			_swap(data, child, parent);
			child = parent;
			parent = child / 2;
		}
	}

	T pop()
	{
		if (isEmpty()) return -1;

		T res = data[1];

		data[1] = data[size--];
		
		int parent = 1;
		int child = parent * 2;

		if (child + 1 <= size && data[child] < data[child + 1]) child++;

		while (data[child] > data[parent] && child <= size)
		{
			_swap(data, child, parent);
			parent = child;
			child = child * 2;
			if (child + 1 <= size && data[child] < data[child + 1]) child++;
		}

		return res;
	}

	int _size()
	{
		return size;
	}
};

int main(void)
{
	maxheap<int> mh = maxheap<int>();

	mh.push(3);
	mh.push(6);
	mh.push(4);
	mh.push(1);
	mh.push(2);
	mh.push(5);
	mh.push(7);
	mh.push(10);
	mh.push(9);
	mh.push(8);
	mh.push(22);

	cout << "size : " << mh._size() << endl;

	for (int i = 0; i < 10; i++)
	{
		cout << mh.pop() << endl;
	}

	return 0;
}

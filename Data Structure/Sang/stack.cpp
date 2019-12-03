#include <iostream>

using namespace std;

template <typename T>
class stacks
{
private:
	T s[50];
	int top;
public:
	stacks()
	{
		this->s[50] = { 0, };
		this->top = 0;
	}

	bool isfull()
	{
		if (this->top >= 50) return true;
		else return false;
	}

	bool isempty()
	{
		if (this->top <= 0) return true;
		else return false;
	}

	int size()
	{
		return this->top;
	}

	bool push(T data)
	{
		if (this->isfull()) return false;

		this->s[this->top++] = data;
	}

	bool pop()
	{
		if (this->isempty()) return false;

		this->top--;
	}

	T tops()
	{
		if (isempty()) return false;
		return this->s[this->top-1];
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
	cout << s.size() << endl;


	return 0;
}

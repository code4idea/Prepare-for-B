#include <iostream>

using namespace std;

#define MAX 5

template <typename T>
class queue
{
private:
	T q[5];
	int front;
	int rear;

public:
	queue()
	{
		this->q[MAX] = { 0, };
		this->front = MAX-1;
		this->rear = MAX - 1;
	}

	bool isempty()
	{
		if (front == rear) return true;
		else return false;
	}

	bool isfull()
	{
		if (front == (rear+1) % MAX) return true;
		else return false;
	}

	void push(T data)
	{
		if (isfull())
		{
			cout << "FULL" << endl;
			return;
		}
		rear = (rear + 1) % MAX;
		q[rear] = data;
	}

	void pop()
	{
		if (isempty())
		{
			cout << "EMPTY" << endl;
			return;
		}
		front = (front+1) % MAX;
	}

	T _front()
	{
		if (isempty())
		{
			cout << "EMPTY" << endl;
			return -1;
		}
		return q[(front+1)%MAX];
	}

	T _back()
	{
		if (isempty())
		{
			cout << "EMPTY" << endl;
			return -1;
		}
		return q[rear];
	}

	int size()
	{
		int res = front >= rear ? rear - front + MAX : rear - front;
		return res;
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
	cout << "size 3 : " << q.size() << endl;
	q.push(6);
	cout << "6 : " << q._back() << endl;
	q.push(7);
	cout << "6 : " << q._back() << endl;

	cout << "size : " << q.size() << endl;

	while (!q.isempty())
	{
		cout << q._front() << endl;
		q.pop();
	}
	return 0;
}

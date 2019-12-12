/* 
** 큐 - 배열 (구조체)
** ADT
** - push
** - pop
** - front
** - back
** - empty
*/

#define MAX_QUEUE 50

typedef struct queue {
	int frontIndex;
	int backIndex;
	int data[MAX_QUEUE];
	
	void init();
	bool push(int value);
	int pop();
	int front();
	int back();
	int empty();

	int full();
} Queue;

void Queue::init() {
	frontIndex = 0;
	backIndex = 0;
}

bool Queue::push(int value) {
	if (!full()) data[++backIndex] = value;
	return !full() ? true : false;
}

int Queue::pop() {
	return empty() ? 0 : data[frontIndex++];
}

int Queue::front() {
	return data[frontIndex];
}

int Queue::back() {
	return data[backIndex];
}

int Queue::empty() {
	return frontIndex == backIndex ? true : false;
}

int Queue::full() {
	return backIndex + 1 == MAX_QUEUE ? true : false;
}

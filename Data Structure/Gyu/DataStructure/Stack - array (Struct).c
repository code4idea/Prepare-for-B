/* 
** 스택 - 배열 (구조체)
** ADT
** - push
** - pop
** - peak
** - isEmpty
*/

#define MAX_STACK 50

typedef struct stack {
	int topIndex;
	char data[MAX_STACK];

	void initStack();
	bool push(char value);
	char pop();
	char top();
	bool isEmpty();

	bool isFull();
} Stack;

void Stack::initStack() {
	topIndex = -1;
}

bool Stack::push(char value) {
	if (!isFull()) data[++topIndex] = value;
	return !isFull();
}

char Stack::pop() {
	return isEmpty() ? 0 : data[topIndex--];
}

char Stack::top() {
	return data[topIndex];
}

bool Stack::isEmpty() {
	return topIndex == -1 ? true : false;
}

bool Stack::isFull() {
	return topIndex+1 == MAX_STACK ? true : false;
}

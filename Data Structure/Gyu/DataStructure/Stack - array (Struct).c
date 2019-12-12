/* 
** 스택 - 배열 (구조체)
** ADT
** - push
** - pop
** - top
** - empty
*/

#define MAX_STACK 50

typedef struct stack {
	int topIndex;
	char data[MAX_STACK];

	void init();
	bool push(char value);
	char pop();
	char top();
	bool empty();

	bool full();
} Stack;

void Stack::init() {
	topIndex = -1;
}

bool Stack::push(char value) {
	if (!full()) data[++topIndex] = value;
	return !full();
}

char Stack::pop() {
	return empty() ? 0 : data[topIndex--];
}

char Stack::top() {
	return data[topIndex];
}

bool Stack::empty() {
	return topIndex == -1 ? true : false;
}

bool Stack::full() {
	return topIndex+1 == MAX_STACK ? true : false;
}

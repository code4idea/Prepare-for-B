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
	int top;
	char data[MAX_STACK];

	void initStack();
	bool push(char value);
	char pop();
	char peak();
	bool isEmpty();

	bool isFull();
} Stack;

void Stack::initStack() {
	top = -1;
}

bool Stack::push(char value) {
	if (!isFull()) data[++top] = value;
	return !isFull();
}

char Stack::pop() {
	return isEmpty() ? 0 : data[top--];
}

char Stack::peak() {
	return data[top];
}

bool Stack::isEmpty() {
	return top == -1 ? true : false;
}

bool Stack::isFull() {
	return top+1 == MAX_STACK ? true : false;
}

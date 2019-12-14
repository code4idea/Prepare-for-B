/* 
** 스택 - 배열 (구조체)
** ADT
** - push
** - pop
** - top
** - empty
*/

#define MAX_STACK 50

template <typename T>
struct Stack {
	int topIndex;
	T data[MAX_STACK];

	Stack();

	bool push(char value);
	T pop();
	T top();
	bool empty();

	bool full();
};

template<typename T>
Stack<T>::Stack() {
	topIndex = -1;
}

template<typename T>
bool Stack<T>::push(char value) {
	if (!full()) data[++topIndex] = value;
	return !full();
}

template<typename T>
T Stack<T>::pop() {
	return empty() ? 0 : data[topIndex--];
}

template<typename T>
T Stack<T>::top() {
	return data[topIndex];
}

template<typename T>
bool Stack<T>::empty() {
	return topIndex == -1 ? true : false;
}

template<typename T>
bool Stack<T>::full() {
	return topIndex + 1 == MAX_STACK ? true : false;
}

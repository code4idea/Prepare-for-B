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

template <typename T>
struct Queue {
	int frontIndex;
	int backIndex;
	T data[MAX_QUEUE];

	Queue();

	bool push(T value);
	T pop();
	T front();
	T back();
	bool empty();

	bool full();
};

template <typename T>
Queue<T>::Queue() {
	frontIndex = 0;
	backIndex = 0;
}

template <typename T>
bool Queue<T>::push(T value) {
	if (!full()) data[backIndex++] = value;
	return !full() ? true : false;
}

template <typename T>
T Queue<T>::pop() {
	return empty() ? 0 : data[frontIndex++];
}

template <typename T>
T Queue<T>::front() {
	return data[frontIndex];
}

template <typename T>
T Queue<T>::back() {
	return data[backIndex];
}

template <typename T>
bool Queue<T>::empty() {
	return frontIndex == backIndex ? true : false;
}

template <typename T>
bool Queue<T>::full() {
	return backIndex + 1 == MAX_QUEUE ? true : false;
}

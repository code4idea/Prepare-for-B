/* 
** 벡터 - 배열 (구조체)
** ADT
** - push_back
** - pop_back
** - clear
** - size
** - []
** - empty
*/

#include <malloc.h>
#define NULL 0

template <typename T>
struct Vector {
	size_t vectorSize;
	size_t vectorCapacity;

	T* data;
	int count;

	Vector();

	void push_back(T value);
	T pop_back();
	void clear();
	size_t size();
	T& operator [] (int index);
	bool empty();
};

template <typename T>
Vector<T>::Vector() {
	vectorSize = 0;
	vectorCapacity = 0;
	data = NULL;
}

template <typename T>
void Vector<T>::push_back(T value) {
	if (vectorSize == vectorCapacity) {
		vectorCapacity = vectorCapacity == 0 ? 1 : vectorCapacity * 2;
		data = (T*)realloc(data, vectorCapacity * sizeof(T*));
	}

	data[vectorSize++] = value;
}

template <typename T>
T Vector<T>::pop_back() {
	return data[--vectorSize];
}

template <typename T>
void Vector<T>::clear() {
	free(data);
	data = NULL;
}

template <typename T>
size_t Vector<T>::size() {
	return vectorSize;
}

template <typename T>
T& Vector<T>::operator [] (int index) {
	return data[index];
}

template <typename T>
bool Vector<T>::empty() {
	return vectorCapacity == 0 ? true : false;
}

/* 
** 유니온 파인드 - 연결리스트 (구조체-C언어)
** ADT
** - find
** - union
** - isSame
*/

#include <malloc.h>
#define NULL 0

template <typename T>
struct Vector {
	size_t vectorSize;
	size_t vectorCapacity;

	T* data;
	int count;

	Vecotr() {
		vectorSize = 0;
		vectorCapacity = 0;
		data = NULL;
	}

	void push_back(T value) {
		if (vectorSize == vectorCapacity) {
			vectorCapacity = vectorCapacity == 0 ? 1 : vectorCapacity * 2;
			data = (T*)realloc(data, vectorCapacity * sizeof(T*));
		}
		data[vectorSize++] = value;
	}

	T pop_back() {
		return data[--vectorSize];
	}

	void clear() {
		free(data);
		data = NULL;
	}

	size_t size() {
		return vectorSize;
	}

	T& operator [] (int index) {
		return data[index];
	}

	bool empty() {
		return vectorCapacity == 0 ? true : false;
	}
};

template <typename T>
struct UnionFind {
	Vector<int> parent;
	Vector<int> level;

	UnionFind(int groupNumber);
	int find(int member);
	void merge(int member1, int member2);
  bool isSame(int member1, int member2);
};

template <typename T>
UnionFind<T>::UnionFind(int groupNumber) {
	parent.clear();
	level.clear();
	for (int i = 0; i < groupNumber; i++) {
		parent.push_back(i);
		level.push_back(1);
	}
}

template <typename T>
int UnionFind<T>::find(int member) {
	if (member == parent[member]) return u;
	else return parent[member] = find(parent[member]);
}

template <typename T>
void UnionFind<T>::merge(int member1, int member2) {
	member1 = find(member1);
	member2 = find(member2);

	if (member1 == member2) return;

	if (level[member1] < level[member2]) {
		int temp = member1;
		member1 = member2;
		member2 = temp;
	}

	parent[member2] = member1;

	if (level[member1] == level[member2]) ++level[member1];
}

template <typename T>
bool UnionFind<T>::isSame(int member1, int member2){
  return find(member1) == find(member2);
}

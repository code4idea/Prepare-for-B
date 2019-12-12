#include <iostream>

using namespace std;

#define MAX_STACK 50

typedef struct stack {
	char data[50];
	int top;
} Stack;

Stack s;

void initStack() {
	s.top = 0;
}

bool isEmpty() {
	if (s.top == 0) return true;
	else return false;
}

bool isFull() {
	if (s.top == MAX_STACK) return true;
	else return false;
}

bool pushStack(char c) {
	if (isFull()) {
		return false;
	}
	else {
		s.data[s.top] = c;
		s.top++;
		return true;
	}
}

bool popStack() {
	if (isEmpty()) {
		return false;
	}
	else {
		s.top--;
	}
}

char isTop() {
	return s.data[s.top];
}

int main() {
	int T;
	char inputStr[51];
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> inputStr;

		initStack();
		for (int i = 0; i < 50; i++) {
			char nowC = inputStr[i];
			if (nowC == '\0') break;
			
			if (!isEmpty()) {
				if (isTop() == '(' && nowC == ')') popStack();
				else pushStack(nowC);
			}
			else {
				pushStack(nowC);
			}
		}

		if (isEmpty()) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}

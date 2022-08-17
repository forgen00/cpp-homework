#include <iostream>

#include "Stack.h"

Stack empty_stack() {
	Stack st;
	st.top = -1;
	st.size = 0;
	return st;
}

void push(Stack& st, int number) {
	if (st.size == MAX_SIZE) {
		std::cerr << "Stack overflow\n";
		exit(0);
	}
	
	else {
		++st.top;
		++st.size;
		st.arr[st.top] = number;
	}
}

int top(const Stack& st) {
	return st.arr[st.top];
}

void pop(Stack& st) {
	if (st.size == 0) {
		std::cerr << "Stack underflow\n";
		exit(0);
	}
	else {
		--st.size;
		--st.top;
	}
}

bool is_empty(const Stack& st) {
	return st.size == 0;
}

bool is_full(const Stack& st) {
	return st.size == MAX_SIZE;
}
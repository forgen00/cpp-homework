#include <iostream>

#include "Stack.h"
#include "headers/graphics.h"

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

void StackVisual(const Stack& st, const int WIDTH, const int HEIGHT) {
	int left = WIDTH - 1400, top = HEIGHT - 200, right = WIDTH - 300, bottom = HEIGHT - 125;
	setfillstyle(SOLID_FILL, WHITE);
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 60);
	setcolor(RED);
	setbkcolor(WHITE);
	for (int i = 0; i < st.size; ++i) {
		bar(left, top, right, bottom);
		rectangle(left, top, right, bottom);
		outtextxy((left + right) / 2, top + 10, std::to_string(st.arr[i]).c_str());
		top -= 75; bottom -= 75;
	}
}
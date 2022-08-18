#include <iostream>
#include <string>

#include "MyButton.h"
#include "headers/graphics.h"

MyBtn controls[N_CONTROLS];

void create_control(int left, int top, int right, int bottom, int type) {

	//Создаем кнопку
	MyBtn control;
	control.left = left;
	control.top = top;
	control.right = right;
	control.bottom = bottom;

	//type - именованная константа, она же индекс для массива controls
	controls[type] = control;
}

void drawButtons(const int WIDTH, const int HEIGHT) {
	int button_width = WIDTH / 11;
	int button_left = 0;
	setfillstyle(SOLID_FILL, WHITE);
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 60);
	setcolor(RED);
	setbkcolor(WHITE);
	for (int i = 0; i <= N_CONTROLS; ++i) {
		if (i != 10) {
			bar(controls[i].left, controls[i].top, controls[i].right, controls[i].bottom);
			outtextxy((controls[i].left + controls[i].right) / 2, HEIGHT - 70, std::to_string(i).c_str());
			rectangle(controls[i].left, controls[i].top, controls[i].right, controls[i].bottom);
			button_left += button_width;
		}
		else {
			bar(controls[i].left, controls[i].top, controls[i].right, controls[i].bottom);
			outtextxy(controls[i].left, HEIGHT - 70, "Delete");
			rectangle(controls[i].left, controls[i].top, controls[i].right, controls[i].bottom);
		}
	}
}

int select_control() {
	int x = mousex();
	int y = mousey();

	for (int i = 0; i < N_CONTROLS; ++i) {
		if (x >= controls[i].left && x <= controls[i].right
			&& y >= controls[i].top && y <= controls[i].bottom) {
			return i;
		}
	}
	return NONE;
}
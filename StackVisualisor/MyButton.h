#ifndef _CONTROL_H
#define _CONTROL_H

//Структура "кнопка"
struct MyBtn {
	int left;
	int top;
	int right;
	int bottom;
};

//Именованные константы для кнопок
enum control_values {
	NONE = -1, BUTTON_1, BUTTON_2, BUTTON_3, BUTTON_4, BUTTON_5, BUTTON_6, BUTTON_7, BUTTON_8, BUTTON_9, N_CONTROLS
};

void create_control(int left, int top, int right, int bottom, int type);
void drawButtons(const int WIDTH, const int HEIGHT);
int select_control();

#endif
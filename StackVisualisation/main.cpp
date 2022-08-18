#include <iostream>
#include <string>

#include "Stack.h"
#include "MyButton.h"
#include "headers/graphics.h"

const int WIDTH = 1700;
const int HEIGHT = 1000;

int main() {
    initwindow(WIDTH, HEIGHT, "Визуализация стека", 0, 0); // режим 2-страниц
     // видима страница 0, активна страница 1
    int t = 0; // номер кадра (время)
    
    int button_width = WIDTH / 11;
    int button_left = 0;
    for (int i = 0; i <= N_CONTROLS; ++i) {
        create_control(button_left, HEIGHT - 100, button_left + button_width, HEIGHT, i);
        button_left += button_width;
    }

    bool fl = false;
    Stack s = empty_stack();
    
    while (1)
    {
        setbkcolor(BLACK); // цвет фона
        clearviewport(); // закраска текущей страницы цветом фона
        ++t;
        // рисование изображения
        rectangle(300, 125, WIDTH - 300, 875);
        drawButtons(WIDTH, HEIGHT);
        if (is_full(s)) {
            setbkcolor(BLACK);
            outtextxy(50, HEIGHT / 2, "Stack");
            outtextxy(50, HEIGHT / 2 + 30, "is");
            outtextxy(50, HEIGHT / 2 + 60, "full!");
        }
        StackVisual(s, WIDTH, HEIGHT);
        
        

        if (mousebuttons() == 1) {
            int button = select_control();

            if (button == BUTTON_1) {
                if (is_full(s)) {
                    std::cout << "Stack is full\n";
                }

                else {
                    push(s, BUTTON_1);
                    fl = false;
                }
            }
            if (button == BUTTON_2) {
                if (is_full(s)) {
                    std::cout << "Stack is full\n";
                }

                else {
                    push(s, BUTTON_2);
                    fl = false;
                }
            }
            if (button == BUTTON_3) {
                if (is_full(s)) {
                    std::cout << "Stack is full\n";
                }

                else {
                    push(s, BUTTON_3);
                    fl = false;
                }
            }
            if (button == BUTTON_4) {
                if (is_full(s)) {
                    std::cout << "Stack is full\n";
                }

                else {
                    push(s, BUTTON_4);
                    fl = false;
                }
            }
            if (button == BUTTON_5) {
                if (is_full(s)) {
                    std::cout << "Stack is full\n";
                }

                else {
                    push(s, BUTTON_5);
                    fl = false;
                }
            }
            if (button == BUTTON_6) {
                if (is_full(s)) {
                    std::cout << "Stack is full\n";
                }

                else {
                    push(s, BUTTON_6);
                    fl = false;
                }
            }
            if (button == BUTTON_7) {
                if (is_full(s)) {
                    std::cout << "Stack is full\n";
                }

                else {
                    push(s, BUTTON_7);
                    fl = false;
                }
            }
            if (button == BUTTON_8) {
                if (is_full(s)) {
                    std::cout << "Stack is full\n";
                }

                else {
                    push(s, BUTTON_8);
                    fl = false;
                }
            }
            if (button == BUTTON_9) {
                if (is_full(s)) {
                    std::cout << "Stack is full\n";
                }

                else {
                    push(s, BUTTON_9);
                    fl = false;
                }
            }
            if (button == BUTTON_10) {
                if (is_full(s)) {
                    std::cout << "Stack is full\n";
                }

                else {
                    push(s, BUTTON_10);
                    fl = false;
                }
            }
            if (button == BUTTON_11) {
                if (is_empty(s)) {
                    std::cout << "Stack is empty\n";
                    fl = true;
                }

                else {
                    pop(s);
                    fl = false;
                }
            }
        }

        if (fl) {
            setbkcolor(BLACK);
            outtextxy(1500, HEIGHT / 2, "Stack");
            outtextxy(1500, HEIGHT / 2 + 30, "is");
            outtextxy(1500, HEIGHT / 2 + 60, "empty!");
        }

        
        swapbuffers(); // делаем активную страницу видимой
        delay(30); // задержка на 1/30 секунды
        if (kbhit()) break; // если нажата клавиша - завершить работу
    }
    closegraph();
}

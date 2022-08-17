#include <iostream>
#include <string>

#include "Stack.h"
#include "MyButton.h"
#include "headers/graphics.h"

const int WIDTH = 1600;
const int HEIGHT = 1000;
const int BUTTON_WIDTH = WIDTH / 10;

int main() {
    initwindow(WIDTH, HEIGHT, "Визуализация стека", 0, 0, true); // режим 2-страниц
     // видима страница 0, активна страница 1
    int t = 0; // номер кадра (время)
    
    int button_width = WIDTH / 10;
    int button_left = 0;
    for (int i = 0; i < N_CONTROLS; ++i) {
        create_control(button_left, HEIGHT - 100, button_left + button_width, HEIGHT, i);
        button_left += button_width;
    }

    
    while (1)
    {
        setbkcolor(BLACK); // цвет фона
        clearviewport(); // закраска текущей страницы цветом фона
        ++t;
        // рисование изображения
        drawButtons(WIDTH, HEIGHT);
        
        
        swapbuffers(); // делаем активную страницу видимой
        delay(30); // задержка на 1/30 секунды
        if (kbhit()) break; // если нажата клавиша - завершить работу
    }
    closegraph();
}
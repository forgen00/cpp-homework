#include <iostream>
#include <string>

#include "Stack.h"
#include "MyButton.h"
#include "headers/graphics.h"

const int WIDTH = 1700;
const int HEIGHT = 1000;

int main() {
    initwindow(WIDTH, HEIGHT, "������������ �����", 0, 0); // ����� 2-�������
     // ������ �������� 0, ������� �������� 1
    int t = 0; // ����� ����� (�����)
    
    int button_width = WIDTH / 11;
    int button_left = 0;
    for (int i = 0; i <= N_CONTROLS; ++i) {
        create_control(button_left, HEIGHT - 100, button_left + button_width, HEIGHT, i);
        button_left += button_width;
    }

    
    while (1)
    {
        setbkcolor(BLACK); // ���� ����
        clearviewport(); // �������� ������� �������� ������ ����
        ++t;
        // ��������� �����������
        drawButtons(WIDTH, HEIGHT);
        
        
        swapbuffers(); // ������ �������� �������� �������
        delay(30); // �������� �� 1/30 �������
        if (kbhit()) break; // ���� ������ ������� - ��������� ������
    }
    closegraph();
}
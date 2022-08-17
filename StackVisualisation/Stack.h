#ifndef _STACK_H
#define _STACK_H

const int MAX_SIZE = 100;

struct Stack {
	int arr[MAX_SIZE];
	int top;				//������ ������� �����
	int size;				//����������� ������ �����
};

Stack empty_stack();				//������ ������ ����
void push(Stack& st, int number);	//���������� ����� � ����
int top(const Stack& st);			//���������� ������� �����
void pop(Stack& st);				//���������� �� ����� �������, ������� �����������
bool is_empty(const Stack& st);		//���������� true, ���� ���� ������
bool is_full(const Stack& st);		//���������� true, ���� ���� ������



#endif
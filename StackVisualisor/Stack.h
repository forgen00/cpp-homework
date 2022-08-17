#ifndef _STACK_H
#define _STACK_H

const int MAX_SIZE = 100;

struct Stack {
	int arr[MAX_SIZE];
	int top;				//Индекс вершины стека
	int size;				//Фактический размер стека
};

Stack empty_stack();				//Создаёт пустой стек
void push(Stack& st, int number);	//Добавление числа в стек
int top(const Stack& st);			//Возвращать вершину стека
void pop(Stack& st);				//Выкидывает из стека вершину, вершина обновляется
bool is_empty(const Stack& st);		//Возвращает true, если стек пустой
bool is_full(const Stack& st);		//Возвращает true, если стек полный



#endif
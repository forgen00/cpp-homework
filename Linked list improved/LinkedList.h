#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

class List {
private:
	struct Node {
		int value;
		Node* next;
		Node* prev;
	}*head;

public:
	List();								//Конструктор
	List(const List& other);					//Конструктор копирования
	~List();							//Деконструктор (удаляет список)
	Node* find_node(int value);
	void push_front(int value);
	void push_back(int value);
	void remove(Node* target);
	void print();
};

#endif

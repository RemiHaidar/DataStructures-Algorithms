#include <iostream>
#include <stdlib.h>

class Stack
{
private:
	int* stack;
	size_t size;
	void Realloc();
public:
	Stack();
	void push(int);
	void pop();
	int peek();
	bool empty();
	int& operator[](unsigned int);
};
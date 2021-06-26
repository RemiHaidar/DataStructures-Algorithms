#include <stdlib.h>

class Stack
{
private:
	int* stack;
	size_t size;
public:
	Stack();
	~Stack();
	void push(int);
	void pop();
	int peek();
	bool empty();
	int& operator[](unsigned int);
};
#include "Stack.hpp"

Stack::Stack()
{
	size = 0;
}

void Stack::push(int value)
{
	int* newStack = new int[size + 1];

	for (int i = 0; i < size; i++)
		newStack[i] = stack[i];

	delete[] stack;
	stack = newStack;
	size++;

	stack[size - 1] = value;
}

void Stack::pop()
{
	if (size > 0)
	{
		int* newStack = new int[size - 1];
		
		for (int i = 0; i < size - 1; i++)
			newStack[i] = stack[i];

		delete[] stack;
		stack = newStack;
		size--;
	}
}

int& Stack::operator[](unsigned int index)
{
	if (index < size)
		return stack[index];
}

int Stack::peek()
{
	return stack[size - 1];
}

bool Stack::empty()
{
	if (size == 0)
		return true;
	return false;
}

Stack::~Stack()
{
	delete stack;
}
#include "Queue.hpp"

Queue::Queue()
{
	size = 0;
}

void Queue::enqueue(int value)
{
	int* newQueue = new int[size + 1];

	newQueue[0] = value;
	for (int i = 0; i < size; i++)
		newQueue[i + 1] = queue[i];

	delete[] queue;
	queue = newQueue;
	size++;
}

void Queue::dequeue()
{
	if (size > 0)
	{
		int* newQueue = new int[size - 1];
		
		for (int i = 0; i < size - 1; i++)
			newQueue[i] = queue[i];

		delete[] queue;
		queue = newQueue;
		size--;
	}
}

int& Queue::operator[](unsigned int index)
{
	if (index < size)
		return queue[index];
}

int Queue::front()
{
	return queue[size - 1];
}

int Queue::rear()
{
	return queue[0];
}

bool Queue::empty()
{
	if (size == 0)
		return true;
	return false;
}
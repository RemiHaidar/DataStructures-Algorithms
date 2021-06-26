#include <stdlib.h>
#include <iostream>

class Queue
{
private:
	int* queue;
	size_t size;
public:
	Queue();
	~Queue();
	void enqueue(int);
	void dequeue();
	int rear();
	int front();
	bool empty();
	int& operator[](unsigned int);
};
#include <iostream>

class LinkedList
{
private:
	struct Slot
	{
		int value;
		Slot* next;
		Slot(int);
	};
	Slot* root;
	void prependUtil(Slot*, int);
public:
	LinkedList();
	void append(int);
	void prepend(int);
	int index(int);
	bool find(int);
	void erase(int);
	int operator[](unsigned int index);
};
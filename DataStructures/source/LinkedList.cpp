#include "LinkedList.hpp"

LinkedList::LinkedList()
{
	this->root = NULL;
}

LinkedList::Slot::Slot(int value)
{
	this->value = value;
	this->next = NULL;
}

void LinkedList::append(int value)
{
	if (root == NULL)
		root = new Slot(value);
	else {
		for (Slot* i = root; ; i = i->next)
		{
			if (i->next == NULL) {
				i->next = new Slot(value);
				break;
			}
		}
	}
		
}

void LinkedList::prepend(int value)
{
	Slot* temp = root;
	root = new Slot(value);

	root->next = temp;
}

int LinkedList::index(int value)
{
	int indexCounter = 0;
	for (Slot* i = root; i->value != value && i != NULL; i = i->next)
		indexCounter++;
	return indexCounter;
}

bool LinkedList::find(int value)
{
	for (Slot* i = root; i != NULL; i = i->next)
		if (i->value == value)
			return true;
	return false;
}

void LinkedList::erase(int value)
{
	for (Slot* i = root; i != NULL; i = i->next)
		if (i->next != NULL)
			if (i->next->value == value)
				i->next = i->next->next;
}

int LinkedList::operator[] (unsigned int index)
{
	int counter = 0;
	for (Slot* i = root; i != NULL ; i = i->next)
	{
		if (counter == index)
			return i->value;
		else
			counter++;
	}
	return -1;
}
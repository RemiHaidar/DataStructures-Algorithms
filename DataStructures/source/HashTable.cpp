#include "HashTable.hpp"

// ----- LinearHashTable -----

LinearHashTable::LinearHashTable(int size)
{
    hashTable.reserve(size);
    for (int i = 0; i < hashTable.capacity(); i++)
        hashTable.push_back(new HashTableSlot());
    this->size = this->availableSpace = hashTable.capacity();
}

LinearHashTable::HashTableSlot::HashTableSlot(int value)
{
    this->value = value; 
    this->empty = false;
}

int LinearHashTable::hash(int insert)
{
    return insert % size;
}

void LinearHashTable::insert(int insert)
{
    int index = hash(insert);

    if (availableSpace > 0)
    {
        if (hashTable[index]->empty) {
            hashTable[index] = new HashTableSlot(insert);
            availableSpace--;
        }
        else {
            for (int i = index; i < size; i++) {
            // Loop starting from the index
                if (hashTable[i]->empty) {
                    hashTable[index] = new HashTableSlot(insert);
                    availableSpace--;
                    break;
                }
                if (i >= size - 1) {
                // Loop through the back of the table till the index
                    for (int j = 0; j < index; j++) {
                        if (hashTable[j]->empty) {
                            hashTable[index] = new HashTableSlot(insert);;
                            availableSpace--;
                            break;
                        }
                    }
                }
            }
        }
    }
    else
    {
        std::cout << "Not enough space left to insert " << insert << "!" << std::endl;
    }
}

int LinearHashTable::index(int n)
{
    int index = hash(n);

    if (hashTable[index]->empty)
        return -1;
    else
    {
        for (int i = index; i < size; i++) {
            // Loop starting from the index
            if (hashTable[i]->value == n) {
                return i;
            }
            if (i >= size - 1) {
                // Loop through the back of the table till the index
                for (int j = 0; j < index; j++) {
                    if (hashTable[j]->value == n) {
                        return j;
                    }
                }
            }
        }
    }
    return -1;
}

bool LinearHashTable::find(int n)
{
    int index = hash(n);

    if (hashTable[index]->empty)
        return false;
    else
    {
        for (int i = index; i < size; i++) {
            if (hashTable[i]->value == n)
                return true;
            if (i >= size - 1) {
                for (int j = 0; j < index; j++)
                    if (hashTable[j]->value == n)
                        return true;
            }
        }
    }
    return false;
}

void LinearHashTable::erase(int n)
{   
    int index = hash(n);

    if (hashTable[index]->empty)
    {
        hashTable[index]->empty = true;
        hashTable[index]->value = 0;
    }
    else
    {
        for (int i = index; i < size; i++) {
            if (hashTable[i]->value == n) {
                hashTable[i]->empty = true;
                hashTable[i]->value = 0;
            }
            if (i >= size - 1) {
                for (int j = 0; j < index; j++) {
                    if (hashTable[j]->value == n) {
                        hashTable[j]->empty = true;
                        hashTable[j]->value = 0;
                    }
                }
            }
        }
    }
}

// ----- ChainHashTable -----

ChainHashTable::ChainHashTable(int size)
{
    hashTable.reserve(size);
    for (int i = 0; i < hashTable.capacity(); i++)
        hashTable.push_back(new HashTableSlot());
    this->size = hashTable.capacity();
}

ChainHashTable::HashTableSlot::HashTableSlot()
{
    this->empty = true;
}

ChainHashTable::HashTableSlot::HashTableSlot(int value)
{
    this->value = value; 
    this->empty = false;
}

int ChainHashTable::hash(int insert)
{
    return insert % size;
}

void ChainHashTable::insert(int insert)
{
    int index = hash(insert);

    if (hashTable[index]->empty) 
        hashTable[index] = new HashTableSlot(insert);
    else
        hashTable[index]->chain.push_back(insert);
}

bool ChainHashTable::find(int value)
{
    int index = hash(value);

    if (hashTable[index]->value == value)
        return true;
    else
    {
        for (int i = 0; i < hashTable[index]->chain.size(); i++)
            if (hashTable[index]->chain[i] == value)
                return true;
        return false;
    }
}

std::pair<int,int> ChainHashTable::index(int value)
{
    int index1, index2;

    index1 = hash(value);

    if (hashTable[index1]->value == value)
        return std::make_pair(index1,0);
    else {
        for (int i = 0; i < hashTable[index1]->chain.size(); i++)
            if (hashTable[index1]->chain[i] == value)
                index2 = i;
    }

    

    return std::make_pair(index1,index2 + 1);
}

void ChainHashTable::erase(int value)
{
    int index = hash(value);

    if (hashTable[index]->value == value)
    {
        std::vector<int> temp = hashTable[index]->chain;
        hashTable[index] = new HashTableSlot(hashTable[index]->chain[0]);
        for (int i = 0; i < temp.size(); i++)
            if (temp[i] == value) {
                temp.erase(temp.begin() + i);
                break;
            }
        hashTable[index]->chain = temp;
    }
    else
    {
        for (int i = 0; i < hashTable[index]->chain.size(); i++)
            if (hashTable[index]->chain[i] == value)
                hashTable[index]->chain.erase(hashTable[index]->chain.begin() + i);
    }
}
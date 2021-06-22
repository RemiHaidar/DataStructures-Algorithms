#include <iostream>
#include <vector>

class LinearHashTable
{
private:
    unsigned int size, availableSpace;
    struct HashTableSlot
    {
        int value;
        bool empty = true;
        HashTableSlot(int);
        HashTableSlot() { };
    };
    int hash(int);
    std::vector<HashTableSlot*> hashTable;
public:
    LinearHashTable(int);
    void insert(int);
    int index(int);
    bool find(int);
    void erase(int);
    int& operator[](unsigned int index) { return hashTable[index]->value; };
};

class ChainHashTable
{
private:
    unsigned int size;
    struct HashTableSlot
    {
        int value;
        bool empty;
        std::vector<int> chain;
        HashTableSlot();
        HashTableSlot(int value);
    };
    std::vector<HashTableSlot*> hashTable;
    int hash(int);
public:
    ChainHashTable(int);
    void insert(int);
    std::pair<int,int> index(int);
    bool find(int);
    void erase(int);
    int& operator()(unsigned int index1, unsigned int index2)
    { 
        if (index2 == 0)
            return hashTable[index1]->value;
        else if (index2 > 0)
            return hashTable[index1]->chain[index2 - 1]; 
    }
};

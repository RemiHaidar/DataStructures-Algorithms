#include "main.hpp"

int main()
{
    ChainHashTable table(20);

    table.insert(5);
    table.insert(23);
    table.insert(78);
    table.insert(1);
    table.insert(6);
    table.insert(118);
}
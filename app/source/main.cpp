#include "main.hpp"

int main()
{
    LinkedList list;

    list.append(5);
    list.append(9);
    list.append(2);
    list.append(3);
    list.append(77);

    std::cout << list[4] << std::endl;
}
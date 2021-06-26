#include "main.hpp"

int main()
{
    Queue queue;

    queue.enqueue(5);
    queue.enqueue(90);
    queue.enqueue(17);

    queue.dequeue();

    queue.enqueue(78);

    std::cout << queue.rear() << std::endl;
    std::cout << queue.front() << std::endl;

    std::cout << queue[2] << std::endl;
}
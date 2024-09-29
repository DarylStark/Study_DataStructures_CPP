#include <iostream>

#include "data_structures/doubly_linked_list.h"

int main()
{
    DoublyLinkedList list;

    list.append(10);
    list.append(20);
    list.append(30);
    list.append(40);
    list.append(50);

    list.prepend(1);
    list.prepend(2);
    list.prepend(3);
    list.prepend(4);

    std::cout << std::boolalpha << list.contains(11) << std::endl;

    return 0;
}
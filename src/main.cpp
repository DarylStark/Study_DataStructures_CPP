#include <iostream>

#include "data_structures/doubly_linked_list.h"

void print_list(const DoublyLinkedList &list)
{
    for (uint32_t i = 0; i < list.size(); i++)
        std::cout << i << ": " << list.get(i) << "\n";
    std::cout << '\n';
}

int main()
{
    DoublyLinkedList list;

    list.append(10);
    list.append(20);
    list.append(30);
    list.append(40);
    list.append(50);

    list.prepend(4);
    list.prepend(3);
    list.prepend(2);
    list.prepend(1);

    print_list(list);

    std::flush(std::cout);

    return 0;
}
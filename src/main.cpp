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
    list.append(60);
    list.append(70);

    print_list(list);
    list.insert(5, 55);
    print_list(list);

    std::flush(std::cout);

    return 0;
}
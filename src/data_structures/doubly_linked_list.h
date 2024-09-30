#ifndef __DOUBLY_LINKED_LIST_H__
#define __DOUBLY_LINKED_LIST_H__

#include <iostream>
#include <memory>

class DoublyLinkedListNode
{
public:
    uint32_t value;
    std::shared_ptr<DoublyLinkedListNode> next;
    std::shared_ptr<DoublyLinkedListNode> prev;

public:
    DoublyLinkedListNode(uint32_t value);
};

class DoublyLinkedList
{
private:
    std::shared_ptr<DoublyLinkedListNode> _head;
    std::shared_ptr<DoublyLinkedListNode> _tail;
    uint32_t _size;

    std::shared_ptr<DoublyLinkedListNode> _get_node(uint32_t index) const;

public:
    // Add items
    void append(uint32_t value);
    void prepend(uint32_t value);
    void insert(uint32_t index, uint32_t value);

    // Removing items
    uint32_t pop_head();
    uint32_t pop_tail();

    // Move items
    void move_to_front(uint32_t index);
    void move_to_back(uint32_t index);

    // Get items
    bool contains(uint32_t value) const;
    uint32_t location(uint32_t value) const;
    uint32_t get(uint32_t index) const;

    // Get information
    uint32_t size() const;
};

#endif /* __DOUBLY_LINKED_LIST_H__ */
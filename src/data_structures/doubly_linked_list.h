#ifndef __DOUBLY_LINKED_LISuint32_t_H__
#define __DOUBLY_LINKED_LISuint32_t_H__

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

public:
    void append(uint32_t value);
    void prepend(uint32_t value);
    bool contains(uint32_t value) const;

    uint32_t size() const;
};

#endif /* __DOUBLY_LINKED_LISuint32_t_H__ */
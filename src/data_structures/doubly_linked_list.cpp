#include "doubly_linked_list.h"

DoublyLinkedListNode::DoublyLinkedListNode(uint32_t value)
    : value(value), next(nullptr), prev(nullptr)
{
}

void DoublyLinkedList::append(uint32_t value)
{
    // Create new element
    std::shared_ptr<DoublyLinkedListNode> new_node = std::make_shared<DoublyLinkedListNode>(value);

    // Increase count
    this->_size++;

    if (!this->_head)
    {
        this->_head = new_node;
        this->_tail = new_node;
        return;
    }

    // Not the first element, append to the end
    this->_tail->next = new_node;
    new_node->prev = this->_tail;

    // Set the new end
    this->_tail = new_node;
}

void DoublyLinkedList::prepend(uint32_t value)
{
    // Create new element
    std::shared_ptr<DoublyLinkedListNode> new_node = std::make_shared<DoublyLinkedListNode>(value);

    // Increase count
    this->_size++;

    if (!this->_head)
    {
        this->_head = new_node;
        this->_tail = new_node;
        return;
    }

    // Not the first element, prepend to the start
    this->_head->prev = new_node;
    new_node->next = this->_head;

    // Set the new end
    this->_head = new_node;
}

bool DoublyLinkedList::contains(uint32_t value) const
{
    std::shared_ptr<DoublyLinkedListNode> current = this->_head;

    while (current)
    {
        if (current->value == value)
            return true;
        current = current->next;
    }

    return false;
}

uint32_t DoublyLinkedList::size() const
{
    return this->_size;
}
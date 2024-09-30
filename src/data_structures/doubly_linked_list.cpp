#include "doubly_linked_list.h"

DoublyLinkedListNode::DoublyLinkedListNode(uint32_t value)
    : value(value), next(nullptr), prev(nullptr)
{
}

std::shared_ptr<DoublyLinkedListNode> DoublyLinkedList::_get_node(uint32_t index) const
{
    if (index >= this->_size)
        throw std::invalid_argument("Index out of bounds");

    uint32_t current_index = 0;
    std::shared_ptr<DoublyLinkedListNode> current = this->_head;
    while (current && current_index < index)
    {
        current = current->next;
        current_index++;
    }
    return current;
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

void DoublyLinkedList::move_to_front(uint32_t index)
{
    // Get the node
    std::shared_ptr<DoublyLinkedListNode> node = this->_get_node(index);

    // Update the nodes around the selected node
    node->prev->next = node->next;
    node->next->prev = node->prev;

    // Set the correct values for the selected node
    node->prev = nullptr;
    node->next = this->_head;

    // Update the head
    this->_head->prev = node;
    this->_head = node;
}

void DoublyLinkedList::move_to_back(uint32_t index)
{
    // Get the node
    std::shared_ptr<DoublyLinkedListNode> node = this->_get_node(index);

    // Update the nodes around the selected node
    node->next->prev = node->prev;
    node->prev->next = node->next;

    // Set the correct values for the selected node
    node->next = nullptr;
    node->prev = this->_tail;

    // Update the tail
    this->_tail->next = node;
    this->_tail = node;
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

uint32_t DoublyLinkedList::location(uint32_t value) const
{
    uint32_t index = 0;
    std::shared_ptr<DoublyLinkedListNode> current = this->_head;

    while (current)
    {
        if (current->value == value)
            return index;
        current = current->next;
        index++;
    }

    throw std::invalid_argument("Value not found in list");
}

uint32_t DoublyLinkedList::get(uint32_t index) const
{
    return this->_get_node(index)->value;
}

uint32_t DoublyLinkedList::size() const
{
    return this->_size;
}
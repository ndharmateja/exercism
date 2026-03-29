#include "simple_linked_list.h"

#include <stdexcept>
#include <iostream>

namespace simple_linked_list
{

    std::size_t List::size() const { return this->current_size; }

    void List::push(int entry)
    {
        Element *new_head = new Element(entry);
        new_head->next = this->head;
        this->head = new_head;
        this->current_size++;
    }

    // Assumes there is atleast one element in the singly linked list
    int List::pop()
    {
        // Store the ptr to the old head, to be able to delete the node manually
        // as it was created on the heap
        Element *old_head = this->head;

        // Update the head of the linked list to the node after the curr head
        this->head = this->head->next;

        // Store result and delete the old head and return result
        int result{old_head->data};
        delete old_head;
        this->current_size--;
        return result;
    }

    void List::reverse()
    {
        Element *prev = nullptr;
        Element *curr = this->head;
        while (curr != nullptr)
        {
            Element *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Update the head to the last element before reversing
        // prev will point to the last node at the end of the iteration
        this->head = prev;
    }

    List::~List()
    {
        // We already have the deletion of node logic in the pop() method
        while (this->head != nullptr)
            this->pop();
    }

} // namespace simple_linked_list

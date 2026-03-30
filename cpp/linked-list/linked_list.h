#pragma once
#include <optional>
#include <stdexcept>

namespace linked_list
{
    template <typename T>
    class List
    {
    private:
        struct Node
        {
            std::optional<T> data;
            Node *prev;
            Node *next;

            // Node constructor
            Node() : data(std::nullopt), prev(nullptr), next(nullptr) {}
            Node(T d) : data(d), prev(nullptr), next(nullptr) {}
        };

        // Instance variables
        Node *head_sentinel;
        Node *tail_sentinel;
        int size;

        // Helper methods
        static void insert_after(Node *, Node *);
        static void insert_before(Node *, Node *);
        static void delete_node(Node *);

    public:
        // Constructor
        List();
        ~List();

        void push(T data);
        T pop();
        T shift();
        void unshift(T data);
        int count() const;
        bool erase(T data);
    };

    // Constructor
    template <typename T>
    List<T>::List() : size(0)
    {
        this->head_sentinel = new Node();
        this->tail_sentinel = new Node();
        this->head_sentinel->next = this->tail_sentinel;
        this->tail_sentinel->prev = this->head_sentinel;
    }

    // Helper methods
    template <typename T>
    void List<T>::insert_after(Node *node, Node *to_insert)
    {
        to_insert->prev = node;
        to_insert->next = node->next;
        to_insert->prev->next = to_insert;
        to_insert->next->prev = to_insert;
    }

    template <typename T>
    void List<T>::insert_before(Node *node, Node *to_insert)
    {
        to_insert->next = node;
        to_insert->prev = node->prev;
        to_insert->next->prev = to_insert;
        to_insert->prev->next = to_insert;
    }

    template <typename T>
    void List<T>::delete_node(Node *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
    }

    template <typename T>
    void List<T>::push(T data)
    {
        Node *node = new Node(data);
        insert_before(this->tail_sentinel, node);
        this->size++;
    }

    template <typename T>
    void List<T>::unshift(T data)
    {
        Node *node = new Node(data);
        insert_after(this->head_sentinel, node);
        this->size++;
    }

    template <typename T>
    T List<T>::shift()
    {
        if (!this->size)
            throw std::domain_error("List is empty.");

        Node *to_delete = this->head_sentinel->next;
        T return_value = to_delete->data.value();
        delete_node(to_delete); // also deletes the node object from heap

        this->size--;
        return return_value;
    }

    template <typename T>
    T List<T>::pop()
    {
        if (!this->size)
            throw std::domain_error("List is empty.");

        Node *to_delete = this->tail_sentinel->prev;
        T return_value = to_delete->data.value();
        delete_node(to_delete); // also deletes the node object from heap

        this->size--;
        return return_value;
    }

    template <typename T>
    int List<T>::count() const { return this->size; }

    template <typename T>
    List<T>::~List()
    {
        while (this->size)
            this->pop();
        delete this->head_sentinel;
        delete this->tail_sentinel;
    }

    template <typename T>
    bool List<T>::erase(T data)
    {
        for (Node *curr = this->head_sentinel->next; curr != this->tail_sentinel; curr = curr->next)
        {
            if (curr->data.value() == data)
            {
                delete_node(curr);
                this->size--;
                return true;
            }
        }
        return false;
    }
} // namespace linked_list

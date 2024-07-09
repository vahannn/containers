#pragma once

#include <iostream>
#include <list>
#include "./algorithms/distance.hpp"

namespace ft
{
    template <typename T>
    struct Node
    {
        Node(T data)
        {
            m_data = data;
            next = NULL;
            prev = NULL;
        }

        Node(const Node &obj)
        {
            next = NULL;
            prev = NULL;
            this->m_data = obj.m_data;
        }

        ~Node() {};

        Node &operator=(const Node &obj)
        {
            if (this != &obj)
                this->m_data = obj.m_data;
            return (*this);
        }

        Node *next;
        Node *prev;
        T m_data;
    };

    template <typename T, typename Allocator = std::allocator<T> >
    class list
    {
        /* Member types */
        public:
            typedef T                                       value_type;
            typedef Allocator			                    allocator_type;
            typedef size_t                                  size_type;
            typedef value_type&                             reference;
            typedef const value_type&                       const_reference;
            typedef value_type*                             pointer;
            typedef const value_type*                       const_pointer;
            typedef ptrdiff_t                               difference_type;

        /* Constructers and Destructer */
        public:
        /* Element access */
        public:
        /*Iterators*/
        public:
            // iterator begin();
            // iterator end();
        public:
            // allocator_type get_allocator() const noexcept;
        /* Capacity */
        public:
        /* Modifiers */
        public:
        private:
            Node<T> *m_head;
            Node<T> *m_tail;
            size_t m_size;

    };
    /* Non-member functions */
}
# include "list.tpp"
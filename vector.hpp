#pragma once

#include <iostream>
#include <vector>
#include <list>
#include "./iterators/random_access_iterator.hpp"

namespace ft
{
    template <typename T, typename Allocator = std::allocator<T> >
    class vector
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
            typedef ft::random_access_iterator<T>           iterator;
            typedef const ft::random_access_iterator<T>     const_iterator;

        /* Constructers and Destructer */
        public:
            explicit vector() noexcept;
            explicit vector(size_type count,
                const T& value = T());
            vector(const vector &other);
            vector( vector&& other ) noexcept;
            // vector( std::initializer_list<T> init, 
                // const Allocator& alloc = Allocator() );
            ~vector();

            vector &operator=(const vector &other) noexcept;
            void assign( size_type count, const T& value );
        /* Element access */
        public:
            reference at( size_type pos );
            const_reference at( size_type pos ) const;
            reference operator[](size_type pos);
            const_reference operator[](size_type pos) const;
            reference front();
            const_reference front() const;
            reference back();
            const_reference back() const;
            T* data() noexcept;
            const T* data() const;

        /*Iterators*/
        public:
            iterator begin();
            iterator end();
        public:
            allocator_type get_allocator() const noexcept;
        /* Capacity */
        public:
            bool empty() const noexcept;
            size_type size() const noexcept;
            size_type max_size() const noexcept;
            void reserve(size_type new_cap);
            size_type capacity() const noexcept;
            void shrink_to_fit();
        /* Modifiers */
        public:
            iterator insert(const_iterator pos, const T& value);
            iterator insert(const_iterator pos, size_type count, const T& value);
            void clear() noexcept;
            void push_back(const T& value);
            void pop_back();
            // template< class... Args >
            // reference emplace_back( Args&&... args );
            void swap(vector& other) noexcept;
        /* Member functions (Iterators) */
        private:
            value_type * _arr;
            size_type _size;
            size_type _cap;
            allocator_type _alloc;

    };
    /* Non-member functions */
    template<typename T, typename Allocator>
    bool operator==( const vector<T, Allocator>& lhs,
                 const vector<T, Allocator>& rhs );
}
# include "vector.tpp"
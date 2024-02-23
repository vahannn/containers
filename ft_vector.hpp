#pragma once

#include <iostream>
#include <vector>
namespace ft
{
    template <typename T, typename Allocator = std::allocator<T> >
    class vector
    {
        /* Member types */
        public:
            typedef T                   value_type;
            typedef Allocator			allocator_type;
            typedef size_t              size_type;
            typedef value_type&         reference;
            typedef value_type&         const_reference;
            typedef value_type*         pointer;
            typedef value_type*         const_pointer;

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

        public:
            reference operator[](size_type pos);
        public:
            size_type size() const noexcept;
        public:
            allocator_type get_allocator() const noexcept;
        /* Modifiers */
        public:
            void clear() noexcept;
        /* Member functions (Iterators) */
        private:
            value_type * _arr;
            size_type _size;
            size_type _cap;
            allocator_type _alloc;

    };

}
# include "ft_vector.tpp"
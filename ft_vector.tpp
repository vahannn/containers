#pragma once
#include <iostream>

namespace	ft
{
    template <typename T, typename Allocator>
    vector<T, Allocator>::vector() noexcept
        : _arr(NULL), _size(0), _cap(0), _alloc(allocator_type()) {};

    template <typename T, typename Allocator>
    vector<T, Allocator>::vector(size_type count,
                const T& value)
    {
        _alloc = allocator_type();
        _arr = count != 0 ? _alloc.allocate(count) : NULL;
        _size = count;
        _cap = count;

        for (size_type i = 0; i < count; i++) {
            _alloc.construct(_arr + i, value);
        }

        // TODO catch exceptions
    }

    template <typename T, typename Allocator>
    vector<T, Allocator>::vector(const vector& other)
    {
        std::cout << "copy\n";
        _alloc = std::allocator_traits<allocator_type>::select_on_container_copy_construction(other.get_allocator());
        _arr = other._size != 0 ? _alloc.allocate(other._size) : NULL;
        _size = other._size;
        _cap = other._cap;

        for (size_type i = 0; i < other._size; i++) {
            _alloc.construct(_arr + i, other._arr[i]);
        }
    };

    template <typename T, typename Allocator>
    vector<T, Allocator>::~vector() {};


    template <typename T, typename Allocator>
    typename vector<T, Allocator>::reference vector<T, Allocator>::operator[](size_type pos)
    {
        return (_arr[pos]);
    };

    template <typename T, typename Allocator>
    typename vector<T, Allocator>::size_type vector<T, Allocator>::size() const noexcept {
        return (_size);
    };

    template <typename T, typename Allocator>
    typename vector<T, Allocator>::allocator_type vector<T, Allocator>::get_allocator() const noexcept
    {
        return (_alloc);
    };

    template <typename T, typename Allocator>
    vector<T, Allocator>::vector(vector&& other) noexcept
    {
        std::cout << "move\n";
        _alloc = std::move(other._alloc);
        _size = other._size;
        _cap = other._cap;
        _arr = other._arr;
        // TODO clear other
        other._arr = NULL;
    };

}
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
    vector<T, Allocator>::vector(vector&& other) noexcept
    {
        std::cout << "move\n";
        _alloc = std::move(other._alloc);
        _size = other._size;
        _cap = other._cap;
        _arr = other._arr;
        other.clear();
        other._arr = NULL;
        other._cap = 0;
    };

    template <typename T, typename Allocator>
    vector<T, Allocator>::~vector()
    {
        for (size_type i = 0; i < _size; i++) {
            _alloc.destroy(_arr + i);
        }
        if (_arr)
            _alloc.deallocate(_arr, _cap);
    };

    /* Element access */

    template <typename T, typename Allocator>
    typename vector<T, Allocator>::reference vector<T, Allocator>::at(size_type pos)
    {
        if (pos >= _size) {
            throw std::out_of_range("vector: out of range");
        }
        return (_arr[pos]);
    };

    template <typename T, typename Allocator>
    typename vector<T, Allocator>::const_reference vector<T, Allocator>:: at(size_type pos) const
    {
        if (pos >= _size) {
            throw std::out_of_range("vector: out of range");
        }
        return (_arr[pos]);
    };

    template <typename T, typename Allocator>
    typename vector<T, Allocator>::reference vector<T, Allocator>::operator[](size_type pos)
    {
        return (_arr[pos]);
    };

    template <typename T, typename Allocator>
    typename vector<T, Allocator>::const_reference vector<T, Allocator>::operator[](size_type pos) const
    {
        return (_arr[pos]);
    };

    template <typename T, typename Allocator>
    typename vector<T, Allocator>::reference vector<T, Allocator>::front()
    {
        return (*_arr);
    };

    template <typename T, typename Allocator>
    typename vector<T, Allocator>::const_reference vector<T, Allocator>::front() const
    {
        return (*_arr);
    };

    template <typename T, typename Allocator>
    typename vector<T, Allocator>::reference vector<T, Allocator>::back()
    {
        return (*(_arr + _size - 1));
    };

    template <typename T, typename Allocator>
    typename vector<T, Allocator>::const_reference vector<T, Allocator>::back() const
    {
        return (*(_arr + _size - 1));
    };

    template <typename T, typename Allocator>
    T* vector<T, Allocator>::data() noexcept
    {
        return (_arr);
    };

    template <typename T, typename Allocator>
    const T* vector<T, Allocator>::data() const
    {
        return (_arr);
    };

    template <typename T, typename Allocator>
    typename vector<T, Allocator>::allocator_type vector<T, Allocator>::get_allocator() const noexcept
    {
        return (_alloc);
    };


    template <typename T, typename Allocator>
    vector<T, Allocator> &vector<T, Allocator>::operator=(const vector &other) noexcept
    {
        if (this != &other)
        {
            if (_arr) {
                this->clear();
                _alloc.deallocate(_arr, _cap);
            }
            _alloc = other._alloc;
            _arr = other._size != 0 ? _alloc.allocate(other._size) : NULL;
            _size = other._size;
            _cap = other._cap;

            for (size_type i = 0; i < other._size; i++) {
                _alloc.construct(_arr + i, other._arr[i]);
            }
        }
        return (*this);
    };

    // template <typename T, typename Allocator>
    // void vector<T, Allocator>::assign(size_type count, const T& value)
    // {
    //     if (_arr) {
    //         this->clear();
    //         _alloc.deallocate(_arr, _cap);
    //     }
    //     _arr = other._size != 0 ? _alloc.allocate(other._size) : NULL;
    //     _size = other._size;
    //     _cap = other._cap;

    //     for (size_type i = 0; i < other._size; i++) {
    //         _alloc.construct(_arr + i, other._arr[i]);
    //     }
    // };


    /*Iterators*/
    template <typename T, typename Allocator>
    typename vector<T, Allocator>::iterator vector<T, Allocator>::begin()
    {
        return (ft::random_access_iterator(_arr));
    };

    template <typename T, typename Allocator>
    typename vector<T, Allocator>::iterator vector<T, Allocator>::end()
    {
        return (_arr + _size);
    };

    /* Capacity */

    template <typename T, typename Allocator>
    bool vector<T, Allocator>::empty() const noexcept
    {
        return (_size == 0);
    };

    template <typename T, typename Allocator>
    typename vector<T, Allocator>::size_type vector<T, Allocator>::size() const noexcept {
        return (_size);
    };

    template <typename T, typename Allocator>
    typename vector<T, Allocator>::size_type vector<T, Allocator>::max_size() const noexcept
    {
        return (_alloc.max_size());
    };

    template <typename T, typename Allocator>
    void vector<T, Allocator>::reserve(size_type new_cap)
    {
        if (new_cap < _cap || new_cap == 0) {
            return ;
        }
        if (new_cap >= _alloc.max_size()) {
            throw std::length_error("cannot allocate vector of size" + std::to_string(new_cap));
        }

        pointer tmpArr = _alloc.allocate(new_cap);

        for (size_type i = 0; i < _size; i++) {
            _alloc.construct(tmpArr + i, _arr[i]);
            _alloc.destroy(_arr + i);
        }
        _alloc.deallocate(_arr, _cap);
        _arr = tmpArr;
        _cap = new_cap;
    };

    template <typename T, typename Allocator>
    typename vector<T, Allocator>::size_type vector<T, Allocator>::capacity() const noexcept
    {
        return (_cap);
    };

    template <typename T, typename Allocator>
    void vector<T, Allocator>::shrink_to_fit()
    {
        if (_size == _cap)
            return ;
        pointer tmpArr = _alloc.allocate(_size);
        for (size_type i = 0; i < _size; i++) {
            _alloc.construct(tmpArr + i, _arr[i]);
            _alloc.destroy(_arr + i);
        }
        _alloc.deallocate(_arr, _cap);
        _arr = tmpArr;
        _cap = _size;
    };


    template <typename T, typename Allocator>
    void vector<T, Allocator>::clear() noexcept
    {
        for (size_type i = 0; i < _size; i++) {
            _alloc.destroy(_arr + i);
        }
        _size = 0;
    };

    /* Modifiers */

    template <typename T, typename Allocator>
    typename vector<T, Allocator>::iterator vector<T, Allocator>::insert(const_iterator pos, const T& value)
    {
        if (pos == _size) {
            this->push_back(value);
            return (_size - 1);
        }


    };

    template <typename T, typename Allocator>
    typename vector<T, Allocator>::iterator vector<T, Allocator>::insert(const_iterator pos, size_type count, const T& value)
    {
        if (count == 0) {
            return iterator(this->begin());
        }

        if (_size + count > _cap) {
            size_type tmpCap = _size + count <= _cap * 2 ? _cap * 2 : _size + count;

            value_type *tmpArr = _alloc.allocate(tmpCap);
            size_type i = 0;

            for (size_type end = pos - this->begin(); i < end; i++) {
                _alloc.construct(tmpArr + i, _arr[i]);
                _alloc.destroy(_arr + i);
            }
            size_type j = i;

            for (; i < count; i++) {
                _alloc.construct(tmpArr + i, value);
            }
            for (; j < _size; j++) {
                _alloc.construct(tmpArr + i, _arr[j]);
                _alloc.destroy(_arr + j);
                i++;
            }
            _alloc.deallocate(_arr, _cap);
            _size += count;
            _cap = tmpCap;
            _arr = tmpArr;
        } else {
            size_type i = pos - this->begin();

            for (; i < count; i++) {
                
                _alloc.construct(tmpArr + i, _arr[i]);
                _alloc.destroy(_arr + i);
            }
        }
    };

    template <typename T, typename Allocator>
    void vector<T, Allocator>::push_back(const T& value)
    {
        // std::cout << "_size = " << _size << std::endl;
        // std::cout << "_cap = " << _cap << std::endl;
        if (_size >= _cap) {
            if (_cap == 0)
                _cap = 1;
            else
                _cap = _cap * 2 > _alloc.max_size() ? _alloc.max_size() : _cap * 2;
            this->reserve(_cap);
        }

        _alloc.construct(_arr + _size++, value);
    };

    template <typename T, typename Allocator>
    void vector<T, Allocator>::pop_back()
    {
        _alloc.destroy(_arr + --_size);
    };

    template <typename T, typename Allocator>
    void vector<T, Allocator>::swap(vector& other) noexcept
    {
        std::swap(_arr, other._arr);
        std::swap(_size, other._size);
        std::swap(_cap, other._cap);
        std::swap(_alloc, other._alloc);
    };

    /* Non-member functions */
    template<typename T, typename Allocator>
    bool operator==( const vector<T, Allocator>& lhs,
                    const vector<T, Allocator>& rhs )
    {
        if (lhs.size() != rhs.size()) {
            return (false);
        }
        size_t len = lhs.size();

        for (size_t i = 0; i < len; i++) {
            if (lhs[i] != rhs[i]) {
                return (false);
            }
        }
        return (true);
    };
}

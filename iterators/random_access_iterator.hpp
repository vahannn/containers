#pragma once

namespace ft
{
    template<typename T>
    class random_access_iterator
    {
        public:
            typedef T                   value_type;
            typedef size_t              size_type;
            typedef value_type&         reference;
            typedef const value_type&   const_reference;
            typedef value_type*         pointer;
            typedef const value_type*   const_pointer;
            typedef ptrdiff_t           difference_type;
        public:
            random_access_iterator();
            random_access_iterator(T *);
            random_access_iterator<T> &operator=(const random_access_iterator<T> &);
        public:
            bool operator==(const random_access_iterator<T> &) const;
            bool operator!=(const random_access_iterator<T> &) const;
            reference operator*();
            const_reference operator*() const;
            pointer operator->();
            const_pointer operator->() const;
            random_access_iterator<T> &operator++();
            random_access_iterator<T> operator++(int);
            random_access_iterator<T> &operator--();
            random_access_iterator<T> operator--(int);
            random_access_iterator<T> operator+(int) const;
            random_access_iterator<T> operator-(int) const;
            int operator-(const random_access_iterator<T> &) const;
            bool operator<(const random_access_iterator<T> &) const;
            bool operator<=(const random_access_iterator<T> &) const;
            bool operator>(const random_access_iterator<T> &) const;
            bool operator>=(const random_access_iterator<T> &) const;
            random_access_iterator<T> &operator+=(int);
            random_access_iterator<T> &operator-=(int);
            reference operator[](size_type pos);
            const_reference operator[](size_type pos) const;
        private:
            T *_ptr;
    };

    template<typename T>
    random_access_iterator<T> operator+(int, const random_access_iterator<T> &);
#include "random_access_iterator.tpp"
}

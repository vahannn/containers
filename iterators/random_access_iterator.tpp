#pragma once

template<typename T>
random_access_iterator<T>::random_access_iterator() : _ptr(0) {};

template<typename T>
random_access_iterator<T>::random_access_iterator(T *ptr) : _ptr(ptr) {};

template<typename T>
random_access_iterator<T> &random_access_iterator<T>::operator=(const random_access_iterator<T> &other)
{
    _ptr = other._ptr;
    return (*this);
};

template<typename T>
bool random_access_iterator<T>::operator==(const random_access_iterator<T> &other)
{
    return (_ptr == other._ptr);
};

template<typename T>
bool random_access_iterator<T>::operator!=(const random_access_iterator<T> &other)
{
    return (_ptr != other._ptr);
};

template<typename T>
typename random_access_iterator<T>::reference random_access_iterator<T>::operator*()
{
    return (*_ptr);
};

template<typename T>
typename random_access_iterator<T>::const_reference random_access_iterator<T>::operator*() const
{
    return (*_ptr);
};

template<typename T>
typename random_access_iterator<T>::pointer random_access_iterator<T>::operator->()
{
    return (_ptr);
};

template<typename T>
typename random_access_iterator<T>::const_pointer random_access_iterator<T>::operator->() const
{
    return (_ptr);
};

template<typename T>
random_access_iterator<T> &random_access_iterator<T>::operator++()
{
    ++_ptr;
    return (*this);
};

template<typename T>
random_access_iterator<T> random_access_iterator<T>::operator++(int)
{
    random_access_iterator<T> tmp = *this;
    ++_ptr;
    return (tmp);
};

template<typename T>
random_access_iterator<T> &random_access_iterator<T>::operator--()
{
    --_ptr;
    return (*this);
};

template<typename T>
random_access_iterator<T> random_access_iterator<T>::operator--(int)
{
    random_access_iterator<T> tmp = *this;
    --_ptr;
    return (tmp);
};

template<typename T>
random_access_iterator<T> random_access_iterator<T>::operator+(int a) const
{
    return (random_access_iterator<T>(_ptr + a));
};

template<typename T>
random_access_iterator<T> random_access_iterator<T>::operator-(int a) const
{
    return (random_access_iterator<T>(_ptr - a));
};

template<typename T>
int random_access_iterator<T>::operator-(const random_access_iterator<T> &other) const
{
    return (random_access_iterator<T>(_ptr - other._ptr));
};

template<typename T>
bool random_access_iterator<T>::operator<(const random_access_iterator<T> &other) const
{
    return (_ptr < other._ptr);
};

template<typename T>
bool random_access_iterator<T>::operator<=(const random_access_iterator<T> &other) const
{
    return (_ptr <= other._ptr);
};

template<typename T>
bool random_access_iterator<T>::operator>(const random_access_iterator<T> &other) const
{
    return (_ptr > other._ptr);
};

template<typename T>
bool random_access_iterator<T>::operator>=(const random_access_iterator<T> &other) const
{
    return (_ptr >= other._ptr);
};

template<typename T>
random_access_iterator<T> &random_access_iterator<T>::operator+=(int a)
{
    _ptr += a;
    return (*this);
};

template<typename T>
random_access_iterator<T> &random_access_iterator<T>::operator-=(int a)
{
    _ptr -= a;
    return (*this);
};

template<typename T>
typename random_access_iterator<T>::reference random_access_iterator<T>::operator[](size_type pos)
{
    return (*_ptr);
};

template<typename T>
typename random_access_iterator<T>::const_reference random_access_iterator<T>::operator[](size_type pos) const
{
    return (*_ptr);
};


template<typename T>
random_access_iterator<T> operator+(int lhs, const random_access_iterator<T> &rhs)
{
    return (random_access_iterator<T>(rhs + lhs));
};

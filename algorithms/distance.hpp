#pragma once

namespace ft
{
    template< typename InputIt >
    typename InputIt::difference_type \
    distance(InputIt first, InputIt last)
    {
        typename InputIt::difference_type count = 0;
        while (first != last) {
            first++;
            count++;
        }
        return (count);
    };
}
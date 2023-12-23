#pragma once

#include "iterator.hpp"

namespace ft
{

// reverse_iterator
template <typename Iter>
class reverse_iterator
    : public iterator<typename iterator_traits<Iter>::value_type,
                      typename iterator_traits<Iter>::iterator_category,
                      typename iterator_traits<Iter>::reference,
                      typename iterator_traits<Iter>::pointer,
                      typename iterator_traits<Iter>::difference_type>
{
protected:
    Iter _current;

public:
    typedef Iter                                                iterator_type;
    typedef typename iterator_traits<Iter>::reference           reference;
    typedef typename iterator_traits<Iter>::pointer             pointer;
    typedef typename iterator_traits<Iter>::difference_type     difference_type;

    reverse_iterator();
};

}
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

public:
    reverse_iterator();
    explicit reverse_iterator(Iter x);
    template <typename Up> reverse_iterator(const reverse_iterator<Up>& up);

public:
    template <typename Up> reverse_iterator& operator=(const reverse_iterator<Up>& up);

public:
    inline Iter base() const
    {
        return _current;
    }

};

template <typename Iter>
reverse_iterator<Iter>::reverse_iterator()
    : _current() {}


template <typename Iter>
reverse_iterator<Iter>::reverse_iterator(Iter x)
   : _current(x) {}

// for another type iterator
template <typename Iter>
template <typename Up>
reverse_iterator<Iter>::reverse_iterator(const reverse_iterator<Up>& up)
    : _current(up.base()) {}

template <typename Iter>
template <typename Up>
reverse_iterator<Iter>& reverse_iterator<Iter>::operator=(const reverse_iterator<Up>& up)
{
    this->_current = up.base();
    return *this;
}

}
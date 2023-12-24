#pragma once

#include "iterator.hpp"

namespace ft
{

// ----- member declarations -----
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
    template <typename Up> inline reverse_iterator& operator=(const reverse_iterator<Up>& up);
    inline reference operator*() const;
    inline pointer operator->() const;
    inline reverse_iterator& operator++();
    inline reverse_iterator& operator--();
    inline reverse_iterator operator++(int);
    inline reverse_iterator operator--(int);
    inline reverse_iterator operator+(difference_type n) const;
    inline reverse_iterator operator-(difference_type n) const;
    inline reverse_iterator& operator+=(difference_type n);
    inline reverse_iterator& operator-=(difference_type n);
    inline reference operator[](difference_type n) const;

public:
    inline Iter base() const;

};

template <class Iter1, class Iter2> inline bool operator==(const reverse_iterator<Iter1>& x, const reverse_iterator<Iter2>& y);
template <class Iter1, class Iter2> inline bool operator!=(const reverse_iterator<Iter1>& x, const reverse_iterator<Iter2>& y);
template <class Iter1, class Iter2> inline bool operator<(const reverse_iterator<Iter1>& x, const reverse_iterator<Iter2>& y);
template <class Iter1, class Iter2> inline bool operator>(const reverse_iterator<Iter1>& x, const reverse_iterator<Iter2>& y);
template <class Iter1, class Iter2> inline bool operator<=(const reverse_iterator<Iter1>& x, const reverse_iterator<Iter2>& y);
template <class Iter1, class Iter2> inline bool operator>=(const reverse_iterator<Iter1>& x, const reverse_iterator<Iter2>& y);
template <class Iter1, class Iter2> inline typename reverse_iterator<Iter1>::difference_type operator-(const reverse_iterator<Iter1>& x, const reverse_iterator<Iter2>& y);
template <class Iter> inline reverse_iterator<Iter> operator+(typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& x);



// ----- member funtions definitions -----

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
inline reverse_iterator<Iter>& reverse_iterator<Iter>::operator=(const reverse_iterator<Up>& up)
{
    this->_current = up.base();
    return *this;
}

// *--temp?
template <typename Iter>
inline typename reverse_iterator<Iter>::reference reverse_iterator<Iter>::operator*() const
{
    Iter temp = _current;
    return *--temp;
}

template <typename Iter>
inline typename reverse_iterator<Iter>::pointer reverse_iterator<Iter>::operator->() const
{
    return std::addressof(operator*());
}

// 'reverse'
template <typename Iter>
inline reverse_iterator<Iter>& reverse_iterator<Iter>::operator++()
{
    --_current;
    return *this;
}

template <typename Iter>
inline reverse_iterator<Iter>& reverse_iterator<Iter>::operator--()
{
    ++_current;
    return *this;
}

template <typename Iter>
inline reverse_iterator<Iter> reverse_iterator<Iter>::operator++(int)
{
    reverse_iterator<Iter> temp(*this);
    --_current;
    return temp;
}

template <typename Iter>
inline reverse_iterator<Iter> reverse_iterator<Iter>::operator--(int)
{
    reverse_iterator<Iter> temp(*this);
    ++_current;
    return temp;
}

template <typename Iter>
inline reverse_iterator<Iter> reverse_iterator<Iter>::operator+(difference_type n) const
{
    return reverse_iterator<Iter>(_current - n);
}

template <typename Iter>
inline reverse_iterator<Iter> reverse_iterator<Iter>::operator-(difference_type n) const
{
    return reverse_iterator<Iter>(_current + n);
}

template <typename Iter>
inline reverse_iterator<Iter>& reverse_iterator<Iter>::operator+=(difference_type n)
{
    _current -= n;
    return *this;
}

template <typename Iter>
inline reverse_iterator<Iter>& reverse_iterator<Iter>::operator-=(difference_type n)
{
    _current += n;
    return *this;
}

template <typename Iter>
inline typename reverse_iterator<Iter>::reference reverse_iterator<Iter>::operator[](difference_type n) const
{
    return *(*this + n);
}

template <typename Iter>
inline Iter reverse_iterator<Iter>::base() const
{
    return _current;
}


// ----- global funtions definitions -----

template <class Iter1, class Iter2>
inline bool operator==(const reverse_iterator<Iter1>& x, const reverse_iterator<Iter2>& y)
{
    return x.base() == y.base();
}

template <class Iter1, class Iter2>
inline bool operator!=(const reverse_iterator<Iter1>& x, const reverse_iterator<Iter2>& y)
{
    return x.base() != y.base();
}

// 'reverse'
template <class Iter1, class Iter2>
inline bool operator<(const reverse_iterator<Iter1>& x, const reverse_iterator<Iter2>& y)
{
    return x.base() > y.base();
}

template <class Iter1, class Iter2>
inline bool operator>(const reverse_iterator<Iter1>& x, const reverse_iterator<Iter2>& y)
{
    return x.base() < y.base();
}

template <class Iter1, class Iter2>
inline bool operator<=(const reverse_iterator<Iter1>& x, const reverse_iterator<Iter2>& y)
{
    return x.base() >= y.base();
}

template <class Iter1, class Iter2>
inline bool operator>=(const reverse_iterator<Iter1>& x, const reverse_iterator<Iter2>& y)
{
    return x.base() <= y.base();
}

template <class Iter1, class Iter2> 
inline typename reverse_iterator<Iter1>::difference_type operator-(const reverse_iterator<Iter1>& x, const reverse_iterator<Iter2>& y)
{
    return y.base() - x.base();
}

template <class Iter> 
inline reverse_iterator<Iter> operator+(typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& x)
{
    return reverse_iterator<Iter>(x.base() - n);
}

}
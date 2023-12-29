#pragma once

#include "iterator.hpp"

namespace ft
{

// ----- member declarations -----
template <typename Iter>
class random_access_iterator
    : public iterator<typename iterator_traits<Iter>::value_type,
                      random_access_iterator_tag,
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
    random_access_iterator();
    explicit random_access_iterator(Iter x);
    template <typename Up> random_access_iterator(const random_access_iterator<Up>& up);

public:
    template <typename Up> inline random_access_iterator& operator=(const random_access_iterator<Up>& up);
    inline reference operator*() const;
    inline pointer operator->() const;
    inline random_access_iterator& operator++();
    inline random_access_iterator& operator--();
    inline random_access_iterator operator++(int);
    inline random_access_iterator operator--(int);
    inline random_access_iterator operator+(difference_type n) const;
    inline random_access_iterator operator-(difference_type n) const;
    inline random_access_iterator& operator+=(difference_type n);
    inline random_access_iterator& operator-=(difference_type n);
    inline reference operator[](difference_type n) const;

public:
    inline Iter base() const;
};

template <class Iter1, class Iter2> inline bool operator==(const random_access_iterator<Iter1>& x, const random_access_iterator<Iter2>& y);
template <class Iter1, class Iter2> inline bool operator!=(const random_access_iterator<Iter1>& x, const random_access_iterator<Iter2>& y);
template <class Iter1, class Iter2> inline bool operator<(const random_access_iterator<Iter1>& x, const random_access_iterator<Iter2>& y);
template <class Iter1, class Iter2> inline bool operator>(const random_access_iterator<Iter1>& x, const random_access_iterator<Iter2>& y);
template <class Iter1, class Iter2> inline bool operator<=(const random_access_iterator<Iter1>& x, const random_access_iterator<Iter2>& y);
template <class Iter1, class Iter2> inline bool operator>=(const random_access_iterator<Iter1>& x, const random_access_iterator<Iter2>& y);
template <class Iter1, class Iter2> inline typename random_access_iterator<Iter1>::difference_type operator-(const random_access_iterator<Iter1>& x, const random_access_iterator<Iter2>& y);
template <class Iter> inline random_access_iterator<Iter> operator+(typename random_access_iterator<Iter>::difference_type n, const random_access_iterator<Iter>& x);



// ----- member funtions definitions -----

template <typename Iter>
random_access_iterator<Iter>::random_access_iterator()
    : _current() {}

template <typename Iter>
random_access_iterator<Iter>::random_access_iterator(Iter x)
   : _current(x) {}

// for another type iterator
template <typename Iter>
template <typename Up>
random_access_iterator<Iter>::random_access_iterator(const random_access_iterator<Up>& up)
    : _current(up.base()) {}

template <typename Iter>
template <typename Up>
inline random_access_iterator<Iter>& random_access_iterator<Iter>::operator=(const random_access_iterator<Up>& up)
{
    this->_current = up.base();
    return *this;
}

// *--temp?
template <typename Iter>
inline typename random_access_iterator<Iter>::reference random_access_iterator<Iter>::operator*() const
{
    Iter temp = _current;
    return *--temp;
}

template <typename Iter>
inline typename random_access_iterator<Iter>::pointer random_access_iterator<Iter>::operator->() const
{
    return std::addressof(operator*());
}

// 'reverse'
template <typename Iter>
inline random_access_iterator<Iter>& random_access_iterator<Iter>::operator++()
{
    --_current;
    return *this;
}

template <typename Iter>
inline random_access_iterator<Iter>& random_access_iterator<Iter>::operator--()
{
    ++_current;
    return *this;
}

template <typename Iter>
inline random_access_iterator<Iter> random_access_iterator<Iter>::operator++(int)
{
    random_access_iterator<Iter> temp(*this);
    --_current;
    return temp;
}

template <typename Iter>
inline random_access_iterator<Iter> random_access_iterator<Iter>::operator--(int)
{
    random_access_iterator<Iter> temp(*this);
    ++_current;
    return temp;
}

template <typename Iter>
inline random_access_iterator<Iter> random_access_iterator<Iter>::operator+(difference_type n) const
{
    return random_access_iterator<Iter>(_current - n);
}

template <typename Iter>
inline random_access_iterator<Iter> random_access_iterator<Iter>::operator-(difference_type n) const
{
    return random_access_iterator<Iter>(_current + n);
}

template <typename Iter>
inline random_access_iterator<Iter>& random_access_iterator<Iter>::operator+=(difference_type n)
{
    _current -= n;
    return *this;
}

template <typename Iter>
inline random_access_iterator<Iter>& random_access_iterator<Iter>::operator-=(difference_type n)
{
    _current += n;
    return *this;
}

template <typename Iter>
inline typename random_access_iterator<Iter>::reference random_access_iterator<Iter>::operator[](difference_type n) const
{
    return *(*this + n);
}

template <typename Iter>
inline Iter random_access_iterator<Iter>::base() const
{
    return _current;
}


// ----- global funtions definitions -----

template <class Iter1, class Iter2>
inline bool operator==(const random_access_iterator<Iter1>& x, const random_access_iterator<Iter2>& y)
{
    return x.base() == y.base();
}

template <class Iter1, class Iter2>
inline bool operator!=(const random_access_iterator<Iter1>& x, const random_access_iterator<Iter2>& y)
{
    return x.base() != y.base();
}

// 'reverse'
template <class Iter1, class Iter2>
inline bool operator<(const random_access_iterator<Iter1>& x, const random_access_iterator<Iter2>& y)
{
    return x.base() > y.base();
}

template <class Iter1, class Iter2>
inline bool operator>(const random_access_iterator<Iter1>& x, const random_access_iterator<Iter2>& y)
{
    return x.base() < y.base();
}

template <class Iter1, class Iter2>
inline bool operator<=(const random_access_iterator<Iter1>& x, const random_access_iterator<Iter2>& y)
{
    return x.base() >= y.base();
}

template <class Iter1, class Iter2>
inline bool operator>=(const random_access_iterator<Iter1>& x, const random_access_iterator<Iter2>& y)
{
    return x.base() <= y.base();
}

template <class Iter1, class Iter2> 
inline typename random_access_iterator<Iter1>::difference_type operator-(const random_access_iterator<Iter1>& x, const random_access_iterator<Iter2>& y)
{
    return y.base() - x.base();
}

template <class Iter> 
inline random_access_iterator<Iter> operator+(typename random_access_iterator<Iter>::difference_type n, const random_access_iterator<Iter>& x)
{
    return random_access_iterator<Iter>(x.base() - n);
}

}
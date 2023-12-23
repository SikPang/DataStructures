#pragma once

#include <cstddef>	// ptrdiff_t

namespace ft
{

// iterator_category tags
struct input_iterator_tag  {};
struct output_iterator_tag {};
struct forward_iterator_tag       : public input_iterator_tag         {};
struct bidirectional_iterator_tag : public forward_iterator_tag       {};
struct random_access_iterator_tag : public bidirectional_iterator_tag {};


// iterator_traits
template <typename Iter>
struct iterator_traits
{
    typedef typename Iter::value_type           value_type;
    typedef typename Iter::reference            reference;
    typedef typename Iter::pointer              pointer;
    typedef typename Iter::difference_type      difference_type;
    typedef typename Iter::iterator_category    iterator_category;
};

// Specialization template for iterator_traits
template <typename T>
struct iterator_traits<T*>
{
    typedef T                           value_type;
    typedef T&                          reference;
    typedef T*                          pointer;
    typedef ptrdiff_t                   difference_type;
    typedef random_access_iterator_tag  iterator_category;
};

// Specialization template for iterator_traits
template <typename T>
struct iterator_traits<const T*>
{
    typedef T                           value_type;
    typedef const T&                    reference;
    typedef const T*                    pointer;
    typedef ptrdiff_t                   difference_type;
    typedef random_access_iterator_tag  iterator_category;
};


// iterator
template <typename T, typename Category, typename Reference = T&, 
          typename Pointer = T*, typename Distance = ptrdiff_t>
struct iterator
{
    typedef T           value_type;
    typedef Reference   reference;
    typedef Pointer     pointer;
    typedef Distance    difference_type;
    typedef Category    iterator_category;
};

}
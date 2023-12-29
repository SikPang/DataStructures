#pragma once

#include <memory>	// std::allocator, std::allocator_traits
#include "../Iterator/reverse_iterator.hpp"
#include "../Iterator/random_access_iterator.hpp"

namespace ft
{

template <class T, class Alloc = std::allocator<T>>
class vector
{
public:
    typedef T                                           value_type;
    typedef Alloc                                       allocator_type;
    typedef std::allocator_traits<allocator_type>       alloc_traits;
    typedef value_type&                                 reference;
    typedef const value_type&                           const_reference;
    typedef typename alloc_traits::pointer              pointer;
    typedef typename alloc_traits::const_pointer        const_pointer;
    typedef typename alloc_traits::difference_type      difference_type;
    typedef typename alloc_traits::size_type            size_type;	

    typedef ft::random_access_iterator<pointer>         iterator;
    typedef ft::random_access_iterator<const_pointer>   const_iterator;
    typedef ft::reverse_iterator<iterator>              reverse_iterator;
    typedef ft::reverse_iterator<const_iterator>        const_reverse_iterator;

public:
    vector() noexcept
    {

    }
    ~vector()
    {

    }
    
    void clear() noexcept;
};

}
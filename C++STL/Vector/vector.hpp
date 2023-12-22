#pragma once

#include <memory>	// std::allocator, std::allocator_traits
#include "../Iterator/iterator.hpp"

namespace ks
{

template <class T>
class vector_iterator
{

};

template <class T, class Alloc = std::allocator<T>>
class vector
{
public:
	typedef T                                       value_type;
	typedef Alloc                                   allocator_type;
	typedef std::allocator_traits<allocator_type>   alloc_traits;
	typedef value_type&                             reference;
	typedef const value_type&                       const_reference;
	typedef typename alloc_traits::pointer          pointer;
	typedef typename alloc_traits::const_pointer    const_pointer;
	typedef typename alloc_traits::difference_type  difference_type;
	typedef typename alloc_traits::size_type        size_type;

	typedef vector_iterator<value_type>             iterator;
    typedef vector_iterator<const value_type>       const_iterator;
	typedef reverse_iterator<iterator>              reverse_iterator;
	typedef reverse_iterator<const_iterator>        const_reverse_iterator;

public:
	vector() _NOEXCEPT;
	~vector();

	clear() _NOEXCEPT;
};

}
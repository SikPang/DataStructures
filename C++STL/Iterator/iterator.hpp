#pragma once

#include <stddef.h>	// ptrdiff_t

namespace ks
{

// iterator_category tags
struct input_iterator_tag  {};
struct output_iterator_tag {};
struct forward_iterator_tag       : public input_iterator_tag         {};
struct bidirectional_iterator_tag : public forward_iterator_tag       {};
struct random_access_iterator_tag : public bidirectional_iterator_tag {};


// iterator_traits
template <class Iter>
struct iterator_traits
{
    typedef typename Iter::value_type			value_type;
    typedef typename Iter::reference			reference;
    typedef typename Iter::pointer				pointer;
    typedef typename Iter::difference_type		difference_type;
    typedef typename Iter::iterator_category	iterator_category;
};

// Specialization template class for iterator_traits
template <class T>
struct iterator_traits<T*>
{
    typedef T							value_type;
    typedef T&							reference;
    typedef T*							pointer;
    typedef ptrdiff_t					difference_type;
    typedef random_access_iterator_tag	iterator_category;
};


// iterator
template <class T, class Category, 
		  class Reference = T&, class Pointer = T*, class Distance = ptrdiff_t>
struct iterator
{
	typedef T			value_type;
	typedef Reference	reference;
	typedef Pointer		pointer;
	typedef Distance	difference_type;
	typedef Category	iterator_category;
};


// reverse_iterator
template <class Iter>
class reverse_iterator
	: public iterator<typename iterator_traits<Iter>::value_type,
					  typename iterator_traits<Iter>::iterator_category,
					  typename iterator_traits<Iter>::reference,
					  typename iterator_traits<Iter>::pointer,
					  typename iterator_traits<Iter>::difference_type>
{
protected:
	Iter current;

public:
	typedef Iter												iterator_type;
	typedef typename iterator_traits<Iter>::reference			reference;
	typedef typename iterator_traits<Iter>::pointer				pointer;
	typedef typename iterator_traits<Iter>::difference_type		difference_type;

	reverse_iterator();
};




}
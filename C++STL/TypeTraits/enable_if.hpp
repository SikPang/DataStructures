#pragma once

namespace ft
{

template <bool, class Tp = void> 
class enable_if {};

// Specialization template for enable_if
template <class Tp>
class enable_if<true, Tp> 
{
	typedef Tp type;
};

}
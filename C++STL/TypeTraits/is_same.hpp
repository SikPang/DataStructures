#pragma once
#include "./integral_const.hpp"

namespace ft
{

template <class Tp, class Up> 
class is_same           : public false_type {};

// Specialization template for is_same
template <class Tp>
class is_same<Tp, Tp>   : public true_type {};

}
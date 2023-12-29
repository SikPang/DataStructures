#pragma once
#include "./integral_const.hpp"

namespace ft
{

// remove_cv
template <class _Tp>
struct remove_const {
    typedef _Tp type;
};

template <class _Tp>
struct remove_volatile {
    typedef _Tp type;
};

template <class _Tp>
struct remove_cv {
    typedef typename remove_volatile<typename remove_const<_Tp>::type>::type type;
};


// inner is_integral
template <typename Tp>
class _is_integral	: public false_type {};

// Specialization template for _is_integral
template <> class _is_integral<bool>               : public true_type {};
template <> class _is_integral<char>               : public true_type {};
template <> class _is_integral<wchar_t>            : public true_type {};
template <> class _is_integral<short>              : public true_type {};
template <> class _is_integral<int>                : public true_type {};
template <> class _is_integral<long>               : public true_type {};
template <> class _is_integral<long long>          : public true_type {};
template <> class _is_integral<unsigned char>      : public true_type {};
template <> class _is_integral<unsigned short>     : public true_type {};
template <> class _is_integral<unsigned int>       : public true_type {};
template <> class _is_integral<unsigned long>      : public true_type {};
template <> class _is_integral<unsigned long long> : public true_type {};


// is_integral
template <typename Tp>
class is_integral
    : public _is_integral<typename remove_cv<Tp>::type> {};

}
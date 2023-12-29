#pragma once

namespace ft
{

template <typename Tp, Tp v>
class integral_constant
{
public:
    typedef Tp                          value_type;
    typedef integral_constant           type;

public:
    static constexpr const value_type   value;

public:
    inline constexpr operator value_type() const noexcept;
    inline constexpr value_type operator()() const noexcept;
};

// static memnber declaration
template <class Tp, Tp v>
constexpr const Tp integral_constant<Tp, v>::value = v;

// 변환 연산자 (객체를 타입에 대입할 때 호출)
template <typename Tp, Tp v>
inline constexpr integral_constant<Tp, v>::operator value_type() const noexcept
{
    return value;
}

template <typename Tp, Tp v>
inline constexpr integral_constant<Tp, v>::value_type integral_constant<Tp, v>::operator()() const noexcept
{
    return value;
}

typedef integral_constant<bool, true> true_type;
typedef integral_constant<bool, true> false_type;

}
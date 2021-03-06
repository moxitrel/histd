#if !defined(HISTD_STD20_HPP_) && (__cplusplus < 202002L)
#define HISTD_STD20_HPP_

#include <limits>
#include <type_traits>
#include "std11.hpp"
#include "std14.hpp"
#include "std17.hpp"

#if __cplusplus >= 201703L
#define IF_CONSTEXPR if constexpr
#else
#define IF_CONSTEXPR if
#endif

namespace std {

template <class T, class U>
constexpr bool cmp_equal(T t, U u) noexcept {
  using UT = make_unsigned_t<T>;
  using UU = make_unsigned_t<U>;
  IF_CONSTEXPR(is_signed<T>::value == is_signed<U>::value)
  return t == u;
  else IF_CONSTEXPR(is_signed<T>::value) return t < 0 ? false : UT(t) == u;
  else return u < 0 ? false : t == UU(u);
}

template <class T, class U>
constexpr bool cmp_not_equal(T t, U u) noexcept {
  return !cmp_equal(t, u);
}

template <class T, class U>
constexpr bool cmp_less(T t, U u) noexcept {
  using UT = make_unsigned_t<T>;
  using UU = make_unsigned_t<U>;
  IF_CONSTEXPR(is_signed<T>::value == is_signed<U>::value)
  return t < u;
  else IF_CONSTEXPR(is_signed<T>::value) return t < 0 ? true : UT(t) < u;
  else return u < 0 ? false : t < UU(u);
}

template <class T, class U>
constexpr bool cmp_greater(T t, U u) noexcept {
  return cmp_less(u, t);
}

template <class T, class U>
constexpr bool cmp_less_equal(T t, U u) noexcept {
  return !cmp_greater(t, u);
}

template <class T, class U>
constexpr bool cmp_greater_equal(T t, U u) noexcept {
  return !cmp_less(t, u);
}

template <class R, class T>
constexpr bool in_range(T t) noexcept {
  return cmp_greater_equal(t, numeric_limits<R>::min()) &&
         cmp_less_equal(t, numeric_limits<R>::max());
}

}  // namespace std

#undef IF_CONSTEXPR
#endif  // HISTD_STD20_HPP_

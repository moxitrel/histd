#ifndef HPPXT_TYPE_HPP_
#define HPPXT_TYPE_HPP_

#include <type_traits>

namespace hppxt {

//
// lvalueof: rvalue -> lvalue
//
template <typename T>
constexpr auto& lvalueof(std::add_rvalue_reference_t<T> x) {
  return x;
}

//
// TypeOf: Show the type of variable in compiler error message
//
// Usage: TypeOf<decltype(x)> _t;
//
template <typename T>
class TypeOf;

//
// rebind_pointer_cv: const volatile S* -> const volatile T*
//
template <typename T, typename S>
constexpr auto rebind_pointer_cv(S* p) {
  return reinterpret_cast<T*>(p);
}

template <typename T, typename S>
constexpr auto rebind_pointer_cv(const S* p) {
  return reinterpret_cast<const T*>(p);
}

template <typename T, typename S>
constexpr auto rebind_pointer_cv(volatile S* p) {
  return reinterpret_cast<volatile T*>(p);
}

template <typename T, typename S>
constexpr auto rebind_pointer_cv(const volatile S* p) {
  return reinterpret_cast<const volatile T*>(p);
}

/////////////////////////////////

#include <string>

template <typename T>
constexpr std::string_view TypeOf() {
#if defined(__clang__)
  std::string_view p = __PRETTY_FUNCTION__;
  return std::string_view(p.data() + 34, p.size() - 34 - 1);

#elif defined(__GNUC__)
  std::string_view p = __PRETTY_FUNCTION__;
#if __cplusplus < 201402
  return std::string_view(p.data() + 36, p.size() - 36 - 1);
#else
  return std::string_view(p.data() + 49, p.find(';', 49) - 49);
#endif

#elif defined(_MSC_VER)
  std::string_view p = __FUNCSIG__;
  return std::string_view(p.data() + 84, p.size() - 84 - 7);

#endif
}

}  // namespace hppxt

#endif  // HPPXT_TYPE_HPP_

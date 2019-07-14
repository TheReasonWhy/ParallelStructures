#ifndef MEM_FUN_TRAITS_HPP
#define MEM_FUN_TRAITS_HPP
template<typename> struct MemFunTraits;

template<typename T, typename R, typename... A>
struct MemFunTraits<R(T::*)(A...)> {  using ResultType = R ; };
#endif // MEM_FUN_TRAITS_HPP

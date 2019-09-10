#ifndef HAS_FUNCTION_HPP
#define HAS_FUNCTION_HPP
#include"type_traits"

template<typename T> struct has_foo{
private:
    static int detect(...);
    template<typename U> static decltype(std::declval<U>().get_value()) detect(const U&);

public:
    static constexpr bool value = std::is_same<unsigned, decltype(detect(std::declval<T>()))>::value;
};


template<typename T> struct is_callable{
private:
    static int detect(...);
    template<typename U> static decltype(std::declval<U>()()) detect(const U&);

public:
    static constexpr bool value = std::is_same<unsigned, decltype(detect(std::declval<T>()))>::value;
};

template<typename T> struct is_indexed{
private:
    static int detect(...);
    template<typename U> static decltype(std::declval<U>().index()) detect(const U&);

public:
    static constexpr bool value = std::is_same<unsigned, decltype(detect(std::declval<T>()))>::value;
};
#endif // HAS_FUNCTION_HPP

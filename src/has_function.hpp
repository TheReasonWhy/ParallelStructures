#ifndef HAS_FUNCTION_HPP
#define HAS_FUNCTION_HPP
#include"type_traits"

template<typename T> struct has_foo{
private:  // Спрячем от пользователя детали реализации.
    static int detect(...);  // Статическую функцию и вызывать проще.
    template<typename U> static decltype(std::declval<U>().get_value()) detect(const U&);

public:
    static constexpr bool value = std::is_same<unsigned, decltype(detect(std::declval<T>()))>::value;  // Вот видите, готово.
};


template<typename T> struct is_callable{
private:  // Спрячем от пользователя детали реализации.
    static int detect(...);  // Статическую функцию и вызывать проще.
    template<typename U> static decltype(std::declval<U>()()) detect(const U&);

public:
    static constexpr bool value = std::is_same<unsigned, decltype(detect(std::declval<T>()))>::value;  // Вот видите, готово.
};

template<typename T> struct is_indexed{
private:  // Спрячем от пользователя детали реализации.
    static int detect(...);  // Статическую функцию и вызывать проще.
    template<typename U> static decltype(std::declval<U>().index()) detect(const U&);

public:
    static constexpr bool value = std::is_same<unsigned, decltype(detect(std::declval<T>()))>::value;  // Вот видите, готово.
};

#endif // HAS_FUNCTION_HPP

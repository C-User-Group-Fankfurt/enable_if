#include <legacy_messages/message_a.h>
#include <legacy_messages/message_b.h>
#include <legacy_messages/message_c.h>

#include <cstdlib>
#include <iostream>

// I promise, this is the worst part of the session! 😅
// And we will refactor the code nicely later.

// For every value of T in the template there will be a new type of the struct
template <class T, T v> struct integral_constant {
  static constexpr T value = v;
  using value_type = T;
  using type = integral_constant;
  explicit constexpr operator value_type() const noexcept { return value; }
  constexpr value_type operator()() const noexcept { return value; }
};

using false_type = integral_constant<bool, false>;
using true_type = integral_constant<bool, true>;

template <typename T> struct is_message : false_type {};
// template <typename T> struct is_message<const T> : is_message<T> {};

template <> struct is_message<legacy_messages::MessageA> : true_type {};

const legacy_messages::Header &
getHeader(const legacy_messages::MessageA &message) {
  return message.header;
}

template <> struct is_message<legacy_messages::MessageB> : std::true_type {};

const legacy_messages::Hdr &
getHeader(const legacy_messages::MessageB &message) {
  return message.hdr;
}

template <> struct is_message<legacy_messages::MessageC> : std::true_type {};

const legacy_messages::Description &
getHeader(const legacy_messages::MessageC &message) {
  return message.description;
}

template <bool B, class T = void> struct enable_if {};

template <class T> struct enable_if<true, T> {
  typedef T type;
};

template <class Message>
typename enable_if<is_message<Message>::value, void>::type
printTimestamp(const Message &message) {
  const auto &header = getHeader(message);
  std::cout << header.stamp << std::endl;
}

int main() {
  constexpr legacy_messages::MessageA a{};
  constexpr legacy_messages::MessageB b{};
  constexpr legacy_messages::MessageC c{};

  std::cout << std::boolalpha;

  /*
   * Note: decltype() is not a function, it's a specifier:
   *  https://en.cppreference.com/w/cpp/language/decltype
   */
  std::cout << "is_message(a) = " << is_message<decltype(a)>::value << " : ";
  printTimestamp(a);

  std::cout << "is_message(b) = " << is_message<decltype(b)>::value << " : ";
  printTimestamp(b);

  std::cout << "is_message(c) = " << is_message<decltype(c)>::value << " : ";
  printTimestamp(c);

  std::cout << "is_message(int) = " << is_message<decltype(25)>::value;
  // printTimestamp(25);

  // Unfortunately, our code is wrong!

  return EXIT_SUCCESS;
}

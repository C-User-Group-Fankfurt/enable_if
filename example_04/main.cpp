#include <legacy_messages/message_a.h>
#include <legacy_messages/message_b.h>
#include <legacy_messages/message_c.h>

#include <cstdlib>
#include <iostream>
#include <type_traits>

template <typename T> struct is_message : std::false_type {};
template <typename T> struct is_message<const T> : is_message<T> {};

template <> struct is_message<legacy_messages::MessageA> : std::true_type {};

legacy_messages::Header getHeader(const legacy_messages::MessageA &message) {
  return message.header;
}

template <> struct is_message<legacy_messages::MessageB> : std::true_type {};

legacy_messages::Hdr getHeader(const legacy_messages::MessageB &message) {
  return message.hdr;
}

template <> struct is_message<legacy_messages::MessageC> : std::true_type {};

legacy_messages::Description
getHeader(const legacy_messages::MessageC &message) {
  return message.description;
}

template <class Message>
typename std::enable_if<is_message<Message>::value, void>::type
printTimestamp(const Message &message) {
  auto header = getHeader(message);
  std::cout << header.stamp << std::endl;
}

int main() {
  constexpr legacy_messages::MessageA a{};
  constexpr legacy_messages::MessageB b{};
  constexpr legacy_messages::MessageC c{};

  std::cout << std::boolalpha;
  std::cout << "is_message(a) = " << is_message<decltype(a)>::value << " : ";
  printTimestamp(a);

  std::cout << "is_message(b) = " << is_message<decltype(b)>::value << " : ";
  printTimestamp(b);

  std::cout << "is_message(c) = " << is_message<decltype(c)>::value << " : ";
  printTimestamp(c);

  std::cout << "is_message(int) = " << is_message<decltype(25)>::value << " : ";
  // printTimestamp(25);

  return EXIT_SUCCESS;
}

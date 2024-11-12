#include <legacy_messages/message_a.h>
#include <legacy_messages/message_b.h>
#include <legacy_messages/message_c.h>
#include <legacy_messages/message_d.h>

#include <cstdlib>
#include <iostream>
#include <type_traits>

template <typename T> struct is_message : std::false_type {};
template <typename T> struct is_message<const T> : is_message<T> {};

template <typename T> constexpr bool is_message_v = is_message<T>::value;
template <typename T> using is_message_t = typename is_message<T>::type;

template <> struct is_message<legacy_messages::MessageA> : std::true_type {};
template <> struct is_message<legacy_messages::MessageB> : std::true_type {};
template <> struct is_message<legacy_messages::MessageC> : std::true_type {};
template <> struct is_message<legacy_messages::MessageD> : std::true_type {};

template <typename Message>
std::enable_if_t<is_message_v<Message>, const decltype(Message::header) &>
getHeader(const Message &message) {
  return message.header;
}

template <typename Message>
std::enable_if_t<is_message_v<Message>, const decltype(Message::hdr) &>
getHeader(const Message &message) {
  return message.hdr;
}

template <typename Message>
std::enable_if_t<is_message_v<Message>, const decltype(Message::description) &>
getHeader(const Message &message) {
  return message.description;
}

template <class Message>
typename std::enable_if_t<is_message_v<Message>, void>
printTimestamp(const Message &message) {
  const auto &header = getHeader(message);
  std::cout << header.stamp << std::endl;
}

int main() {
  constexpr legacy_messages::MessageA a{};
  constexpr legacy_messages::MessageB b{};
  constexpr legacy_messages::MessageC c{};
  constexpr legacy_messages::MessageD d{};

  std::cout << std::boolalpha;

  std::cout << "is_message(a) = " << is_message_v<decltype(a)> << " : ";
  printTimestamp(a);

  std::cout << "is_message(b) = " << is_message_v<decltype(b)> << " : ";
  printTimestamp(b);

  std::cout << "is_message(c) = " << is_message_v<decltype(c)> << " : ";
  printTimestamp(c);

  std::cout << "is_message(d) = " << is_message_v<decltype(d)> << " : ";
  printTimestamp(d);

  std::cout << "is_message(int) = " << is_message_v<decltype(25)>;
  // printTimestamp(25);

  return EXIT_SUCCESS;
}

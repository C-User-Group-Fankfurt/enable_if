#include <legacy_messages/message_a.h>
#include <legacy_messages/message_b.h>
#include <legacy_messages/message_c.h>

#include <cstdlib>
#include <iostream>

legacy_messages::Header getHeader(const legacy_messages::MessageA &message) {
  return message.header;
}

legacy_messages::Hdr getHeader(const legacy_messages::MessageB &message) {
  return message.hdr;
}

legacy_messages::Description
getHeader(const legacy_messages::MessageC &message) {
  return message.description;
}

template <class Message> void printTimestamp(const Message &message) {
  auto header = getHeader(message);
  std::cout << header.stamp << std::endl;
}

int main() {
  constexpr legacy_messages::MessageA a{};
  constexpr legacy_messages::MessageB b{};
  constexpr legacy_messages::MessageC c{};

  printTimestamp(a);
  printTimestamp(b);
  printTimestamp(c);

  /*
   * Substitution failure is not an error (SFINAE) is a principle in C++ where
   * an invalid substitution of template parameters is not in itself an error.
   */
  // printTimestamp(25);

  /*
   * type traits:
   *   compile time property of types, which can be used for metaprogramming.
   */
  std::cout << std::boolalpha;
  std::cout << std::is_floating_point<double>::value << std::endl;
  std::cout << std::is_floating_point<float>::value << std::endl;
  std::cout << std::is_floating_point<int>::value << std::endl;

  return EXIT_SUCCESS;
}

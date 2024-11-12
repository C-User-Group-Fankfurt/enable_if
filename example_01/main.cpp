#include <legacy_messages/message_a.h>
#include <legacy_messages/message_b.h>
#include <legacy_messages/message_c.h>

#include <cstdlib>
#include <iostream>

int main() {
  constexpr legacy_messages::MessageA a{};
  constexpr legacy_messages::MessageB b{};
  constexpr legacy_messages::MessageC c{};

  std::cout << a.header.stamp << std::endl;
  std::cout << b.hdr.stamp << std::endl;
  std::cout << c.description.stamp << std::endl;

  return EXIT_SUCCESS;
}

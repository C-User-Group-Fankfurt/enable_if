#ifndef MESSAGE_A_H
#define MESSAGE_A_H

#include <legacy_messages/timestamp.h>

namespace legacy_messages {
struct Header {
  Timestamp stamp{42};
};

struct MessageA {
  Header header;
};
} // namespace legacy_messages
#endif // MESSAGE_A_H

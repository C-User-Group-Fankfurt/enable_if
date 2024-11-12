#ifndef MESSAGE_B_H
#define MESSAGE_B_H

#include <legacy_messages/timestamp.h>

namespace legacy_messages {
struct Hdr {
  Timestamp stamp{43};
};

struct MessageB {
  Hdr hdr;
};
} // namespace legacy_messages
#endif // MESSAGE_B_H

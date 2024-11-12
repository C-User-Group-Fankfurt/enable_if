#ifndef MESSAGE_C_H
#define MESSAGE_C_H

#include <legacy_messages/timestamp.h>

namespace legacy_messages {
struct Description {
  Timestamp stamp{44};
};

struct MessageC {
  Description description;
};
} // namespace legacy_messages
#endif // MESSAGE_C_H

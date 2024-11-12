#ifndef MESSAGE_D_H
#define MESSAGE_D_H

#include <legacy_messages/timestamp.h>

namespace legacy_messages {

struct MessageD {
  struct Header {
    Timestamp stamp{45};
  };
  Header header;
};
} // namespace legacy_messages


#endif //MESSAGE_D_H

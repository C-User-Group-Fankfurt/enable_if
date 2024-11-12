add_library(legacy_messages
        include/legacy_messages/message_a.h
        include/legacy_messages/message_b.h
        include/legacy_messages/message_c.h
        include/legacy_messages/message_d.h
        dummy.cpp
        include/legacy_messages/message_d.h
)
add_library(legacy_messages::legacy_messages ALIAS
            legacy_messages)

target_include_directories(legacy_messages
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

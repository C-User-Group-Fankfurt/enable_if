add_executable(example_04 main.cpp)

target_link_libraries(
        example_04 PRIVATE legacy_messages::legacy_messages)

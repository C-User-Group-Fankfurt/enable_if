add_executable(example_01 main.cpp)

target_link_libraries(example_01 PRIVATE legacy_messages::legacy_messages)

add_executable(example_02 main.cpp)

target_link_libraries(
  example_02 PRIVATE legacy_messages::legacy_messages)

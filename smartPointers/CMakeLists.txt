set(TARGET_NAME cpp_smart_pointers)
set(TARGET_NAME_LEAK leak_memory)

add_executable(${TARGET_NAME} smart_pointers.cpp
        smart_pointers_utils.h)

add_executable(${TARGET_NAME_LEAK} leak_memory.cpp)
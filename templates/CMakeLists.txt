set(TARGET_NAME cpp_templates)
set(TARGET_NAME_EX cpp_templates_ex)

add_executable(${TARGET_NAME} template_example.cpp)
add_executable(${TARGET_NAME_EX}
        template_exercises.cpp
        template_exercises.h
        )

# OpenCV_DIR
find_package(OpenCV REQUIRED)
set (OpenCV_USE_STATIC_LIBS ON)
include_directories(${OpenCV_INCLUDE_DIRS})


set(TARGET_NAME cpp_opencv)

add_executable(${TARGET_NAME} show_image.cpp
        image_utils.h)

target_link_libraries(cpp_opencv ${OpenCV_LIBS})
# OpenCV_DIR
find_package(OpenCV REQUIRED PATHS "C:/opencv/opencv/build/x64/vc16/lib")
include_directories( ${OpenCV_INCLUDE_DIRS} )


set(TARGET_NAME cpp_opencv)

add_executable(${TARGET_NAME} show_image.cpp)

target_link_libraries(cpp_opencv ${OpenCV_LIBS})
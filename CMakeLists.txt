cmake_minimum_required(VERSION 3.5)

project(cpp_python_api_tests)

find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})

add_executable(main main.cpp)
target_link_libraries(main ${PYTHON_LIBRARIES})

install(TARGETS main DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
message(${CMAKE_CURRENT_BINARY_DIR})
install(FILES printing_tests.py DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
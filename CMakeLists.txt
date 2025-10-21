cmake_minimum_required(VERSION 3.15)
project(cpp_blackbox_demo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(odr)
add_subdirectory(layout)
add_subdirectory(template-specialization)
add_subdirectory(type_traits)
add_subdirectory(RTTI)
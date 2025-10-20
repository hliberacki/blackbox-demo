cmake_minimum_required(VERSION 3.15)
project(cpp_blackbox_demo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# if (MSVC)
#     add_compile_options(/W4 /WX)
# else()
#     add_compile_options(-Wall -Wextra -Wpedantic -Werror)
# endif()

add_subdirectory(define-private-public)
add_subdirectory(layout)
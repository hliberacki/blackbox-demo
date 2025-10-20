cmake_minimum_required(VERSION 3.14)
project(cpp-blackbox-demo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Example 01: Private/Public Access Control
add_executable(01_define_private_public
    01_define_private_public/main.cpp
)

# Example 02: Pointer Offset Cast
add_executable(02_pointer_offset_cast
    02_pointer_offset_cast/example.cpp
)

# Example 03: Friend Injection
add_executable(03_friend_injection
    03_friend_injection/example.cpp
)

# Example 04: Template Alias Trick
add_executable(04_template_alias_trick
    04_template_alias_trick/example.cpp
)

# Example 05: Accessor Pattern
add_executable(05_accessor_pattern
    05_accessor_pattern/example.cpp
)

# Enable warnings
if(MSVC)
    target_compile_options(01_define_private_public PRIVATE /W4)
    target_compile_options(02_pointer_offset_cast PRIVATE /W4)
    target_compile_options(03_friend_injection PRIVATE /W4)
    target_compile_options(04_template_alias_trick PRIVATE /W4)
    target_compile_options(05_accessor_pattern PRIVATE /W4)
else()
    target_compile_options(01_define_private_public PRIVATE -Wall -Wextra -Wpedantic)
    target_compile_options(02_pointer_offset_cast PRIVATE -Wall -Wextra -Wpedantic)
    target_compile_options(03_friend_injection PRIVATE -Wall -Wextra -Wpedantic)
    target_compile_options(04_template_alias_trick PRIVATE -Wall -Wextra -Wpedantic)
    target_compile_options(05_accessor_pattern PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Add a custom target to build all examples
add_custom_target(all_examples
    DEPENDS
        01_define_private_public
        02_pointer_offset_cast
        03_friend_injection
        04_template_alias_trick
        05_accessor_pattern
)

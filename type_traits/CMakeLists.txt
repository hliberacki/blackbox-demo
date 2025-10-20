add_executable(type_traits_inheritance
    example.cpp
)

target_include_directories(type_traits_inheritance
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

set_target_properties(type_traits_inheritance PROPERTIES
    OUTPUT_NAME "type_traits_inheritance"
)

# Test build (with TEST_ACCESS_PRIVATE defined)
add_executable(type_traits_miss_inheritance
    example.cpp
)
target_include_directories(type_traits_miss_inheritance
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)
target_compile_definitions(type_traits_miss_inheritance PRIVATE TEST_ACCESS_PRIVATE)
set_target_properties(type_traits_miss_inheritance PROPERTIES
    OUTPUT_NAME "type_traits_miss_inheritance"
)
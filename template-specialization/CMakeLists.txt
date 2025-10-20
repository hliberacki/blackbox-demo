add_executable(template-specialization
    example.cpp
)

target_include_directories(template-specialization
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

set_target_properties(template-specialization PROPERTIES
    OUTPUT_NAME "template-specialization"
)

# Test build (with TEST_ACCESS_PRIVATE defined)
add_executable(template-miss-specialization
    example.cpp
)
target_include_directories(template-miss-specialization
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)
target_compile_definitions(template-miss-specialization PRIVATE TEST_ACCESS_PRIVATE)
set_target_properties(template-miss-specialization PROPERTIES
    OUTPUT_NAME "template-miss-specialization"
)
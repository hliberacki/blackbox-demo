add_executable(layout_prod
    example.cpp
)
target_include_directories(layout_prod
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)
set_target_properties(layout_prod PROPERTIES
    OUTPUT_NAME "layout-normal"
)

# Test build (with TEST_ACCESS_PRIVATE defined)
add_executable(layout_test
    example.cpp
)
target_include_directories(layout_test
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)
target_compile_definitions(layout_test PRIVATE TEST_ACCESS_PRIVATE)
set_target_properties(layout_test PROPERTIES
    OUTPUT_NAME "layout-test-access-private"
)
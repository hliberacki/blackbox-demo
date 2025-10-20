add_executable(rtti
    example.cpp
)

target_include_directories(rtti
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

set_target_properties(rtti PROPERTIES
    OUTPUT_NAME "rtti"
)

# Test build (with TEST_ACCESS_PRIVATE defined)
add_executable(rtti-missmatch
    example.cpp
)
target_include_directories(rtti-missmatch
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)
target_compile_definitions(rtti-missmatch PRIVATE TEST_ACCESS_PRIVATE)
set_target_properties(rtti-missmatch PROPERTIES
    OUTPUT_NAME "rtti-missmatch"
)
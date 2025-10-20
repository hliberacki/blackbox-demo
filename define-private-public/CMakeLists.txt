add_executable(define_private_public
    example.cpp
)

target_include_directories(define_private_public
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

find_package(nlohmann_json CONFIG REQUIRED)
target_link_libraries(define_private_public PRIVATE nlohmann_json::nlohmann_json)

set_target_properties(define_private_public PROPERTIES
    OUTPUT_NAME "define-private-public"
)

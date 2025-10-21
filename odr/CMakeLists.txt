add_executable(odr-failure
    example.cpp
)

target_include_directories(odr-failure
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

find_package(nlohmann_json CONFIG REQUIRED)
target_link_libraries(odr-failure PRIVATE nlohmann_json::nlohmann_json)

set_target_properties(odr-failure PROPERTIES
    OUTPUT_NAME "odr-failure"
)

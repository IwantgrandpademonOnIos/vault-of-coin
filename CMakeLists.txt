cmake_minimum_required(VERSION 3.15)
project(clockvault)

add_library(${PROJECT_NAME} SHARED
    src/main.cpp
    src/ClockVaultLayer.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE src)
target_link_libraries(${PROJECT_NAME} geode-sdk)

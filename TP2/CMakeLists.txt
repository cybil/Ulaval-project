cmake_minimum_required(VERSION 2.6)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS} ./headers ./interfaces)

add_executable(air-GLOIFT.exe sources/)
target_link_libraries(air-GLOIFT.exe ${GTEST_LIBRARIES} pthread)
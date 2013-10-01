cmake_minimum_required(VERSION 2.6)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS} ./headers ./interfaces)

add_executable(mySolitaire.exe sources/jeuSolitaire.cpp sources/Cartes.cpp)
target_link_libraries(mySolitaire.exe ${GTEST_LIBRARIES} pthread)
cmake_minimum_required(VERSION 2.8)
 
###
# Compilation flags
if (CMAKE_COMPILER_IS_GNUCXX OR CMAKE_COMPILER_IS_CLANGXX)
  # g++ / clang++
  set (CMAKE_CXX_FLAGS "-Wextra -g3")
  set (CMAKE_CXX_FLAGS_DEBUG "-O0 -ggdb -DDEBUG")
  set (CMAKE_CXX_FLAGS_RELEASE "-O2 -DRELEASE")
elseif (MSVC)
  # MS Visual Studio
  # add_definitions( /D _VARIADIC_MAX=10)
  set (CMAKE_CXX_FLAGS "-D_VARIADIC_MAX=10")
  set (CMAKE_CXX_LINK_FLAGS "${CMAKE_CXX_LINK_FLAGS}")
  set (CMAKE_CXX_FLAGS_DEBUG "/MT /EHsc")
  set (CMAKE_CXX_FLAGS_RELEASE "/MT /EHsc")
endif ()

# Binary name
set (BIN_NAME "tp3")

# Source files
set (HEADER_FILES
  "Adresse.h"
  "Annuaire.h"
  "ArbreAVL.h"
  "ArbreAVL.hpp"
  "ArbreGenealogique.h"
  "Personne.h"
)

set (MAIN_FILE
  "main.cpp"
)

set (SOURCE_FILES
  "Adresse.cpp"
  "Annuaire.cpp"
  "ArbreGenealogique.cpp"
  "Personne.cpp"
)

set (TEST_FILES
  "TesteurAnnuaire.cpp"
  "TesteurArbreAVL.cpp"
  "TesteurArbreGenealogique.cpp"
)

include_directories(./)

if (CMAKE_COMPILER_IS_GNUCXX OR CMAKE_COMPILER_CLANGXX)
  # Compile project
  add_executable(${BIN_NAME} ${MAIN_FILE} ${SOURCE_FILES})

  # Locate GTest
  find_package(GTest REQUIRED)
  include_directories(${GTEST_INCLUDE_DIRS})
 
  # Link runTests with what we want to test and the GTest and pthread library
  add_executable(runTests ${TEST_FILES} ${SOURCE_FILES})
  target_link_libraries(runTests ${GTEST_LIBRARY} ${GTEST_MAIN_LIBRARY} pthread)
elseif (MSVC)
  # Compile project
  add_executable(${BIN_NAME} ${HEADER_FILES} ${MAIN_FILE} ${SOURCE_FILES})

  # Link runTests with what we want to test and the GTest library
  add_executable(runTests ${HEADER_FILES} ${TEST_FILES} ${SOURCE_FILES})
  target_link_libraries(runTests ./gtest ./gtest_main)
endif ()

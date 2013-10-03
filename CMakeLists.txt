cmake_minimum_required(VERSION 2.6)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS} ./headers ./interfaces)

add_executable(mySolitaire.exe sources/solitaireTesteur.cpp sources/Cartes.cpp sources/Solitaire.cpp sources/Colonne.cpp)
target_link_libraries(mySolitaire.exe ${GTEST_LIBRARIES} pthread)
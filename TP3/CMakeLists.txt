cmake_minimum_required(VERSION 2.6)

find_package(GTest REQUIRED)

add_executable(tp3 main.cpp Adresse.cpp Annuaire.cpp ArbreGenealogique.cpp Personne.cpp)
target_link_libraries(tp3 ${GTEST_LIBRARIES} pthread)
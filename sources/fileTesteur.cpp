//! \file fileTesteur.cpp
//! \brief Google Test File.
//! \author Benjamin De Almeida - BEDEA1
//! \version 1.0
//! \date 02 octobre 2013
//!
//! Google Test file

#include <iostream>
#include "gtest/gtest.h"
#include "File.h"
#include "Carte.h"

TEST(testEnfiler, estEnfile)
{
  File<int>	test;

  test.enfiler(1);
  EXPECT_TRUE(test.taille() == 1);
}

TEST(testDefiler, estDefile)
{
  File<int>	test;

  test.enfiler(1);
  EXPECT_TRUE(test.taille() == 1);
  EXPECT_TRUE(test.defiler());
}

TEST(TestVide, estVide)
{
  File<int>	test;

  EXPECT_TRUE(test.estVide());  
}

TEST(testPleine, estPleine)
{
  File<int>	test(1);
  
  EXPECT_FALSE(test.estPleine());
  test.enfiler(1);
  EXPECT_TRUE(test.estPleine());
}

TEST(testPremier, estPremierDeLaListe)
{
  File<int>	test;

  test.enfiler(1);
  test.enfiler(0);
  test.enfiler(1);
  EXPECT_TRUE(test.premier());
}

TEST(testDernier, estDernierDeLaListe)
{
  File<int>	test;

  test.enfiler(1);
  test.enfiler(0);
  test.enfiler(1);
  EXPECT_TRUE(test.dernier());
}

TEST(testAccesseur, estAccessible)
{
  File<int>	test;

  test.enfiler(1);
  test.enfiler(0);
  test.enfiler(1);
  EXPECT_FALSE(test[1]);
  EXPECT_TRUE(test[0]);
}
/*
int		main(int ac, char **av)
{
  ::testing::InitGoogleTest(&ac, av);
  return RUN_ALL_TESTS();
}
*/

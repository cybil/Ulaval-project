//! \file pileTesteur.cpp
//! \brief Google Test Pile.
//! \author Benjamin De Almeida - BEDEA1
//! \version 1.0
//! \date 02 octobre 2013
//!
//! Google Test Pile

#include <iostream>
#include "gtest/gtest.h"
#include "Pile.h"

TEST(testEmpiler, aEuUnElementEnPlus)
{
  Pile<int> test;

  test.empiler(1);
  EXPECT_TRUE(1 == test.top());
}

TEST(testDepiler, estDepile)
{
  Pile<int> test;

  test.empiler(1);
  EXPECT_TRUE(1 == test.top());
  EXPECT_TRUE(test.depiler() == 1);
  EXPECT_TRUE(test.taille() == 0);
}

TEST(testEstVide, estVide)
{
   Pile<int> test;
   
   EXPECT_TRUE(test.estVide());
   test.empiler(1);
   EXPECT_FALSE(test.estVide());
}

TEST(testTop, accesAuPremier)
{
  Pile<int> test;

  test.empiler(1);
  EXPECT_TRUE(1 == test.top());
}

TEST(testAccesseur, aEuAcces)
{
  Pile<int> test;

  test.empiler(1);
  EXPECT_TRUE(test[1]);
}

int		main(int ac, char **av)
{
  ::testing::InitGoogleTest(&ac, av);
  return RUN_ALL_TESTS();
}

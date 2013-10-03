//! \file cartesTesteur.cpp
//! \brief Google Test Cartes.
//! \author Benjamin De Almeida - BEDEA1
//! \version 1.0
//! \date 02 octobre 2013
//!
//! Google Test Carte

#include <iostream>
#include "gtest/gtest.h"
#include "Carte.h"


TEST(testSorte, estMemeCarte)
{
  Carte	c1(Carte::AS, Carte::COEUR);
  Carte	c2(Carte::AS, Carte::COEUR);
  Carte	c3(Carte::TROIS, Carte::PIQUE);

  EXPECT_TRUE(c1 == c2);
  EXPECT_FALSE(c1 == c3);
}

TEST(testOrdre, estCarteSuivante)
{
  Carte	c1(Carte::AS, Carte::COEUR);
  Carte	c2(Carte::DEUX, Carte::COEUR);

  EXPECT_TRUE(c1 < c2);
  EXPECT_FALSE(c2 < c1);
}

TEST(testOrdre, estCartePrecedente)
{
  Carte	c1(Carte::DIX, Carte::COEUR);
  Carte	c2(Carte::VALET, Carte::TREFLE);

  EXPECT_FALSE(c1 > c2);
  EXPECT_TRUE(c2 > c1);
}

TEST(testSuperposition, estSuperposablePile)
{
  Carte	c1(Carte::CINQ, Carte::CARREAU);
  Carte	c2(Carte::SIX, Carte::CARREAU);
  Carte	c3(Carte::SIX, Carte::PIQUE);
  Carte	c4(Carte::HUIT, Carte::CARREAU);

  EXPECT_TRUE(c2 >= c1);
  EXPECT_FALSE(c3 >= c1);
  EXPECT_FALSE(c4 >= c2);
}

TEST(testSuperposition, estSuperposableColonne)
{
  Carte	c1(Carte::DIX, Carte::COEUR);
  Carte	c2(Carte::VALET, Carte::TREFLE);
  Carte	c3(Carte::SIX, Carte::PIQUE);
  Carte	c4(Carte::SEPT, Carte::TREFLE);

  EXPECT_TRUE(c1 <= c2);
  EXPECT_FALSE(c2 <= c1);
  EXPECT_FALSE(c3 <= c4);
}

int		main(int ac, char **av)
{
  ::testing::InitGoogleTest(&ac, av);
  return RUN_ALL_TESTS();
}

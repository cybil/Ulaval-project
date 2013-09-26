#include <iostream>
#include "gtest/gtest.h"
#include "Cartes.h"


TEST(testSorte, estMemeSorte)
{
  Cartes	c1(Cartes::AS, Cartes::COEUR);
  Cartes	c2(Cartes::ROI, Cartes::COEUR);
  Cartes	c3(Cartes::TROIS, Cartes::PIQUE);

  EXPECT_TRUE(c1 == c2);
  EXPECT_FALSE(c1 == c3);
}

TEST(testOrdre, estCarteSuivante)
{
  Cartes	c1(Cartes::AS, Cartes::COEUR);
  Cartes	c2(Cartes::DEUX, Cartes::COEUR);

  EXPECT_TRUE(c1 < c2);
  EXPECT_FALSE(c2 < c1);
}

TEST(testOrdre, estCartePrecedente)
{
  Cartes	c1(Cartes::DIX, Cartes::COEUR);
  Cartes	c2(Cartes::VALET, Cartes::TREFLE);

  EXPECT_FALSE(c1 > c2);
  EXPECT_TRUE(c2 > c1);
}

TEST(testSuperposition, estSuperposablePile)
{
  Cartes	c1(Cartes::CINQ, Cartes::CARREAU);
  Cartes	c2(Cartes::SIX, Cartes::CARREAU);
  Cartes	c3(Cartes::SIX, Cartes::PIQUE);
  Cartes	c4(Cartes::HUIT, Cartes::CARREAU);

  EXPECT_TRUE(c2 >= c1);
  EXPECT_FALSE(c3 >= c1);
  EXPECT_FALSE(c4 >= c2);
}

TEST(testSuperposition, estSuperposableColonne)
{
  Cartes	c1(Cartes::DIX, Cartes::COEUR);
  Cartes	c2(Cartes::VALET, Cartes::TREFLE);
  Cartes	c3(Cartes::SIX, Cartes::PIQUE);
  Cartes	c4(Cartes::SEPT, Cartes::TREFLE);

  EXPECT_TRUE(c1 <= c2);
  EXPECT_FALSE(c2 <= c1);
  EXPECT_FALSE(c3 <= c4);
}

int		main(int ac, char **av)
{
  ::testing::InitGoogleTest(&ac, av);
  return RUN_ALL_TESTS();
}

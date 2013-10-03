//! \file colonneTesteur.cpp
//! \brief Google Test Cartes.
//! \author Benjamin De Almeida - BEDEA1
//! \version 1.0
//! \date 02 octobre 2013
//!
//! Google Test COlonne

#include <iostream>
#include "gtest/gtest.h"
#include "Colonne.h"

TEST(testGetTailleListeListe, laGetTailleListeSeModifie)
{
  ColonneCarte	test;
  Cartes	carte1(Cartes::ROI, Cartes::COEUR);

  EXPECT_TRUE(0 == test.getTailleListe());
  test.ajoute(carte1);
  EXPECT_TRUE(1 == test.getTailleListe());
}

TEST(testDeplacePacket, estDeplacee)
{
  ColonneCarte	test;
  ColonneCarte	test2;
  Cartes	carte1(Cartes::ROI, Cartes::COEUR);

  test.ajoute(carte1);
  EXPECT_TRUE(0 == test2.getTailleListe());
  EXPECT_TRUE(1 == test.getTailleListe());
}

TEST(testSuppression, aSupprimeLaDerniereCarte)
{
  ColonneCarte	test;
  Cartes	carte1(Cartes::ROI, Cartes::COEUR);

  EXPECT_TRUE(0 == test.getTailleListe());
  test.ajoute(carte1);
  EXPECT_TRUE(1 == test.getTailleListe());
  test.supprimerDerniereCarte();
  EXPECT_TRUE(0 == test.getTailleListe());
}

TEST(positionColonne, estALaPremierePosition)
{
  ColonneCarte	test;
  Cartes	carte1(Cartes::ROI, Cartes::COEUR);

  test.ajoute(carte1);
  EXPECT_TRUE((test.getCarteAPosition(1)) == carte1);
}

int		main(int ac, char **av)
{
  ::testing::InitGoogleTest(&ac, av);
  return RUN_ALL_TESTS();
}

//! \file TesteurGraphe.cpp
//! \brief Google Test Graph.
//! \author Benjamin De Almeida - BEDEA1
//! \version 1.0
//! \date 05 novembre 2013
//!
//! Google Test Graphe

#include <iostream>
#include "gtest/gtest.h"
#include "Couverture.h"

TEST(testNombreSommets, nombresSommet)
{
  Graph<int>	test;

  EXPECT_FALSE(test.nombreSommets());
  test.ajouterSommet(1, 1);
  EXPECT_TRUE(test.nombreSommets());
  test.enleverSommet(1);
  EXPECT_FALSE(test.nombreSommets());
}

TEST(testEstVide, estVide)
{
  Graph<int>	test;

  EXPECT_TRUE(test.estVide());
  test.ajouterSommet(1, 1);
  EXPECT_FALSE(test.estVide());
  test.enleverSommet(1);
  EXPECT_TRUE(test.estVide());
}

TEST(TestSommetExiste, SommetExiste)
{
  Graph<int>	test;

  EXPECT_FALSE(test.sommetExiste(1));
  test.ajouterSommet(1, 1);
  EXPECT_TRUE(test.sommetExiste(1));
  test.enleverSommet(1);
  EXPECT_FALSE(test.sommetExiste(1));
}

TEST(testGetNumeroSommet, numeroEstRecu)
{
  Graph<int>	test;

  EXPECT_FALSE(test.getNumeroSommet(1));
  test.ajouterSommet(1, 1);
  EXPECT_TRUE(test.getNumeroSommet(1));
  test.enleverSommet(1);
  EXPECT_FALSE(test.getNumeroSommet(1));
}

TEST(testGetEtiquetteSommet, etiquetteEstRecu)
{
  Graph<int>	test;

  EXPECT_FALSE(test.getEtiquetteSommet(1));
  test.ajouterSommet(1, 1);
  EXPECT_TRUE(test.getEtiquetteSommet(1));
  test.enleverSommet(1);
  EXPECT_FALSE(test.getEtiquetteSommet(1));
}

TEST(testOrdreSortieSommet, bonOrdreDeSortie)
{
   Graph<int>	test;
}

TEST(testEntreeSommet, bonOrdreEntree)
{
   Graph<int>	test;
}

TEST(testArcExiste, arcExiste)
{
   Graph<int>	test;

   test.ajouterSommet(1, 1);
   test.ajouterSommet(2, 2);
   EXPECT_FALSE(test.arcExiste(1, 2));
   test.ajouterArc(1, 2, 3);
   EXPECT_TRUE(test.arcExiste(1, 2));
}

TEST(testCoutArc, arcAUnBonCout)
{
   Graph<int>	test;

   test.ajouterSommet(1, 1);
   test.ajouterSommet(2, 2);
   EXPECT_FALSE(test.getCoutArc(1, 2));
   test.ajouterArc(1, 2, 3);
   EXPECT_EQ(3, test.getCoutArc(1, 2));
}

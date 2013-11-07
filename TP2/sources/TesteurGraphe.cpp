//! \file TesteurGraphe.cpp
//! \brief Google Test Graph.
//! \author Benjamin De Almeida - BEDEA1
//! \version 1.0
//! \date 05 novembre 2013
//!
//! Google Test Graphe

#include <iostream>
#include "gtest/gtest.h"
#include "Graphe.h"

TEST(testNombreSommets, nombresSommet)
{
  Graphe<int>	test;

  EXPECT_FALSE(test.nombreSommets());
  test.ajouterSommet(1, 1);
  EXPECT_TRUE(test.nombreSommets());
  test.enleverSommet(1);
  EXPECT_FALSE(test.nombreSommets());
}

TEST(testEstVide, estVide)
{
  Graphe<int>	test;

  EXPECT_TRUE(test.estVide());
  test.ajouterSommet(1, 1);
  EXPECT_FALSE(test.estVide());
  test.enleverSommet(1);
  EXPECT_TRUE(test.estVide());
}

TEST(TestSommetExiste, SommetExiste)
{
  Graphe<int>	test;

  EXPECT_FALSE(test.sommetExiste(1));
  test.ajouterSommet(1, 1);
  EXPECT_TRUE(test.sommetExiste(1));
  test.enleverSommet(1);
  EXPECT_FALSE(test.sommetExiste(1));
}

TEST(testGetNumeroSommet, numeroEstRecu)
{
  Graphe<int>	test;

  EXPECT_FALSE(test.getNumeroSommet(1));
  test.ajouterSommet(1, 1);
  EXPECT_TRUE(test.getNumeroSommet(1));
  test.enleverSommet(1);
  EXPECT_FALSE(test.getNumeroSommet(1));
}

TEST(testGetEtiquetteSommet, etiquetteEstRecu)
{
  Graphe<int>	test;

  EXPECT_FALSE(test.getEtiquetteSommet(1));
  test.ajouterSommet(1, 1);
  EXPECT_TRUE(test.getEtiquetteSommet(1));
  test.enleverSommet(1);
  EXPECT_FALSE(test.getEtiquetteSommet(1));
}

TEST(testOrdreSortieSommet, bonOrdreDeSortie)
{
   Graphe<int>	test;

   test.ajouterSommet(1, 1);
   test.ajouterSommet(2, 2);
   EXPECT_EQ(0, test.ordreSortieSommeT(1));
   test.ajouterArc(1, 2, 3);
   EXPECT_EQ(1, test.ordreSortieSommeT(1));
}

TEST(testEntreeSommet, bonOrdreEntree)
{
   Graphe<int>	test;

   test.ajouterSommet(1, 1);
   test.ajouterSommet(2, 2);
   EXPECT_EQ(0, test.ordreEntreSommet(1));
   test.ajouterArc(2, 1, 3);
   EXPECT_EQ(1, test.ordreSortieSommeT(1));
}

TEST(testArcExiste, arcExiste)
{
   Graphe<int>	test;

   test.ajouterSommet(1, 1);
   test.ajouterSommet(2, 2);
   EXPECT_FALSE(test.arcExiste(1, 2));
   test.ajouterArc(1, 2, 3);
   EXPECT_TRUE(test.arcExiste(1, 2));
}

TEST(testCoutArc, arcAUnBonCout)
{
  Graphe<int>	test;
  
  test.ajouterSommet(1, 1);
  test.ajouterSommet(2, 2);
  EXPECT_FALSE(test.getCoutArc(1, 2));
  test.ajouterArc(1, 2, 3);
  EXPECT_EQ(3, test.getCoutArc(1, 2));
}

TEST(fortementConnexe, estFortementConnexe)
{
  Graphe<int>	test;
  
  test.ajouterSommet(1, 1);
  test.ajouterSommet(2, 2);
  test.ajouterArc(1, 2, 3);
  test.ajouterArc(2, 1, 3);
  EXPECT_TRUE(test.estFortementConnexe());
}


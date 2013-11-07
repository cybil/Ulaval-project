//! \file TesteurCouverture.cpp
//! \brief Google Test Graph.
//! \author Benjamin De Almeida - BEDEA1
//! \version 1.0
//! \date 05 novembre 2013
//!
//! Google Test Couverture

#include <iostream>
#include "gtest/gtest.h"
#include "Couverture.h"

TEST(testCreation, estCree)
{
  Couverture test("misc/couverture.txt");

  EXPECT_TRUE(test.villesAcessibles());
}

TEST(testCritique, contientVilleCritique)
{
  Couverture test("misc/couverture.txt");

  EXPECT_TRUE(!test.villesCritiques().empty());
}

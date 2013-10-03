//! \file solitaireTesteur.cpp
//! \brief Google Test Solitaire.
//! \author Benjamin De Almeida - BEDEA1
//! \version 1.0
//! \date 02 octobre 2013
//!
//! Google Test Solitaire

#include <iostream>
#include "gtest/gtest.h"
#include "Solitaire.h"

TEST(testGagne, aPasGagne)
{
  Solitaire	tmp;

  EXPECT_FALSE(tmp.verifieGagne());
}
/*
int		main(int ac, char **av)
{
  ::testing::InitGoogleTest(&ac, av);
  return RUN_ALL_TESTS();
}
*/

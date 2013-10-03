#include <iostream>
#include "gtest/gtest.h"
#include "Solitaire.h"

TEST(testGagne, aPasGagne)
{
  Solitaire	tmp;

  EXPECT_FALSE(tmp.verifieGagne());
}

int		main(int ac, char **av)
{
  ::testing::InitGoogleTest(&ac, av);
  return RUN_ALL_TESTS();
}

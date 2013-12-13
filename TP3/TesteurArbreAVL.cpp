#include "gtest/gtest.h"
#include "ArbreAVL.h"

class ArbreAVLTest : public ::testing::Test
{

  public:
    ArbreAVL<int, int> arb;

};

TEST_F(ArbreAVLTest, AppartientFalse)
{
	 EXPECT_FALSE(arb.appartient(1));
}

TEST_F(ArbreAVLTest, AppartientTrue)
{
	 arb.inserer(1, 1);
	 EXPECT_TRUE(arb.appartient(1));
}

TEST_F(ArbreAVLTest, AppartientFalseInsert)
{
	 arb.inserer(1, 1);
	 EXPECT_FALSE(arb.appartient(10));
	 EXPECT_TRUE(arb.appartient(1));
}



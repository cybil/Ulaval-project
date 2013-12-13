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


TEST_F(ArbreAVLTest, estVide)
{
  EXPECT_TRUE(arb.estVide());
  arb.inserer(1, 1);
  EXPECT_FALSE(arb.estVide());
}

TEST_F(ArbreAVLTest, taille)
{
  EXPECT_EQ(arb.taille(), 0);
  arb.inserer(1, 1);
  EXPECT_EQ(arb.taille(), 1);
}

TEST_F(ArbreAVLTest, hauteur)
{
  arb.inserer(1, 1);
  EXPECT_EQ(arb.hauteur(), 0);
  arb.inserer(1, 1);
  EXPECT_EQ(arb.hauteur(), 1);
}

TEST_F(ArbreAVLTest, enlever)
{
  EXPECT_EQ(arb.taille(), 0);
  arb.inserer(1, 1);
  EXPECT_EQ(arb.taille(), 1);
  // arb.enlever(1);
  // EXPECT_EQ(arb.taille(), 0);
}

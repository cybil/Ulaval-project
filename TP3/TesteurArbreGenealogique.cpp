#include "gtest/gtest.h"
#include "ArbreGenealogique.h"

class ArbreGeneTest : public ::testing::Test
{
public:
  ArbreGeneTest() {
    p = new Personne("toto", "dupont", 1234);
    arb = new ArbreGenealogique(*p);
  }

  ArbreGenealogique* arb;
  Personne* p;

};

TEST_F(ArbreGeneTest, constructor)
{
  EXPECT_FALSE(arb == 0);
}

TEST_F(ArbreGeneTest, AppartientFalse)
{
  Personne test("tata", "dupont", 1234);
  EXPECT_FALSE(arb->appartient(test));
}

TEST_F(ArbreGeneTest, AppartientTrue)
{
  EXPECT_TRUE(arb->appartient(*p));
}

TEST_F(ArbreGeneTest, enfants)
{
  Personne test("tata", "dupont", 1234);
  Personne test2("tatadwa", "martin", 4242);

  EXPECT_TRUE(arb->enfantsDe(*p).size() == 0);

  arb->ajouterEnfant(*p,  test);
  arb->ajouterEnfant(*p,  test2);

  EXPECT_TRUE(arb->enfantsDe(*p).size() == 2);
}

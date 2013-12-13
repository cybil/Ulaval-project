#include <fstream>
#include "gtest/gtest.h"
#include "Annuaire.h"

TEST(AnnuaireTest, constructeurs)
{
  std::ifstream	fichier("test.txt", std::ios::in);
  Annuaire* test = new Annuaire(fichier);

  Annuaire* test2 = new Annuaire();

  EXPECT_TRUE(test != 0);
  EXPECT_TRUE(test2 != 0);
  EXPECT_FALSE(test == test2);

  EXPECT_TRUE(test->getTailleArbreAVL() > 0);
  EXPECT_EQ(test2->getTailleArbreAVL(), 0);
}

TEST(AnnuaireTest, Inscrire)
{
  Annuaire* test2 = new Annuaire();
  Personne p("toto", "dupont", 1234);
  Adresse a(2, "rue toto", "Quebec");
  Personne p2("tata", "martin", 4242);
  Adresse a2(42, "rue tata", "Quebec");

  EXPECT_EQ(test2->getTailleArbreAVL(), 0);
  test2->inscrire(p, a);
  test2->inscrire(p2, a2);
  EXPECT_EQ(test2->getTailleArbreAVL(), 2);
}

TEST(AnnuaireTest, ajouterEnfant)
{
  Annuaire* test = new Annuaire();
  Adresse a(2, "toto", "Quebec");
  Personne p("toto", "dupont", 1234);
  Personne p2("tata", "martin", 4242);

  EXPECT_EQ(test->getTailleArbreGenealogique(), 0);
  test->inscrire(p, a);
  test->ajouterEnfant(p, p);
  EXPECT_EQ(test->getTailleArbreGenealogique(), 1);
}

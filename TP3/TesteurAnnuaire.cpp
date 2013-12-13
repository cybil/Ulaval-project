#include <fstream>
#include "gtest/gtest.h"
#include "Annuaire.h"

TEST_F(AnnuaireTest, constructeurs)
{
  std::ifstream	fichier("test.txt", std::ios::in);
  Annuaire* test = new Annuaire(fichier);

  Annuaire* test2 = new Annuaire();

  EXPECT_TRUE(test != 0);
  EXPECT_TRUE(test2 != 0);
  EXPECT_FALSE(test == test2);

  TEST_TRUE(test.getTailleArbreAVL() > 0);
  TEST_EQ(test2.getTailleArbreAVL(), 0);
}

TEST_F(AnnuaireTest, Inscrire)
{
  Annuaire test2();
  Personne p("toto", "dupont", 1234);
  Adresse a(2, "rue toto", "Quebec");
  Personne p2("tata", "martin", 4242);
  Adresse a2(42, "rue tata", "Quebec");

  TEST_EQ(test2.getTailleArbreAVL(), 0);
  test2.inscrire(p, a);
  test2.inscrire(p2, a2);
  TEST_EQ(test2.getTailleArbreAVL(), 2);
}

TEST_F(AnnuaireTest, ajouterEnfant)
{
  Annuaire test();
  Adresse a(2, "toto", "Quebec");
  Personne p("toto", "dupont", 1234);
  Personne p2("tata", "martin", 4242);

  TEST_EQ(test2.getTailleArbreGenealogique(), 0);
  test.inscrire(p, a);
  test.ajouterEnfant(p, p2);
  TEST_EQ(test2.getTailleArbreGenealogique(), 1);
}

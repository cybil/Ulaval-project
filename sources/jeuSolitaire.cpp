
#include <iostream>
#include "Solitaire.h"

struct t_opt
{
  std::string	opt;
  void		(*ptr)(Solitaire &);
};

void		prochaineTalon(Solitaire &p_jeu)
{
  std::cout << "prochaineTalon" << std::endl;
  p_jeu.avancerTalon();
}

void		deplacerTalonColonne(Solitaire &p_jeu)
{
  int		numColonneDestination;

  std::cout << "deplacerTalonColonne" << std::endl;
  std::cout << "Entrer le numero de la colonne de destination [0,6] : ";
  std::cin >> numColonneDestination;
  p_jeu.deplacerTalonAColonne(numColonneDestination);
}

void		deplacerTalonPile(Solitaire &p_jeu)
{
  int		numPileDestination;
  
  std::cout << "deplacerTalonPile" << std::endl;
  std::cout << "Entrer le numero de la pile de destination [0,3] : ";
  std::cin >> numPileDestination;
  p_jeu.deplacerTalonAPile(numPileDestination);
}

void		deplacerColonneColonne(Solitaire &p_jeu)
{
  std::cout << "deplacerColonneColonne" << std::endl;
  int		numColonneOrigine;
  int		numColonneDestination;
  int		nbCartes;

  std::cout << "Entrer le numero de la colonne d'origine [0,6] : ";
  std::cin >> numColonneOrigine;
  std::cout << "Entrer le numero de la colonne de destination [0,6] : ";
  std::cin >> numColonneDestination;
  std::cout << "Entrer le nombre de carte a deplacer [1,12] : ";
  std::cin >> nbCartes;
  p_jeu.deplacerColonneAColonne(numColonneOrigine, numColonneDestination, nbCartes);
}

void		deplacerColonnePile(Solitaire &p_jeu)
{
  int		numColonneOrigine;
  int		numPileDestination;

  std::cout << "deplacerColonnePile" << std::endl;
  std::cout << "Entrer le numero de la colonne d'origine [0,6] : ";
  std::cin >> numColonneOrigine;
  std::cout << "Entrer le numero de la pile de destination [0,3] : ";
  std::cin >> numPileDestination;
  p_jeu.deplacerColonneAPile(numColonneOrigine, numPileDestination);
}

static t_opt	tab[] =
  {
    {"1", &prochaineTalon},
    {"2", &deplacerTalonColonne},
    {"3", &deplacerTalonPile},
    {"4", &deplacerColonneColonne},
    {"5", &deplacerColonnePile}
  };

void		affMenu()
{
  std::cout << "******************************************" << std::endl;
  std::cout << "      Menu" << std::endl;
  std::cout << "******************************************" << std::endl;
  std::cout << "1. Prochaine carte du talon." << std::endl;
  std::cout << "2. Deplacer une carte du talon vers une colonne." << std::endl;
  std::cout << "3. Deplacer une carte du talon vers une pile." << std::endl;
  std::cout << "4. Deplacer une(des) carte(s) d'une colonne vers une autre." << std::endl;
  std::cout << "5. Deplacer une carte d'une colonne vers une pile." << std::endl;
  std::cout << "6. Quitter." << std::endl;
  std::cout << "******************************************************" << std::endl;
}

int		main(int ac, char **av)
{
  Solitaire	jeu;
  bool		run = true;

  while (run)
    {
      std::string	buf;
      
      std::cout << jeu.reqEtatJeu();
      affMenu();
      std::cin >> buf;
      if (buf == "6")
	run = false;
      try {
	for (int i = 0; i < 5; i++)
	  if (buf == tab[i].opt)
	    (tab[i].ptr)(jeu);
      }
      catch (std::exception e) {
	std::cerr << "!!! Coup invalide !!!" << std::endl;
      }
      if (jeu.verifieGagne() == true)
	{
	  run = false;
	  std::cout << "Vous avez gagne !" << std::endl;
	}
    }
  return 0;
}

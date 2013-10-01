
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
}

void		deplacerTalonColonne(Solitaire &p_jeu)
{
  std::cout << "deplacerTalonColonne" << std::endl;

}

void		deplacerTalonPile(Solitaire &p_jeu)
{
  std::cout << "deplacerTalonPile" << std::endl;

}

void		deplacerColonneColonne(Solitaire &p_jeu)
{
  std::cout << "deplacerColonneColonne" << std::endl;

}

void		deplacerColonnePile(Solitaire &p_jeu)
{
  std::cout << "deplacerColonnePile" << std::endl;

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
  std::cout << "******************************************************" << std::endl;
  std::cout << "\tMenu" << std::endl;
  std::cout << "******************************************************" << std::endl;
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
  std::cout << "Coucou, je suis un jeu de solitaire. Tu es seul ? viens jouer avec moi :p" << std::endl;
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
      for (int i = 0; i < 5; i++)
	if (buf == tab[i].opt)
	  (tab[i].ptr)(jeu);
    }
  return 0;
}

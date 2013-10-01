
#include <iostream>
#include "Solitaire.h"

void		affMenu()
{
  std::cout << "******************************************************" << std::endl;
}

int		main(int ac, char **av)
{
  std::cout << "Coucou, je suis un jeu de solitaire. Tu es seul ? viens jouer avec moi :p" << std::endl;
  Solitaire	jeu;

  std::cout << jeu.reqEtatJeu();
  return 0;
}

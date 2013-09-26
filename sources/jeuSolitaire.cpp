
#include <iostream>
#include "Cartes.h"

int		main(int ac, char **av)
{
  std::cout << "Coucou, je suis un jeu de solitaire. Tu es seul ? viens jouer avec moi :p" << std::endl;

  Cartes	c1(Cartes::AS, Cartes::PIQUE);
  std::cout << c1;
  return 0;
}

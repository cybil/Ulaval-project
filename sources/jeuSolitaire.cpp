
#include <iostream>
#include "Solitaire.h"

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

  while (42)
    {
      std::string	buf;
      
      std::cout << jeu.reqEtatJeu();
      affMenu();
      
    }
  return 0;
}

#include <iostream>
#include <fstream>
#include "Adresse.h"
#include "Annuaire.h"

int		main()
{
  std::ifstream	fichier("test.txt", std::ios::in);
  
  if (!fichier)
    return -1;
  // Adresse		adr(62, "rue des Bourrelier", "Moissy_Cramayel");
  Annuaire	anu(fichier);


  std::cout << anu;
  fichier.close();
  return 0;
}

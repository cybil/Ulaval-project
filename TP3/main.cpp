#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include "Adresse.h"
#include "Annuaire.h"
#include "ArbreAVL.h"
#include "ArbreGenealogique.h"
#include "Personne.h"

int		main() {
//  std::ifstream	fichier("test.txt", std::ios::in);

//  if (!fichier)
//    return -1;
//  // Adresse		adr(62, "rue des Bourrelier", "Moissy_Cramayel");
//  Annuaire	anu(fichier);
//
//
//  std::cout << anu;
//  fichier.close();
//

    ArbreAVL<int, int>	abr;

  std::cout << abr.appartient(120) << std::endl;
  abr.inserer(1, 1);

  std::cout << abr.appartient(1) << std::endl;
  std::cout << abr.appartient(120) << std::endl;

  abr.inserer(3, 3);
  abr.inserer(4, 4);
  abr.inserer(5, 5);
  abr.inserer(3, 3);
    abr.inserer(6, 4);
    abr.inserer(7, 5);
    abr.inserer(8, 3);
      abr.inserer(9, 4);
      abr.inserer(10, 5);
      abr.inserer(11, 3);
        abr.inserer(12, 4);
        abr.inserer(13, 5);
  std::cout << abr.appartient(2) << std::endl;
  std::cout << abr.appartient(3) << std::endl;
  std::cout << abr.appartient(4) << std::endl;
  std::cout << abr.appartient(5) << std::endl;
  std::cout << abr.appartient(120) << std::endl;
  std::cout << "insertion" << std::endl;


  std::cout << "================" << std::endl;
  std::vector<std::pair< int, int> > vec;
  vec = abr.lister();
  std::cout << "========LISTER========" << vec.size() << std::endl;
  for (int i = 0; i < vec.size(); i++)
  {
	  std::cout << "first/second" << vec[i].first << "/" << vec[i].second << std::endl;
  }

  std::cout << "========SHOW========" << std::endl;
  abr.show();
  return 0;
}

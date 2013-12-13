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

    abr.inserer(50, 1);
    abr.inserer(25, 2);
    abr.inserer(10, 3);
    abr.show();
    return 0;

  std::cout << abr.appartient(120) << std::endl;


  std::cout << abr.appartient(1) << std::endl;
  std::cout << abr.appartient(120) << std::endl;
  for (int i = 0; i < 3; i++)
	  abr.inserer(i, i);
  std::cout << abr.appartient(2) << std::endl;
  std::cout << abr.appartient(3) << std::endl;
  std::cout << abr.appartient(4) << std::endl;
  std::cout << abr.appartient(5) << std::endl;
  std::cout << abr.appartient(120) << std::endl;
  std::cout << "insertion" << std::endl;


  std::cout << "================" << std::endl;

  std::cout << "========SHOW========" << std::endl;
  abr.show();

  std::cout << "========LISTER========" << std::endl;
  std::vector<std::pair< int, int> > vec;
  vec = abr.lister();

  for (int i = 0; i < vec.size(); i++)
  {
	  std::cout << vec[i].first << " ";
  }
  std::cout << std::endl;
  std::cout << "========LISTER PREORDRE========" << std::endl;
  vec = abr.listerPreOrdre();
  for (int i = 0; i < vec.size(); i++)
  {
	  std::cout << vec[i].first << " ";
  }
  std::cout << std::endl;

  std::cout << "========Test EGALITE==========" << std::endl;

//  ArbreAVL<int, int>	abr2(abr);
//  ArbreAVL<int, int>	abr3;
//
//  std::cout << (1 == 1) << std::endl;
////  std::cout << abr == abr3 << std::endl;
  return 0;
}

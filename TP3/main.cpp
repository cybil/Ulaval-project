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
 std::cout << "Taille: " << abr.taille() << std::endl;
  abr.inserer(1, 1);
  std::cout << "================" << std::endl;
//  std::cout << abr.appartient(1) << std::endl;
//  std::cout << abr.appartient(120) << std::endl;
  abr.lister();
  abr.inserer(3, 3);
  abr.inserer(4, 4);
  abr.inserer(13, 13);
  abr.inserer(5, 5);
  abr.inserer(6, 6);
  abr.inserer(7, 7);
  abr.inserer(10, 10);
  abr.inserer(11, 11);
  abr.inserer(8, 8);
  abr.inserer(9, 9);
  abr.inserer(12, 12);
  abr.inserer(14, 14);
 std::cout << abr.appartient(2) << std::endl;
 std::cout << abr.appartient(3) << std::endl;
 std::cout << abr.appartient(4) << std::endl;
 std::cout << abr.appartient(5) << std::endl;
 std::cout << abr.appartient(6) << std::endl;
 std::cout << abr.appartient(7) << std::endl;
 std::cout << abr.appartient(8) << std::endl;
 std::cout << abr.appartient(9) << std::endl;
 std::cout << abr.appartient(10) << std::endl;
 std::cout << abr.appartient(11) << std::endl;
 std::cout << abr.appartient(12) << std::endl;
 std::cout << abr.appartient(13) << std::endl;
 std::cout << abr.appartient(14) << std::endl;
 std::cout << abr.appartient(15) << std::endl;

 std::cout << "Taille: " << abr.taille() << std::endl;
 ArbreAVL<int, int>	abr2 = abr;
 // if (abr == abr2)
 //   std::cout << "---> EGAUX 2 ?" << std::endl;
 //   abr.inserer(3, 3);
 //   abr.inserer(6, 4);
 //   abr.inserer(7, 5);
 //   abr.inserer(8, 3);
 //   abr.inserer(9, 4);
 //   abr.inserer(10, 5);
 //   abr.inserer(11, 3);
 //   abr.inserer(12, 4);
 //   abr.inserer(13, 5);
 //   std::cout << abr.appartient(2) << std::endl;
 //  std::cout << abr.appartient(3) << std::endl;
 //  std::cout << abr.appartient(4) << std::endl;
 //  std::cout << abr.appartient(5) << std::endl;
 //  std::cout << abr.appartient(120) << std::endl;
 //  std::cout << "insertion" << std::endl;


 //  std::cout << "================" << std::endl;
 //  std::vector<std::pair< int, int> > vec;
 //  vec = abr.lister();
 //  std::cout << "========LISTER========" << vec.size() << std::endl;
 //  // for (int i = 0; i < vec.size(); i++)
 //  // {
 //  //   std::cout << "first/second" << vec[i].first << "/" << vec[i].second << std::endl;
 //  // }

 //  std::cout << "========SHOW========" << std::endl;
 //  abr.show();
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

  return 0;
}

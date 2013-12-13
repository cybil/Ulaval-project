#include <iostream>
#include <fstream>

#include <vector>
#include <utility>
#include "Adresse.h"
#include "Annuaire.h"
#include "ArbreAVL.h"

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

  // if (abr == abr2)
  //   std::cout << "---> EGAUX" << std::endl;
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
 if (abr == abr2)
   std::cout << "---> EGAUX 2 ?" << std::endl;
  return 0;
}

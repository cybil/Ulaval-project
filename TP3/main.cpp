#include <iostream>
#include <fstream>
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
    ArbreAVL<int, char*>	abr;
    //std::cout << abr.appartient(120) << std::endl;
    //abr.inserer(3, 3);
    //std::cout << abr.appartient(1) << std::endl;
    abr.inserer(5, "a");
    abr.show();
    std::cout << "---" << std::endl;
    abr.inserer(2, "b");
    abr.inserer(4, "c");
    abr.inserer(3, "d");
    abr.show();
//  abr.inserer(4, 4);
//  abr.inserer(5, 5);
//  std::cout << abr.appartient(2) << std::endl;
//  std::cout << abr.appartient(3) << std::endl;
//  std::cout << abr.appartient(4) << std::endl;
//  std::cout << abr.appartient(5) << std::endl;
  return 0;
}

/**
 * \file TestHashTable.cpp
 * \brief un main() pour tester la classe HashTable.
 * \author Cybil Bourely - CMBOU5
 * \version 0.1
 * \date 22 novembre 2013
 */

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include "HashTable.h"
#include "HashTableD.h"

using namespace std;
using namespace HashTable_Lab9;

/** 
 * \class Hache
 *
 * \brief Classe pour definir un foncteur pour la fonction de hachage qui sera utilisee par la classe HashTable
 *
 * Un foncteur n'est rien d'autre qu'un objet dont la classe definit l'operateur fonctionnel '()'. 
 * Les foncteurs, très utilses dans la STL, ont la particularite de pouvoir être utilises exactement 
 * comme des fonctions puisqu'il est possible de leur appliquer leur operateur fonctionnel selon une 
 * ecriture similaire à un appel de fonction. Cependant, ils sont un peu plus puissants que de simples fonctions, 
 * car ils permettent de transporter, en plus du code de l'operateur fonctionnel, des paramètres additionnels dans 
 * leurs donnees membres. Les foncteurs constituent donc une fonctionnalite extrêmement puissante qui peut être 
 * très pratique en de nombreux endroits.
 */
class Hache1
{
public:
  unsigned long			operator()(const int clef)
  {
    return  clef;
  }
};

class Hache2
{
public:
  unsigned long			operator()(const int clef)
  {
    return  (919 - clef % 919);
  }
};

typedef HashTable<int, double, Hache1> Table_Hache1;		// utilise le sondage quadratique avec le foncteur Hache1
typedef HashTableD<int, double, Hache1, Hache2> Table_Hache2;	// utilise le double hachage avec les foncteurs Hache1 et Hache2

/**
 * \brief Cherche si un vector contient un element donne
 * \param[in] vec est le vector conteneur
 * \param[in] k est l'element a chercher
 * \return True si l'element est present, false sinon
 */
bool		contains(std::vector<int> &p_vec, int p_k)
{
  std::vector<int>::iterator	it = p_vec.begin();

  while (it != p_vec.end())
    {
      if (*it == p_k)
	return true;
      ++it;
    }
  return false;
}

/**
 * \brief Fonction de test du sondage quadratique
 * \return le nombre de collision
 */
int				testQuadratique(int NB_ENTRY)
{
  Table_Hache1			employes(1013);
  int				nbCollision = 0;
  std::vector<int>		keys; // conteneur pour stocker les clefs generees
  int				k = 0; // iterateur pour generer les clefs uniques

  srand(time(NULL));
  keys.push_back(0);
  for (int i = 0; i < NB_ENTRY; i++)
    {
      while (contains(keys, k) == true)
	k = (rand() % (19999 - 10000) + 10000) + 1;
      keys.push_back(k);
      employes.insert(k, i);
    }

  // Recherche des elements inseres (verification de la methode contains)
  int		find = 0;
  for (int i = 0; i < NB_ENTRY; i++)
    {
      std::cout << "Clef recherchee : " << keys[i] << std::endl;
      if (employes.contains(keys[i]) == false)
	std::cout << "ERREUR: Clef non trouvee." << std::endl;
      else
	{
	  std::cout << "Clef trouvee." << std::endl;
	  ++find;
	}
    }
  if (find == NB_ENTRY - 1)
    std::cout << "Toutes les clefs inseree ont ete trouvee." << std::endl;
  return nbCollision;
}


/**
 * \brief Fonction de test du double hachage
 * \return le nombre de collision
 */
int				testDoubleHachage(int NB_ENTRY)
{
  Table_Hache2			hashTable(1013);
  int				nbCollision = 0;
  std::vector<int>		keys; // conteneur pour stocker les clefs generees
  int				k = 0; // iterateur pour generer les clefs uniques

  srand(time(NULL));
  keys.push_back(0);
  for (int i = 0; i < NB_ENTRY; i++)
    {
      while (contains(keys, k) == true)
	k = (rand() % (19999 - 10000) + 10000) + 1;
      keys.push_back(k);
      hashTable.insert(k, i);
    }

  // Recherche des elements inseres (verification de la methode contains)
  int		find = 0;
  for (int i = 0; i < NB_ENTRY; i++)
    {
      std::cout << "Clef recherchee : " << keys[i] << std::endl;
      if (hashTable.contains(keys[i]) == false)
	std::cout << "ERREUR: Clef non trouvee." << std::endl;
      else
	{
	  std::cout << "Clef trouvee." << std::endl;
	  ++find;
	}
    }
  if (find == NB_ENTRY - 1)
    std::cout << "Toutes les clefs inseree ont ete trouvee." << std::endl;
  return nbCollision;
}

/**
 * \fn int main (void)
 * \brief fonction principale.
 *
 * Un main() testeur de la classe Graphe
 * \return 0 - Arrêt normal du programme.
 */
int				main()
{ 
  std::cout << "<<<== SONDAGE QUADRATIQUE ==>>>" << std::endl;
  testQuadratique(500); // 500 = nombre d'entree a inserer
  std::cout << "<<<== FIN SONDAGE QUADRATIQUE ==>>>" << std::endl;

  std::cout << "<<<== DOUBLE HACHAGE ==>>>" << std::endl;
  testDoubleHachage(500); // 500 = nombre d'entree a inserer
  std::cout << "<<<== FIN DOUBLE HACHAGE ==>>>" << std::endl;

  return 0;
}

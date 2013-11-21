/**
 * \file TestHashTable.cpp
 * \brief un main() pour tester la classe HashTable.
 * \author Abder
 * \version 0.1
 * \date septembre 2011
 */

#include <iostream>
#include <string>
#include "HashTable.h"

using namespace std;
using namespace HashTable_Lab9;

/** 
	* \class Hache
	*
	* \brief Classe pour définir un foncteur pour la fonction de hachage qui sera utilisée par la classe HashTable
	*
	* Un foncteur n'est rien d'autre qu'un objet dont la classe définit l'opérateur fonctionnel '()'. 
	* Les foncteurs, très utilsés dans la STL, ont la particularité de pouvoir être utilisés exactement 
	* comme des fonctions puisqu'il est possible de leur appliquer leur opérateur fonctionnel selon une 
	* écriture similaire à un appel de fonction. Cependant, ils sont un peu plus puissants que de simples fonctions, 
	* car ils permettent de transporter, en plus du code de l'opérateur fonctionnel, des paramètres additionnels dans 
	* leurs données membres. Les foncteurs constituent donc une fonctionnalité extrêmement puissante qui peut être 
	* très pratique en de nombreux endroits.
	*/
class Hache
{
public:
  unsigned long			operator()(const std::string &clef)
  {
    const unsigned long		GRAND_PREMIER = 1000003;
    unsigned long		total = 0;
    unsigned long		premiers[] = {11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79};
    
    for(unsigned int i = 0; i < clef.length(); i++)
      total += premiers[i] * clef[i];
    return total * GRAND_PREMIER;
  }
};

//Un typedef pour raccourcir les écritures
typedef HashTable<string, double, Hache> Table_Hache;

/**
 * \fn int main (void)
 * \brief fonction principale.
 *
 * Un main() testeur de la classe Graphe
 * \return 0 - Arrêt normal du programme.
 */
int				main()
{ 

  try {
    Table_Hache			employes;

    // Table_hache::Iterateur itr;
    cout << "début" << endl;
    employes.insert("Napoléon Bonaparte", 33.5);
    cout << "Napoléon inséré" << endl;
    employes.insert("Gengis Khan", 40); 
    cout << "Gengis Khan inséré" << endl;
    employes.insert("Alexandre le Grand", 30.1);
    cout << "Alexandre le Grand inséré" << endl;
    //l'instruction suivant doit générer une exception
    // employes.insert("Napoléon Bonaparte", 33.5);

    employes.display();
    cout << "On a ";
  
    if (!employes.contains("Napoléon Bonaparte"))
      cout << "pas trouvé Napoléon Bonaparte" << endl;
    else
      cout << "trouvé " << endl;

    cout << "On a " ;
    if (!employes.contains("Tartarin de Tarascon"))
      cout << "pas trouvé Tartarin de Tarascon" << endl;
    else
      cout << "trouvé " << endl;

    cout << "Enlever Gengis Khan" << endl;
    employes.remove("Gengis Khan");
 
    if (!employes.contains ("Gengis Khan"))
      cout << "Pas de Gengis Khan" << endl;
    else
      cout << "Gengis Khan encore là!" << endl;
    if (!employes.contains("Alexandre le Grand"))
      cout << "Pas d'Alexandre le Grand!" << endl;
    else
      cout << "Alexandre le Grand trouvé" << endl;

    employes.display();

  } catch(exception &e)
    {
      cout << "Erreur: " << e.what() << endl;
      return 0;
    }

  return 0;
}

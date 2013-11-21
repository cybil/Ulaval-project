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
	* \brief Classe pour d�finir un foncteur pour la fonction de hachage qui sera utilis�e par la classe HashTable
	*
	* Un foncteur n'est rien d'autre qu'un objet dont la classe d�finit l'op�rateur fonctionnel '()'. 
	* Les foncteurs, tr�s utils�s dans la STL, ont la particularit� de pouvoir �tre utilis�s exactement 
	* comme des fonctions puisqu'il est possible de leur appliquer leur op�rateur fonctionnel selon une 
	* �criture similaire � un appel de fonction. Cependant, ils sont un peu plus puissants que de simples fonctions, 
	* car ils permettent de transporter, en plus du code de l'op�rateur fonctionnel, des param�tres additionnels dans 
	* leurs donn�es membres. Les foncteurs constituent donc une fonctionnalit� extr�mement puissante qui peut �tre 
	* tr�s pratique en de nombreux endroits.
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

//Un typedef pour raccourcir les �critures
typedef HashTable<string, double, Hache> Table_Hache;

/**
 * \fn int main (void)
 * \brief fonction principale.
 *
 * Un main() testeur de la classe Graphe
 * \return 0 - Arr�t normal du programme.
 */
int				main()
{ 

  try {
    Table_Hache			employes;

    // Table_hache::Iterateur itr;
    cout << "d�but" << endl;
    employes.insert("Napol�on Bonaparte", 33.5);
    cout << "Napol�on ins�r�" << endl;
    employes.insert("Gengis Khan", 40); 
    cout << "Gengis Khan ins�r�" << endl;
    employes.insert("Alexandre le Grand", 30.1);
    cout << "Alexandre le Grand ins�r�" << endl;
    //l'instruction suivant doit g�n�rer une exception
    // employes.insert("Napol�on Bonaparte", 33.5);

    employes.display();
    cout << "On a ";
  
    if (!employes.contains("Napol�on Bonaparte"))
      cout << "pas trouv� Napol�on Bonaparte" << endl;
    else
      cout << "trouv� " << endl;

    cout << "On a " ;
    if (!employes.contains("Tartarin de Tarascon"))
      cout << "pas trouv� Tartarin de Tarascon" << endl;
    else
      cout << "trouv� " << endl;

    cout << "Enlever Gengis Khan" << endl;
    employes.remove("Gengis Khan");
 
    if (!employes.contains ("Gengis Khan"))
      cout << "Pas de Gengis Khan" << endl;
    else
      cout << "Gengis Khan encore l�!" << endl;
    if (!employes.contains("Alexandre le Grand"))
      cout << "Pas d'Alexandre le Grand!" << endl;
    else
      cout << "Alexandre le Grand trouv�" << endl;

    employes.display();

  } catch(exception &e)
    {
      cout << "Erreur: " << e.what() << endl;
      return 0;
    }

  return 0;
}

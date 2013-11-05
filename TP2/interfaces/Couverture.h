//! \file Couverture.h
//! \brief interface de la classe couverture mod�lisant la couverture des villes d�servies par la compagnie air-GLOIFT
//! \author theud1
//! \version 0.1
//! \date 2013-10-03
#ifndef COUVERTURE_H_
#define COUVERTURE_H_
#include <fstream>		// Pour les fichiers
#include <vector>
#include "Graphe.h"
#include "Ville.h"

namespace tp2
{

  class Couverture
  {
  public:
    // �������������������������������������������������������
    //	Constructeurs et destructeur
    // _______________________________________________________
    Couverture(std::ifstream & p_fichierEntree);

    // �������������������������������������������������������
    //	Affichage
    // _______________________________________________________
    void			afficherVilles(std::vector<Ville>& p_vVilles);
    void			afficherVilles();

    // �������������������������������������������������������
    //	Connexit�, point d'articulation
    // _______________________________________________________
    bool			villesAccessibles();
    std::vector<Ville>		villesCritiques();

    // �������������������������������������������������������
    //	Chemin le plus court
    // _______________________________________________________
    std::vector<Ville>	determinerMinParcours(const Ville & p_origine,
					      const Ville & p_destination, int & p_duree);
    std::vector<Ville>	bellManFord(const Ville & p_origine,
				    const Ville & p_destination, int & p_duree);

  private:
    Graphe<Ville>		m_graphe; //< Le graphe de la couverture
  };

}

#endif /* COUVERTURE_H_ */

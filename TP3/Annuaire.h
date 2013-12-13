
#ifndef		ANNUAIRE_H__
#define		ANNUAIRE_H__

#include <list>
#include <ostream>
#include "Adresse.h"
#include "ArbreAVL.h"
#include "ArbreGenealogique.h"

class Annuaire
{
public:

  Annuaire();

  //! \brief Constructeur a partir d'un fichier en entree
  //! \param[in] p_fichierEntree un flux d'entree vers un fichier contenant la liste des personnes a charger
  //! \pre Il y a assez de memoire pour charger toutes les personnes de la liste
  //! \pre Le fichier p_fichierEntree est ouvert correctement
  //! \post Le fichier p_fichierEntree n'est pas ferme par la fonction
  //! \post Si les preconditions sont respectees, les donnees de l'annuaire contenues dans le fichier en entree sont orgnisees dans une structure de donnees
  //! \exception bad_alloc si pas assez de memoire pour contenir toute la liste du fichier
  //! \exception logic_error si p_fichierEntree n'est pas ouvert correctement
  Annuaire(std::ifstream &p_fichierEntree);

  ~Annuaire();

  /* ArbreAVL<Personne, Adresse>	getBottin() const; */
  /* std::list<ArbreGenealogique>	getListArbreGen() const; */

  void				inscrire(const Personne &p_personne, const Adresse &p_adresse);
  void				ajouterEnfant(const Personne &p_parent, const Personne &p_enfant);

  friend std::ostream		&operator<<(std::ostream &p_os, const Annuaire &p_annuaire);

private:

  ArbreAVL<Personne, Adresse>	m_bottin;
  std::list<ArbreGenealogique>	m_listArbreGene;

};

#endif		// !ANNUAIRE_H__

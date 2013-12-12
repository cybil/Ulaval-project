
#include "ArbreGenealogique.h"

//******************
// Constructeur / Destructeur Noeud
//*******************

ArbreGenealogique::Noeud::Noeud(const Personne& p_personne)
  : m_gauche(NULL), m_droite(NULL), m_hauteur(0) 
{
  m_personne = const_cast<Personne*>(&p_personne);
}

ArbreGenealogique::Noeud::~Noeud()
{
}

//******************
// Constructeur / Destructeur ArbreGenealogique
//*******************

//! \brief Constructeur par parametre 
//! \param[in] p_personne la personne de la racine de l'arbre
ArbreGenealogique::ArbreGenealogique(const Personne &p_personne)
{
  m_nom = p_personne.reqNom();
  m_racine = new ArbreGenealogique::Noeud(p_personne);
}

//! \brief Destructeur par defaut
ArbreGenealogique::~ArbreGenealogique()
{

}

//! \brief Ajouter un enfant a un parent dans un arbre
//! \brief Si le p_parent est NULL creer un parent avec p_enfant
//! \param[in] p_parent la reference du parent
//! \pre Si l'arbre est vide p_parent == p_enfant
//! \param[in] p_enfant la reference de l'enfant
void				ArbreGenealogique::ajouterEnfant(const Personne &p_parent,
								 const Personne &p_enfant)
{
  
}

//! \brief Trouve tous les enfants du parent
//! \param[in] p_parent le parent des enfants
//! \return un vector contenant tous les enfants
std::vector<Personne *>		ArbreGenealogique::enfantsDe(const Personne &p_parent) const
{

}

//! \brief Permet de savoir si une personne est dans l'arbre
//! \param[in] p_personne la personne recherchee
//! \pre l'arbre ne doit pas etre vide
//! \return true si la personne est dans l'arbre sinon false
//! \exception logic_error si l'arbre est vide
bool				ArbreGenealogique::appartient(const Personne &p_personne) const
{

}

//! \brief Surcharge de l'operateur <<
//! \param[in] p_arbreG l'arbre genealogique a sortir
//! \param[out] p_os le flux de sortie contenant l'arbre formatee
//! \return un flux de sortie pour les appels en cascade
std::ostream		&operator<<(std::ostream &p_os, const ArbreGenealogique &p_arbreG)
{
  p_os << "ArbreGenealogique : ";
  return p_os;
}


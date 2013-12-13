
#include <string>
#include <stdexcept>
#include "ArbreGenealogique.h"

//******************
// Constructeur / Destructeur Noeud
//*******************

ArbreGenealogique::Noeud::Noeud(const Personne& p_personne)
  : m_gauche(NULL), m_droite(NULL), m_hauteur(0) 
{
  m_personne = new Personne(p_personne);
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
  Noeud *ptr_noeud = NULL;

  trouvePersonne(p_parent, ptr_noeud);
  if (ptr_noeud == NULL)
    return ;
  
  if (ptr_noeud->m_gauche == NULL)
    {
      ptr_noeud->m_gauche = new Noeud(p_enfant);
      std::cout << "Noeud fils: " << *(ptr_noeud->m_gauche->m_personne) << std::endl;
    }
  else
    _ajouterEnfant(ptr_noeud->m_gauche, p_enfant);
}

void				ArbreGenealogique::_ajouterEnfant(Noeud *p_noeud_fils,
    								  const Personne &p_enfant)
{
    std::cout << "Noeud fils: " << *(p_noeud_fils->m_personne) << std::endl;
  if (p_noeud_fils->m_droite == NULL) 
  {
    p_noeud_fils->m_droite = new Noeud(p_enfant);
    std::cout << "Noeud fils: " << *(p_noeud_fils->m_droite->m_personne) << std::endl;
    return;
  }
  _ajouterEnfant(p_noeud_fils->m_droite, p_enfant);
}

void				ArbreGenealogique::trouvePersonne(const Personne &p_personne,
						 Noeud *&p_trouve) const
{
  _trouvePersonne(m_racine, p_personne, p_trouve);    
}

void				ArbreGenealogique::_trouvePersonne(Noeud *p_racine, 
								   const Personne &p_personne,
								   Noeud *&p_trouve) const
{
  std::cout << "--->  " << *(p_racine->m_personne) << std::endl;
  if (p_personne == *(p_racine->m_personne)) 
    {
      p_trouve = p_racine;
      std::cout << "Trouve: " << *(p_racine->m_personne) << std::endl;
      return;
    }
  if (p_trouve || (p_racine->m_gauche == NULL && p_racine->m_droite == NULL))
    return;
  if (m_racine->m_gauche) 
    _trouvePersonne(p_racine->m_gauche, p_personne, p_trouve);
  if (m_racine->m_droite)
    _trouvePersonne(p_racine->m_droite, p_personne, p_trouve);
}

//! \brief Trouve tous les enfants du parent
//! \param[in] p_parent le parent des enfants
//! \return un vector contenant tous les enfants
std::vector<Personne *>		ArbreGenealogique::enfantsDe(const Personne &p_parent) const
{
  Noeud *tmp_noeud = NULL;
  std::vector<Personne *> tab_personne;
  trouvePersonne(p_parent, tmp_noeud);
  if (tmp_noeud == NULL)
    return tab_personne;
  _creerVecteurEnfant(tmp_noeud->m_gauche, tab_personne);  
}

void				ArbreGenealogique::_creerVecteurEnfant(Noeud *p_enfant,
						       std::vector<Personne *> p_tab_personne) const
{
  if (p_enfant == NULL)
    return;
  p_tab_personne.push_back(p_enfant->m_personne);
  _creerVecteurEnfant(p_enfant->m_droite, p_tab_personne);
}

//! \brief Permet de savoir si une personne est dans l'arbre
//! \param[in] p_personne la personne recherchee
//! \pre l'arbre ne doit pas etre vide
//! \return true si la personne est dans l'arbre sinon false
//! \exception logic_error si l'arbre est vide
bool				ArbreGenealogique::appartient(const Personne &p_personne) const
{
  if (m_racine == NULL)
    throw std::logic_error("Erreur: Arbre vide dans methode appartient");
  Noeud *tmp_personne;

  trouvePersonne(p_personne, tmp_personne); 
  if (tmp_personne == NULL)
    return false;
  return true;
}

//! \brief Surcharge de l'operateur <<
//! \param[in] p_arbreG l'arbre genealogique a sortir
//! \param[out] p_os le flux de sortie contenant l'arbre formatee
//! \return un flux de sortie pour les appels en cascade
std::ostream		&operator<<(std::ostream &p_os, const ArbreGenealogique &p_arbreG)
{
  std::cout << "operateur << arbre" << std::endl;
  p_os << p_arbreG.display() << std::endl;
  return p_os;
}

std::string		ArbreGenealogique::display() const
{
 std::string 		str = "";
 
 _display(m_racine, str);

 return str;
}

std::string		ArbreGenealogique::_display(Noeud *p_noeud, std::string &p_str) const
{
  std::cout << "la 1" << std::endl;

  if (p_noeud == NULL)
    {
      std::cout << "c'est fini" << std::endl;
      return p_str;
}
  std::cout << "la 2" << std::endl;
  
  p_str += p_noeud->m_personne->reqNom();
  std::cout << "--> " << p_str << std::endl;
  
  if (p_noeud->m_droite)
    {
      p_str += ", ";
      _display(p_noeud->m_droite, p_str);
    }
  if (p_noeud->m_gauche)
    {
      p_str += "\n" + p_noeud->m_personne->reqNom() + " :\n";
      _display(p_noeud->m_gauche, p_str);
    }

  return p_str;
}

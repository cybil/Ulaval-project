
#ifndef		ARBREGENEALOGIQUE_H__
#define		ARBREGENEALOGIQUE_H__

#include <vector>
#include <string>
#include <ostream>
#include "Personne.h"

class ArbreGenealogique
{
public :

  class Noeud
  {
  public:
    //! \brief Constructeur de la classe Noeud
    //! \param[in] p_personne la personne contenue dans le noeud
    //! \post un noeud typique est initialise
    Noeud(const Personne &p_personne);

    ~Noeud();
    //! \brief La donnee dans l'arbre
    Personne		*m_personne;

    //! \brief Pointe sur le fils gauche du noeud soit un frere ou une soeur
    Noeud		*m_gauche;

    //! \brief Pointe sur le fils droit du noeud soit un fils
    Noeud		*m_droite;

    //! \brief La hauteur d'un noeud, utile pour le balancement
    int			m_hauteur;
    
  };

  //! \brief Constructeur par parametre 
  //! \param[in] p_personne la personne de la racine de l'arbre
  ArbreGenealogique(const Personne &p_personne);

  //! \brief Destructeur par defaut
  ~ArbreGenealogique();

  //! \brief Ajouter un enfant a un parent dans un arbre
  //! \brief Si le p_parent est NULL creer un parent avec p_enfant
  //! \param[in] p_parent la reference du parent
  //! \pre Si l'arbre est vide p_parent == p_enfant
  //! \param[in] p_enfant la reference de l'enfant
  void				ajouterEnfant(const Personne &p_parent,
					      const Personne &p_enfant);

  //! \brief Trouve tous les enfants du parent
  //! \param[in] p_parent le parent des enfants
  //! \return un vector contenant tous les enfants
  std::vector<Personne *>	enfantsDe(const Personne &p_parent) const;

  //! \brief Permet de savoir si une personne est dans l'arbre
  //! \param[in] p_personne la personne recherchee
  //! \pre l'arbre ne doit pas etre vide
  //! \return true si la personne est dans l'arbre sinon false
  //! \exception logic_error si l'arbre est vide
  bool				appartient(const Personne &p_personne) const;

  //! \brief Surcharge de l'operateur <<
  //! \param[in] p_arbreG l'arbre genealogique a sortir
  //! \param[out] p_os le flux de sortie contenant l'arbre formatee
  //! \return un flux de sortie pour les appels en cascade

  Noeud				*m_racine;
  friend std::ostream		&operator<<(std::ostream &p_os, const ArbreGenealogique &p_arbreG);

private:

  //! \brief Trouve l'adresse du noeud ou se trouve la personne par parcours recursif pre-ordre
  //! \brief appelle _trouvePersonne
  //! \param[in] p_personne la personne cherchee
  //! \param[in] p_trouve le noeud trouve
  //! \post p_trouve contient l'adresse du noeud ou est la personne sinon NULL
  void				trouvePersonne(const Personne &p_personne,
						 Noeud *&p_trouve) const;
  //! \brief Trouve l'adresse du noeud ou se trouve la personne par parcours pre-ordre
  //! \param[in] p_racine la racine de l'arbre
  //! \param[in] p_personne la personne cherchee
  //! \param[in] p_trouve le noeud trouve
  //! \post p_trouve contient l'adresse du noeud ou est la personne sinon NULL  
  void				_trouvePersonne(Noeud *p_racine, const Personne &p_personne,
						Noeud *&p_trouve) const;
  //! \brief Parcourt l'arbre en post-ordre
  //! \param[in] p_Ncourant l'arbre parcouru
  //! \param[in] p_vPersonnes un vector contenant le resultat du parcours
  //! \post p_vPersonnes est rempli
  void				_postOrdre(Noeud *p_Ncourant,
					   std::vector<Personne *> &p_vPersonnes) const;

  void				_ajouterEnfant(Noeud *noeud_fils, const Personne &p_enfant);

  void				_creerVecteurEnfant(Noeud *p_enfant,
    					            std::vector<Personne *> p_tab_personne) const;


  std::string	_display(Noeud *p_noeud, std::string &p_str) const;
  std::string		display() const;
  // Attributs prives

  std::string			m_nom;

};

#endif		// !ARBREGENEALOGIQUE_H__

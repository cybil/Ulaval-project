/**
 * \file Liste.h
 * \brief Classe Définissant le type abstrait liste
 * \author Mathieu Dumoulin (m.a.j. par Cybil Bourely - CMBOU5)
 * \version 0.2
 * \date 21 septembre 2013
 *
 * Implémentation dans une liste doublement chaînée
 */

#ifndef _LISTE__H
#define _LISTE__H

#include <iostream>
#include <stdexcept>
#include <string>

/**
 * \class Liste
 *
 * \brief classe générique représentant une liste ordonnée
 *
 *  La classe gére une liste ordonnée générique. L'implémentation
 *  se fait dans une liste circulaire.
 */
template<typename T>
class Liste
{
public:

  //Constructeurs
  Liste();
  Liste(const Liste&);
  ~Liste();

  //Surcharge d'opérateurs
  Liste<T>		&operator =(const Liste<T>&);

  //Modificateurs
  void		ajouter(const T&, int);
  void		enleverEl(const T&);
  void		enleverPos(int);

  //Sélécteurs
  int			taille() const;
  bool		estVide() const;
  bool		appartient(const T&) const;
  const T		&element(int) const;
  int			position(const T&) const;

  // friend
  template<class U> friend std::ostream& operator <<(std::ostream& f, const Liste<U>& l);
private:

  /**
   * \class Noeud
   *
   * \brief classe interne représentant un noeud typique
   *
   *  La classe représente un noeud typique
   *  pour implémenter une liste circulaire.
   */
  class Noeud
  {
  public:
    T			m_el; /*!<L'élément de base de la liste*/
    Noeud		*m_suivant; /*!<Un pointeur vers le noeud suivant*/
    Noeud		*m_precedent; /*!<Un pointeur vers le noeud precedent*/

    explicit Noeud(const T &p_data_item, Noeud *p_next_ptr = NULL, Noeud *p_prev_ptr = NULL) :
      m_el(p_data_item), m_suivant(p_next_ptr), m_precedent(p_prev_ptr)
    {
    }
  };

  /** \typedef typedef Noeud *elem
   *  \brief Définition d'un pointeur sur un Noeud
   *
   *  Pour abréger les écritures
   */
  typedef Noeud	*elem;
  elem		m_sommetG; /*!<Pointeur vers le noeud à l'extrémitée gauche de la liste*/
  elem		m_sommetD; /*!<Pointeur vers le noeud à l'extrémitée droite de la liste*/
  int			m_cpt;

  //Méthodes privées
  void		_copier(Noeud *);
  void		_detruire();
};


#include "Liste.hpp"

#endif

/**
 * \file Pile.h
 * \brief Classe définissant le type abstrait pile
 * \author Abder
 * \version 0.1
 * \date mai 2011
 *
 * Représentation dans une liste chaînée
 */

#ifndef PILE_H
#define PILE_H

#include <iostream>
#include <stdexcept>
//#pragma warning( disable : 4290 )

/** 
 * \class Pile
 *
 * \brief classe générique représentant une Pile
 *
 *  La classe gère une pile générique. L'implémentation
 *  se fait dans une liste chaînée.
 */
template <typename T>
class Pile
{
 public:
  // constructeurs et destructeurs

  /**
   * \brief Constructeur par défaut
   *
   * \post Une instance de la classe Pile est initialisée
   */
  Pile();	//constructeur

		/**
		 *  \brief Constructeur de copie
		 *
		 * \pre Il faut qu'il y ait suffisamment de mémoire
		 * \post une copie profonde de la pile source
		 * \exception bad_alloc s'il n'y a pas assez de mémoire
		 */
  Pile(const Pile&) throw(std::bad_alloc);	

  /**
   *  \brief Destructeur
   *
   *  \post l'instance de Pile est détruite
   */
  ~Pile();									 

  // Modificateurs

  /**                       
   *  \brief Empiler un nouvel élément dans la pile
   * 
   * \pre Il y a assez de mémoire pour l'empilement
   * \post La pile comprend un élément de plus
   * \exception bad_alloc s'il n'y a pas assez de mémoire
   */
  void empiler(const T&) throw(std::bad_alloc);

  /**                       
   *  \brief Dépiler un élément 
   * 
   * \pre La pile ne doit pas être vide
   * \post La pile comprend un élément de moins
   * \exception logic_error si l'élément est absent 
   */
  T depiler() throw (std::logic_error);

  //Sélecteurs

  /**                       
   * \brief Vérifier si la liste est vide
   *
   * \post La pile est inchangée 
   * \post VRAI est retourné si la pile est vide, FAUX sinon
   */
  bool estVide() const;

  /**                       
   * \brief Demander la taille de la pile 
   *
   * \post La pile est inchangée 
   * \post La taille de la pile 
   */
  int taille() const;

  /**                       
   * \brief Retourner l'élément au sommet de la pile
   *
   * \pre La pile ne doit pas être vide 
   *
   * \post Une copie de l'élément retourné
   * \post La pile est inchangée  
   * \exception logic_error si la pile est vide
   */
  const T& top()  throw (std::logic_error);	// élément au sommet

  //surcharge d'opérateurs

  /**                       
   * \brief Surcharger l'opérateur []
   *
   * \pre L'indice doit être compris entre 0 et la cardinalité de la pile - 1 
   * \post L'élément à la position voulue est retournée
   * \exception out_of_range si l'indice n'est pas correcte 
   */
  const T& operator[] (int) const throw (std::out_of_range);

  /**                       
   * \brief Surcharger l'opérateur = 
   *
   * \pre Il y a assez de mémoire pour l'opération 
   * \post Une copie d'une pile est retournée
   * \exception bad_alloc si la mémoire est insuffisante
   */
  const Pile<T>& operator = (const Pile<T>&) throw (std::bad_alloc);

  /**                       
   * \brief Surcharge de l'opérateur << 
   *
   * \post Un flot de sortie correspondant à la liste est retournée 
   */
  template <class U> friend std::ostream& operator << (std::ostream& f, const Pile<U>& p); 

 private:
  /** 
   * \class Noeud
   *
   * \brief classe interne représentant un noeud typique
   *
   *  La classe représente un noeud typique
   *  pour implémenter une liste chaînée.
   */
  class Noeud{	
  public:
    T m_el;				/*!<L'élément de base de la pile*/	
    Noeud *  m_suivant;	/*!<Un pointeur vers le noeud suivant*/

			/**                       
			 * \brief Constructeur de la classe Noeud
			 *
			 * \post un noeud typique est intialisé
			 */
    Noeud (const T& data_item, Noeud * next_ptr = 0) :	
    m_el(data_item), m_suivant(next_ptr) {}
  };	
		
  /** \typedef typedef Noeud *elem
   *  \brief Définition d'un pointeur sur un Noeud
   *
   *  Pour abréger les écritures
   */
  typedef Noeud * elem;
  elem m_sommet;	/*!<Pointeur vers le premier noeud, le sommet de la pile*/			
  int m_cpt;  /*!<Cardinalité de la pile*/
};
	
#include "Pile.hpp"

#endif

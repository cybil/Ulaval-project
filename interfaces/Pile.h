/**
 * \file Pile.h
 * \brief Classe d�finissant le type abstrait pile
 * \author Abder
 * \version 0.1
 * \date mai 2011
 *
 * Repr�sentation dans une liste cha�n�e
 */

#ifndef PILE_H
#define PILE_H

#include <iostream>
#include <stdexcept>
//#pragma warning( disable : 4290 )

/** 
 * \class Pile
 *
 * \brief classe g�n�rique repr�sentant une Pile
 *
 *  La classe g�re une pile g�n�rique. L'impl�mentation
 *  se fait dans une liste cha�n�e.
 */
template <typename T>
class Pile
{
 public:
  // constructeurs et destructeurs

  /**
   * \brief Constructeur par d�faut
   *
   * \post Une instance de la classe Pile est initialis�e
   */
  Pile();	//constructeur

		/**
		 *  \brief Constructeur de copie
		 *
		 * \pre Il faut qu'il y ait suffisamment de m�moire
		 * \post une copie profonde de la pile source
		 * \exception bad_alloc s'il n'y a pas assez de m�moire
		 */
  Pile(const Pile&) throw(std::bad_alloc);	

  /**
   *  \brief Destructeur
   *
   *  \post l'instance de Pile est d�truite
   */
  ~Pile();									 

  // Modificateurs

  /**                       
   *  \brief Empiler un nouvel �l�ment dans la pile
   * 
   * \pre Il y a assez de m�moire pour l'empilement
   * \post La pile comprend un �l�ment de plus
   * \exception bad_alloc s'il n'y a pas assez de m�moire
   */
  void empiler(const T&) throw(std::bad_alloc);

  /**                       
   *  \brief D�piler un �l�ment 
   * 
   * \pre La pile ne doit pas �tre vide
   * \post La pile comprend un �l�ment de moins
   * \exception logic_error si l'�l�ment est absent 
   */
  T depiler() throw (std::logic_error);

  //S�lecteurs

  /**                       
   * \brief V�rifier si la liste est vide
   *
   * \post La pile est inchang�e 
   * \post VRAI est retourn� si la pile est vide, FAUX sinon
   */
  bool estVide() const;

  /**                       
   * \brief Demander la taille de la pile 
   *
   * \post La pile est inchang�e 
   * \post La taille de la pile 
   */
  int taille() const;

  /**                       
   * \brief Retourner l'�l�ment au sommet de la pile
   *
   * \pre La pile ne doit pas �tre vide 
   *
   * \post Une copie de l'�l�ment retourn�
   * \post La pile est inchang�e  
   * \exception logic_error si la pile est vide
   */
  const T& top()  throw (std::logic_error);	// �l�ment au sommet

  //surcharge d'op�rateurs

  /**                       
   * \brief Surcharger l'op�rateur []
   *
   * \pre L'indice doit �tre compris entre 0 et la cardinalit� de la pile - 1 
   * \post L'�l�ment � la position voulue est retourn�e
   * \exception out_of_range si l'indice n'est pas correcte 
   */
  const T& operator[] (int) const throw (std::out_of_range);

  /**                       
   * \brief Surcharger l'op�rateur = 
   *
   * \pre Il y a assez de m�moire pour l'op�ration 
   * \post Une copie d'une pile est retourn�e
   * \exception bad_alloc si la m�moire est insuffisante
   */
  const Pile<T>& operator = (const Pile<T>&) throw (std::bad_alloc);

  /**                       
   * \brief Surcharge de l'op�rateur << 
   *
   * \post Un flot de sortie correspondant � la liste est retourn�e 
   */
  template <class U> friend std::ostream& operator << (std::ostream& f, const Pile<U>& p); 

 private:
  /** 
   * \class Noeud
   *
   * \brief classe interne repr�sentant un noeud typique
   *
   *  La classe repr�sente un noeud typique
   *  pour impl�menter une liste cha�n�e.
   */
  class Noeud{	
  public:
    T m_el;				/*!<L'�l�ment de base de la pile*/	
    Noeud *  m_suivant;	/*!<Un pointeur vers le noeud suivant*/

			/**                       
			 * \brief Constructeur de la classe Noeud
			 *
			 * \post un noeud typique est intialis�
			 */
    Noeud (const T& data_item, Noeud * next_ptr = 0) :	
    m_el(data_item), m_suivant(next_ptr) {}
  };	
		
  /** \typedef typedef Noeud *elem
   *  \brief D�finition d'un pointeur sur un Noeud
   *
   *  Pour abr�ger les �critures
   */
  typedef Noeud * elem;
  elem m_sommet;	/*!<Pointeur vers le premier noeud, le sommet de la pile*/			
  int m_cpt;  /*!<Cardinalit� de la pile*/
};
	
#include "Pile.hpp"

#endif

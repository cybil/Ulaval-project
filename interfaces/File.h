
/**
 * \file FileTableau.h
 * \brief Classe d�finissant le type abstrait file
 * \author Abder
 * \version 0.1
 * \date mai 2011
 *
 * Repr�sentation dans un tableau dynamique 
 */

#ifndef _FILE_H
#define _FILE_H

#include <iostream>
#include <stdexcept>
//#pragma warning( disable : 4290 )

/** 
 * \class File
 *
 * \brief classe g�n�rique repr�sentant une File
 *
 *  La classe g�re une file g�n�rique. L'impl�mentation
 *  se fait dans un tableau dynamique.
 */
template<typename T>
class File
{
public:
  //	constructeurs et destructeurs:

  /**
   *  \brief Constructeur  
   *
   *  \pre Il faut qu'il y ait suffisamment de m�moire
   *  \post Une instance de la classe File est initialis�e
   *  \exception bad_alloc si la m�moire est insuffisante
   */
  File(const int max = MAX_FILE) throw(std::bad_alloc); 

  /**
   *  \brief Constructeur de copie
   *
   * \pre Il faut qu'il y ait suffisamment de m�moire
   *  \post une copie profonde la file source
   *  \exception bad_alloc s'il n'y a pas assez de m�moire
   */
  File(const File &) throw(std::bad_alloc);	

  /**
   *  \brief Destructeur
   *
   *  \post l'instance de File est d�truite
   */
  ~File();										 

  //	modificateurs

  /**                       
   *  \brief Enfiler un nouvel �l�ment dans la file
   * 
   * \pre La file n'est pas pleine
   * \post La file comprend un �l�ment de plus
   * \exception length_error si la file est pleine
   */
  void enfiler(const T&) throw (std::length_error);

  /**                       
   *  \brief D�filer un �l�ment 
   * 
   * \pre La file ne doit pas �tre vide
   * \post La file comprend un �l�ment de moins
   * \exception logic_error si la file est vide
   */
  T defiler() throw(std::logic_error);

  // s�lecteurs

  /**                       
   * \brief Demander la taille de la file 
   *
   * \post La file est inchang�e 
   * \post La taille de la file
   */
  int taille() const;

  /**                       
   * \brief V�rifier si la file est vide
   *
   * \post La file est inchang�e 
   * \post VRAI est retourn� si la file est vide, FAUX sinon
   */
  bool estVide() const;

  /**                       
   * \brief V�rifier si la file est pleine
   *
   * \post La file est inchang�e 
   * \post VRAI est retourn� si la file est pleine, FAUX sinon
   */
  bool estPleine() const; 

  /**                       
   * \brief Retourner l'�l�ment au d�but de la file
   *
   * \pre La file ne doit pas �tre vide 
   * \post Une copie de l'�l�ment est retourn�
   * \post La file est inchang�e  
   * \exception logic_error si la file est vide
   */
  const T& premier()  const throw (std::logic_error);	

  /**                       
   * \brief Retourner l'�l�ment au queue de la file
   *
   * \pre La file ne doit pas �tre vide 
   * \post Une copie de l'�l�ment est retourn�
   * \post La file est inchang�e  
   * \exception logic_error si la file est vide
   */
  const T& dernier()  throw (std::logic_error);	 

  // surcharges d'op�rateurs

  /**                       
   * \brief Surcharger l'op�rateur []
   *
   * \pre L'indice doit �tre compris entre 0 et la cardinalit� de la pile - 1 
   * \post L'�l�ment � la position voulue est retourn�e
   * \exception out_of_range si l'indice n'est pas correcte
   */
  const T& operator [](int) const throw (std::out_of_range);

  /**                       
   * \brief Surcharger l'op�rateur = 
   *
   * \pre Il y a assez de m�moire pour l'op�ration 
   * \post Une copie d'une file est retourn�e
   * \exception bad_alloc si la m�moire est insuffisante
   */
  const File<T>& operator = (const File<T>&) throw (std::bad_alloc);

  /**                       
   * \brief Surcharge de l'op�rateur << 
   *
   * \post Un flot de sortie correspondant � la file est retourn�e 
   */
  template <typename U> friend std::ostream& operator << (std::ostream& f, const File<U>& q); 

private:
  static const int MAX_FILE = 100; /*!< Capacit� de la file par d�faut*/
  T *tab;			/*!< Tableau contenant la file*/
  int tete;		/*!< Tete de la file*/
  int queue;		/*!< Queue de la file*/
  int tailleMax;	/*!< Capacit� courante de la file*/
  int cpt;		/*!< Nombre d'�l�ments effectifs dans la file*/
};

#include "File.hpp"

#endif






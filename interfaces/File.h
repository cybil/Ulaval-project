
/**
 * \file FileTableau.h
 * \brief Classe définissant le type abstrait file
 * \author Abder
 * \version 0.1
 * \date mai 2011
 *
 * Représentation dans un tableau dynamique 
 */

#ifndef _FILE_H
#define _FILE_H

#include <iostream>
#include <stdexcept>
//#pragma warning( disable : 4290 )

/** 
 * \class File
 *
 * \brief classe générique représentant une File
 *
 *  La classe gère une file générique. L'implémentation
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
   *  \pre Il faut qu'il y ait suffisamment de mémoire
   *  \post Une instance de la classe File est initialisée
   *  \exception bad_alloc si la mémoire est insuffisante
   */
  File(const int max = MAX_FILE) throw(std::bad_alloc); 

  /**
   *  \brief Constructeur de copie
   *
   * \pre Il faut qu'il y ait suffisamment de mémoire
   *  \post une copie profonde la file source
   *  \exception bad_alloc s'il n'y a pas assez de mémoire
   */
  File(const File &) throw(std::bad_alloc);	

  /**
   *  \brief Destructeur
   *
   *  \post l'instance de File est détruite
   */
  ~File();										 

  //	modificateurs

  /**                       
   *  \brief Enfiler un nouvel élément dans la file
   * 
   * \pre La file n'est pas pleine
   * \post La file comprend un élément de plus
   * \exception length_error si la file est pleine
   */
  void enfiler(const T&) throw (std::length_error);

  /**                       
   *  \brief Défiler un élément 
   * 
   * \pre La file ne doit pas être vide
   * \post La file comprend un élément de moins
   * \exception logic_error si la file est vide
   */
  T defiler() throw(std::logic_error);

  // sélecteurs

  /**                       
   * \brief Demander la taille de la file 
   *
   * \post La file est inchangée 
   * \post La taille de la file
   */
  int taille() const;

  /**                       
   * \brief Vérifier si la file est vide
   *
   * \post La file est inchangée 
   * \post VRAI est retourné si la file est vide, FAUX sinon
   */
  bool estVide() const;

  /**                       
   * \brief Vérifier si la file est pleine
   *
   * \post La file est inchangée 
   * \post VRAI est retourné si la file est pleine, FAUX sinon
   */
  bool estPleine() const; 

  /**                       
   * \brief Retourner l'élément au début de la file
   *
   * \pre La file ne doit pas être vide 
   * \post Une copie de l'élément est retourné
   * \post La file est inchangée  
   * \exception logic_error si la file est vide
   */
  const T& premier()  const throw (std::logic_error);	

  /**                       
   * \brief Retourner l'élément au queue de la file
   *
   * \pre La file ne doit pas être vide 
   * \post Une copie de l'élément est retourné
   * \post La file est inchangée  
   * \exception logic_error si la file est vide
   */
  const T& dernier()  throw (std::logic_error);	 

  // surcharges d'opérateurs

  /**                       
   * \brief Surcharger l'opérateur []
   *
   * \pre L'indice doit être compris entre 0 et la cardinalité de la pile - 1 
   * \post L'élément à la position voulue est retournée
   * \exception out_of_range si l'indice n'est pas correcte
   */
  const T& operator [](int) const throw (std::out_of_range);

  /**                       
   * \brief Surcharger l'opérateur = 
   *
   * \pre Il y a assez de mémoire pour l'opération 
   * \post Une copie d'une file est retournée
   * \exception bad_alloc si la mémoire est insuffisante
   */
  const File<T>& operator = (const File<T>&) throw (std::bad_alloc);

  /**                       
   * \brief Surcharge de l'opérateur << 
   *
   * \post Un flot de sortie correspondant à la file est retournée 
   */
  template <typename U> friend std::ostream& operator << (std::ostream& f, const File<U>& q); 

private:
  static const int MAX_FILE = 100; /*!< Capacité de la file par défaut*/
  T *tab;			/*!< Tableau contenant la file*/
  int tete;		/*!< Tete de la file*/
  int queue;		/*!< Queue de la file*/
  int tailleMax;	/*!< Capacité courante de la file*/
  int cpt;		/*!< Nombre d'éléments effectifs dans la file*/
};

#include "File.hpp"

#endif






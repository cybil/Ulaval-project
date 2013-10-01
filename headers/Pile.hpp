/**
 * \file Pile.hpp
 * \brief Le code des opérateurs du type abstrait pile.
 * \author Abder
 * \version 0.1
 * \date septembre 2011
 *
 * Implémentation de la classe générique Pile dans une liste chaînée
 *
 */

#include <exception>

//********************************
// constructeurs et destructeurs
//********************************
  
/**
 * \brief Constructeur par défaut
 *
 * \post Une instance de la classe Pile est initialisée
 */
template<typename T>
Pile<T>::Pile()
{
  m_cpt = 0;
  m_sommet = NULL;
}
  
/**
 *  \brief Constructeur de copie
 *
 * \pre Il faut qu'il y ait suffisamment de mémoire
 * \post une copie profonde de la pile source
 * \exception bad_alloc s'il n'y a pas assez de mémoire
 */
template<typename T>
Pile<T>::Pile(const Pile &p_pile) throw (std::bad_alloc)
{ 
  m_cpt = 0;
  m_sommet = NULL;
  
  for (int i = p_pile.taille() - 1; i >= 0; i--)
    empiler(p_pile[i]);
}

/**
 *  \brief Destructeur
 *
 *  \post l'instance de Pile est détruite
 */
template<typename T>
Pile<T>::~Pile()
{
  if (m_cpt > 0)
    {
      elem tmp;
	
      while (m_cpt != 0)
	{
	  tmp = m_sommet->m_suivant;
	  delete (m_sommet);
	  m_sommet = tmp;
	  m_cpt--;
	}
    }
}
  
//******************
// Modificateurs
//******************
  
/**                       
 *  \brief Empiler un nouvel élément dans la pile
 * 
 * \pre Il y a assez de mémoire pour l'empilement
 * \post La pile comprend un élément de plus
 * \exception bad_alloc s'il n'y a pas assez de mémoire
 */
template<typename T>
void Pile<T>::empiler(const T& p_nouveauElem) throw (std::bad_alloc)
{
  elem nouveauElem = new Noeud(p_nouveauElem, m_sommet);
  if (nouveauElem == NULL)
    throw std::bad_alloc();
    
  m_sommet = nouveauElem;
  m_cpt++;
}
  
/**
 *  \brief Dépiler un élément 
 * 
 * \pre La pile ne doit pas être vide
 * \post La pile comprend un élément de moins
 * \exception logic_error si l'élément est absent 
 */
template<typename T>
T Pile<T>::depiler() throw (std::logic_error)
{
  if (m_cpt == 0)
    throw std::logic_error("");
    
  elem tmp = m_sommet;
    
  m_sommet = tmp->m_suivant;
  m_cpt--;
  T tmp_el = tmp->m_el;
  delete (tmp);
  return (tmp_el);
}
  
//***********
//Sélecteurs
//***********
  
/**                       
 * \brief Vérifier si la liste est vide
 *
 * \post La pile est inchangée 
 * \post VRAI est retourné si la pile est vide, FAUX sinon
 */
template<typename T>
bool Pile<T>::estVide() const
{
  if (m_cpt != 0)
    return (false);
  return (true);
}
  
/**     
 * \brief Demander la taille de la pile 
 *
 * \post La pile est inchangée 
 * \post La taille de la pile 
 */
template<typename T>
int Pile<T>::taille() const
{
  return (m_cpt);
}
  
/**                       
 * \brief Retourner l'élément au sommet de la pile
 *
 * \pre La pile ne doit pas être vide 
 *
 * \post Une copie de l'élément retourné
 * \post La pile est inchangée  
 * \exception logic_error si la pile est vide
 */
template<typename T>
const T& Pile<T>::top() throw (std::logic_error)
{
  if (m_cpt == 0)
    throw std::logic_error("Liste vide");
    
  return (m_sommet->m_el);
}
  
//***********************
//surcharge d'opérateurs
//***********************
  
/**                       
 * \brief Surcharger l'opérateur []
 *
 * \pre L'indice doit être compris entre 0 et la cardinalité de la pile - 1 
 * \post L'élément à la position voulue est retournée
 * \exception out_of_range si l'indice n'est pas correcte 
 */
template<typename T>
const T& Pile<T>::operator[] (int p_index) const throw (std::out_of_range)
{
  if (m_cpt < p_index && p_index >= 0)
    throw std::out_of_range("Probleme d'index");
    
  elem tmp = m_sommet;
    
  for (int i = 0; i < p_index && tmp; i++)
    tmp = tmp->m_suivant;
  return (tmp->m_el);
}
  
/**
 * \brief Surcharger l'opérateur = 
 *
 * \pre Il y a assez de mémoire pour l'opération 
 * \post Une copie d'une pile est retournée
 * \exception bad_alloc si la mémoire est insuffisante
 */
template<typename T>
const Pile<T>& Pile<T>::operator = (const Pile<T> & p_rhs) throw (std::bad_alloc)
{
  if (this != &p_rhs)
    {
      for (int i = p_rhs.taille() - 1; i >= 0; i--)
	empiler(p_rhs[i]);
    }
  return (*this);
}
  
/**
 * \brief Surcharge de l'opérateur << 
 *
 * \post Un flot de sortie correspondant à la liste est retournée
 */
template <class U> 
std::ostream& operator << (std::ostream& p_f, const Pile<U>& p_index)
{
  if (p_index.taille() == 0)
    return (p_f);
  for (int i = 0; i < p_index.taille(); i++)
    p_f << p_index[i];
    
  return (p_f);
}


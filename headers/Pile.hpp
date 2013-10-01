/**
 * \file Pile.hpp
 * \brief Le code des op�rateurs du type abstrait pile.
 * \author Abder
 * \version 0.1
 * \date septembre 2011
 *
 * Impl�mentation de la classe g�n�rique Pile dans une liste cha�n�e
 *
 */

#include <exception>

//********************************
// constructeurs et destructeurs
//********************************
  
/**
 * \brief Constructeur par d�faut
 *
 * \post Une instance de la classe Pile est initialis�e
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
 * \pre Il faut qu'il y ait suffisamment de m�moire
 * \post une copie profonde de la pile source
 * \exception bad_alloc s'il n'y a pas assez de m�moire
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
 *  \post l'instance de Pile est d�truite
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
 *  \brief Empiler un nouvel �l�ment dans la pile
 * 
 * \pre Il y a assez de m�moire pour l'empilement
 * \post La pile comprend un �l�ment de plus
 * \exception bad_alloc s'il n'y a pas assez de m�moire
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
 *  \brief D�piler un �l�ment 
 * 
 * \pre La pile ne doit pas �tre vide
 * \post La pile comprend un �l�ment de moins
 * \exception logic_error si l'�l�ment est absent 
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
//S�lecteurs
//***********
  
/**                       
 * \brief V�rifier si la liste est vide
 *
 * \post La pile est inchang�e 
 * \post VRAI est retourn� si la pile est vide, FAUX sinon
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
 * \post La pile est inchang�e 
 * \post La taille de la pile 
 */
template<typename T>
int Pile<T>::taille() const
{
  return (m_cpt);
}
  
/**                       
 * \brief Retourner l'�l�ment au sommet de la pile
 *
 * \pre La pile ne doit pas �tre vide 
 *
 * \post Une copie de l'�l�ment retourn�
 * \post La pile est inchang�e  
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
//surcharge d'op�rateurs
//***********************
  
/**                       
 * \brief Surcharger l'op�rateur []
 *
 * \pre L'indice doit �tre compris entre 0 et la cardinalit� de la pile - 1 
 * \post L'�l�ment � la position voulue est retourn�e
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
 * \brief Surcharger l'op�rateur = 
 *
 * \pre Il y a assez de m�moire pour l'op�ration 
 * \post Une copie d'une pile est retourn�e
 * \exception bad_alloc si la m�moire est insuffisante
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
 * \brief Surcharge de l'op�rateur << 
 *
 * \post Un flot de sortie correspondant � la liste est retourn�e
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


//! \file Liste.hpp
//! \brief Le code des opérateurs de la liste.
//! \author Cybil Bourely - CMBOU5
//! \version 0.1
//! \date 21 septembre 2013
//! Implémentation de la classe générique Liste dans une liste doublement chaînée

#include <iostream>
#include <exception>

//*****************************
// Constructeurs & Destructeur
//*****************************

//! \brief Constructeur par defaut
//! \post Une instance de la classe Liste est initialisee
template<typename T>
Liste<T>::Liste()
{
  m_sommetG = NULL;
  m_sommetD = NULL;
  m_cpt = 0;
}

//! \brief Constructeur par copie
//! \pre Il faut suffisamment de memoire
//! \post Une copie profonde la Liste source
//! \exception bad_alloc s'il n'y a pas assez de memoire
template<typename T>
Liste<T>::Liste(const Liste &p_list)
{
  m_sommetG = NULL;
  m_sommetD = NULL;
  m_cpt = 0;
  for (int i = 1; i <= p_list.taille(); i++)
    ajouter(p_list.element(i), i);
}

//! \brief Destructeur par defaut
//! \post L'instance de Liste est detruite
template<typename T>
Liste<T>::~Liste()
{
  Liste<T>::Noeud	*tmp = m_sommetG;
  Liste<T>::Noeud	*aDetruire;

  while (tmp)
    {
      aDetruire = tmp;
      tmp = tmp->m_suivant;
      delete aDetruire;
    }
  delete tmp;
}



//***********************
//Surcharge d'opérateurs
//***********************

//! \brief Surcharge l'operateur =
//! \param[in] list est une reference constante sur la liste source
//! \return une reference sur l'instance de liste utilisee
//! \pre Il y a assez de memoire pour l'operation
//! \post une copie d'une liste est retourner
//! \exception bad_alloc si la precondition n'est pas respectee
template<typename T>
Liste<T>		&Liste<T>::operator =(const Liste<T> &p_list)
{
  for (int i = 1; i <= p_list.taille(); i++)
    ajouter(p_list.element(i), i);
  return *this;
}



//***************
// Modificateurs
//***************

//! \brief Ajoute un nouvel element dans la liste
//! \param[in] elem est une reference constante sur l'element a ajouter
//! \param[in] pos est un entier qui represente la position du nouvel element dans la liste
//! \pre Il y a assez de memoire pour ajouter l'element x
//! \pre La position d'ajout, p_pos, est comprise entre 1 et |L|+1
//! \post La liste comprend un element de plus
//! \post La liste est inchangee sinon
//! \exception range_error si la precondition n'est pas respectee
template<typename T>
void		Liste<T>::ajouter(const T &p_elem, int p_pos)
{
  if (p_pos < 1 || p_pos > taille() + 1)
    throw std::range_error("range_error");

  Liste<T>::Noeud	*nouveauNoeud = new Liste<T>::Noeud(p_elem, NULL, NULL);

  if (p_pos == 1 && taille() == 0)
    {
      m_sommetD = nouveauNoeud;
      m_sommetG = nouveauNoeud;
      ++m_cpt;
      return ;
    }

  Liste<T>::Noeud	*tmp = m_sommetG;
  int			i = 1;

  if (p_pos == 1)
    {
      m_sommetG = nouveauNoeud;
      nouveauNoeud->m_suivant = tmp;
      tmp->m_precedent = nouveauNoeud;
      ++m_cpt;
      return ;
    }
  while (tmp)
    {
      if (i == p_pos - 1)
	{
	  nouveauNoeud->m_precedent = tmp;
	  nouveauNoeud->m_suivant = tmp->m_suivant;
	  if (tmp->m_suivant)
	    tmp->m_suivant->m_precedent = nouveauNoeud;
	  tmp->m_suivant = nouveauNoeud;
	  if (p_pos == 1)
	    m_sommetG = nouveauNoeud;
	  ++m_cpt;
	  return ;
	}
      i++;
      tmp = tmp->m_suivant;
    }
}

//! \brief Enleve la premiere occurence d'un element
//! \param[in] elem est une reference constante sur l'element a enlever
//! \pre L'element doit etre present dans la liste
//! \post La liste comprend un element de moins
//! \post La liste est inchangee sinon
//! \exception logic_error si l'element est absent
template<typename T>
void			Liste<T>::enleverEl(const T &p_elem)
{
  Liste<T>::Noeud	*tmp = m_sommetG;

  while (tmp)
    {
      if (p_elem == tmp->m_el)
	{
	  if (position(p_elem) == 1)
	    m_sommetG = tmp->m_suivant;
	  if (tmp->m_precedent)
	    tmp->m_precedent->m_suivant = tmp->m_suivant;
	  if (tmp->m_suivant)
	    tmp->m_suivant->m_precedent = tmp->m_precedent;
	  delete tmp;
	  --m_cpt;
	  return ;
	}
      tmp = tmp->m_suivant;
    }
  throw std::logic_error("logic_error");
}

//! \brief Enleve un element a une certaine position
//! \param[in] pos est un entier representant la position de l'element a enlever
//! \pre La position doit etre comprise entre 1 et |L|+1
//! \post La liste comprend un element de moins
//! \post La liste est inchangee sinon
//! \exception range_error si l'element est absent
template<typename T>
void		Liste<T>::enleverPos(int p_pos)
{
  if (p_pos < 1 || p_pos > taille())
    throw std::range_error("range_error");
  enleverEl(element(p_pos));
}



//***********
//Sélécteurs
//***********

//! \brief Demande la taille de la liste
//! \return un entier representant la taille de la liste
//! \post La liste est inchangee
//! \post La taille de la liste est retournee
template<typename T>
int			Liste<T>::taille() const
{
  return m_cpt;
}

//! \brief Verifie si la liste est vide
//! \return un booleen qui indique si la liste est vide ou non
//! \post La liste est inchangee
//! \post TRUE est retourne si la liste est vide, FALSE sinon
template<typename T>
bool		Liste<T>::estVide() const
{
  return taille() == 0 ? true : false;
}

//! \brief Recherche d'un element dans la liste
//! \param[in] elem est une reference constante sur l'element recherche
//! \return un booleen representant la presence ou l'absence de elem
//! \post La liste est inchangee
//! \post renvoie TRUE si l'element est present, FALSE sinon
template<typename T>
bool		Liste<T>::appartient(const T &p_elem) const
{
  Liste<T>::Noeud	*tmp = m_sommetG;

  while (tmp)
    {
      if (p_elem == tmp->m_el)
	return true;
      tmp = tmp->m_suivant;
    }
  return false;
}

//! \brief Retourne l'element a une certaine position
//! \param[in] pos est un entier representant la position de l'element voulu
//! \return une reference constante sur l'element a la position pos
//! \pre La position est comprise entre 1 et |L|+1
//! \post La liste est inchangee dans tous les cas
//! \post L'element a la position demandee est retourne
//! \exception range_error si la precondition n'est pas respectee
template<typename T>
const T		&Liste<T>::element(int p_pos) const
{
  Liste<T>::Noeud	*tmp = m_sommetG;
  int			i = 1;

  while (tmp)
    {
      if (i == p_pos)
	return tmp->m_el;
      i++;
      tmp = tmp->m_suivant;
    }
  throw std::range_error("range_error");
}

//! \brief Retourne la position d'un element
//! \param[in] elem est une reference constante sur l'element voulu
//! \return un entier representant la position de elem
//! \pre L'element doit etre present dans la liste 
//! \post La liste est inchangee
//! \post La position de l'element est retournee
//! \exception logic_error si la precondition n'est pas respectee
template<typename T>
int			Liste<T>::position(const T &p_elem) const
{
  Liste<T>::Noeud	*tmp = m_sommetG;
  int			i = 1;

  while (tmp)
    {
      if (p_elem == tmp->m_el)
	return i;
      i++;
      tmp = tmp->m_suivant;
    }
  throw std::logic_error("logic_error");
}


//********
// Friend
//********

//! \brief Surcharge de l'operateur <<
//! \param[in] f est une reference sur le flux utilise
//! \param[in] l est une reference constante sur la liste que l'on veut parcourir
//! \return une reference sur le flux passe en parametre
//! \post Un flux de sortie correspondant a la liste est retourne
template<class U>
std::ostream& operator <<(std::ostream &p_f, const Liste<U> &p_l)
{
  for (int i = 1; i <= p_l.taille(); i++)
    p_f << p_l.element(i);
  return p_f;
}


//*********
// Private
//*********

template<typename T>
void		Liste<T>::_copier(Noeud *p_noeud)
{
  (void)p_noeud;
}

template<typename T>
void		Liste<T>::_detruire()
{    
}  

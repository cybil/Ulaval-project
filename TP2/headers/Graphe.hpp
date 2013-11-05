//! \file Graphe.hpp
//! \brief Implémentation des méthodes définies dans Graphe.h
//! \author theud1
//! \version 0.1 graphe générique
//! \date 2013-10-03

#include <iostream>
#include "Graphe.h"

/**
 * Classes internes
 */

template<typename Objet>
Graphe<Objet>::Sommet::Sommet(int p_numero, const Objet &p_etiquette)
  : m_numero(p_numero), m_etiquette(p_etiquette)
{
  std::cout << "Sommet created." << std::endl;
}

template<typename Objet>
Graphe<Objet>::Sommet::Sommet(Sommet *p_source);
{
  std::cout << "Sommet created." << std::endl;
  m_numero = p_source.m_numero;
  m_etiquette = p_source.m_etiquette;
  m_listeDest = p_source.m_listeDest;
  m_etat = p_source.m_etat;
  m_predecesseur = p_source.m_predecesseur;
  m_cout = p_source.m_cout;
  m_precedent = p_source.m_precedent;
  m_suivant = p_source.m_suivant;
}

template<typename Objet>
Graphe<Objet>::Sommet::~Sommet()
{
  std::cout << "Sommet destroyed." << std::endl;
  Graphe<Objet>::Arc		*arcTmp = m_listeDest;
  Graphe<Objet>::Arc		aDetruire;

  while (arcTmp)
    {
      aDetruire = arcTmp;
      arcTmp = arcTmp->m_suivDest;
      delete aDetruire;
    }
}


template<typename Objet>
Graphe<Objet>::Arc::Arc(Sommet *p_dest, int p_cout)
  : m_dest(p_dest), m_cout(p_cout)
{
  std::cout << "Arc created." << std::endl;
}

template<typename Objet>
Graphe<Objet>::Arc::~Arc()
{
  std::cout << "Arc destroyed." << std::endl;
}

/**
 * Constructeur & destructeur (Graphe)
 */

template<typename Objet>
Graphe<Objet>::Graphe()
  : m_nbSommets(0), m_listSommets(NULL)
{
  std::cout << "Graphe created." << std::endl;
}

template<typename Objet>
Graphe<Objet>::Graphe(const Graphe &p_source)
  : m_nbSommets(p_source.m_nbSommets), m_listSommets(p_source.m_listSommets)
{
  std::cout << "Graphe created." << std::endl;
}

template<typename Objet>
Graphe<Objet>::~Graphe()
{
  std::cout << "Graphe destroyed." << std::endl;
  Graphe<Objet>::Sommet	*tmp = m_listSommets;
  Graphe<Objet>::Sommet	*aDetruire;

  while (tmp)
    {
      aDetruire = tmp;
      tmp = tmp->m_suivant;
      delete aDetruire;
    }
}

/**
 * Surcharge d'operateur =
 */

template<typename Objet>
const Graphe<Objet>		&Graphe<Objet>::operator=(const Graphe &p_source)
{
  if (*this != p_source)
    {
      m_nbSommets = p_source.m_nbSommets;
      m_listSommets = p_source.m_listSommets;
    }
  return *this;
}

/**
 * Ajout/Suppression de sommets et d'arcs
 */

template<typename Objet>
void				Graphe<Objet>::ajouterSommet(int p_numero, const Objet &p_etiquette)
{
  if (sommetExiste(p_numero) == true)
    throw std::logic_error("logic_error");
  Graphe<Objet>::Sommet		*nouveauSommet = new Sommet(p_numero, p_etiquette);

  if (m_nbSommets == 0)
    m_listSommets = nouveauSommet;
  else
    {
      Graphe<Objet>::Sommet	*tmp = m_listSommets;
      while (tmp)
	tmp = tmp->m_suivant;
      tmp->m_suivant = nouveauSommet;
      nouveauSommet->m_precedent = tmp;
    }
  ++m_nbSommets;
}

template<typename Objet>
void				Graphe<Objet>::enleverSommet(int p_numero)
{
  if (sommetExiste(p_numero) == false)
    throw std::logic_error("logic_error");
  Graphe<Objet>::Sommet		*tmp = m_listSommets;

  while (tmp)
    {
      if (tmp->m_numero == p_numero)
	{
	  if (tmp->m_precedent)
	    tmp->m_precedent->m_suivant = tmp->m_suivant;
	  if (tmp->m_suivant)
	  tmp->m_suivant->m_precedent = tmp->m_precedent;
	  delete tmp;
	  --m_nbSommets;
	}
      tmp = tmp->m_suivant;
    }
}

template<typename Objet>
void				Graphe<Objet>::ajouterArc(int p_numOrigine, int p_numDestination,
							  int p_cout)
{
  if (sommetExiste(p_numOrigine) == false || sommetExiste(p_numDestination) == false)
    throw std::logic_error("logic_error");
  Graphe<Objet>::Arc		nouvelArc = new Arc( p_numDestination, p_cout);
  Graphe<Objet>::Sommet		*tmp = m_listSommets;

  while (tmp)
    {
      if (tmp->m_numero == p_numOrigine)
	{
	  Graphe<Objet>::Arc	*arcTmp = tmp->m_listeDest;
	  if (arcTmp == NULL)
	    arcTmp = nouvelArc;
	  else
	    {
	      while (arcTmp)
		{
		  if (arcTmp->m_dest->m_numero == p_numDestination)
		    throw std::logic_error("logic_error");
		  arcTmp = arcTmp->m_suivDest;
		}
	      arcTmp->m_suivDest = nouvelArc;
	    }
	}
      tmp = tmp->m_suivant;
    }
}

template<typename Objet>
void				Graphe<Objet>::enleverArc(int p_numOrigine, int p_numDestination)
{
  if (arcExiste(p_numOrigine, p_numDestination) == false)
    throw std::logic_error("logic_error");
  Graphe<Objet>::Sommet		*tmp = m_listSommets;

  while (tmp)
    {
      if (tmp->m_numero == p_numOrigine)
	{
	  Graphe<Objet>::Arc	*arcTmp = tmp->listeDest;
	  while (arcTmp)
	    {
	      if (arcTmp->m_suivDest && arcTmp->m_suivDest->m_dest->m_numero == p_numDestination)
		{
		  arcTmp->m_suivDest = arcTmp->m_suivDest->m_suivDest;
		  delete arcTmp->m_suivDest;
		}
	      arcTmp = arcTmp->m_suivDest;
	    }
	}
      tmp = tmp->m_suivant;
    }
  throw std::logic_error("logic_error");
}

/**
 * Donnees sur le graphe
 */

template<typename Objet>
int				Graphe<Objet>::nombreSommets() const
{
  return m_nbSommets;  
}

template<typename Objet>
bool				Graphe<Objet>::estVide() const
{
  return m_nbSommets == 0 ? true : false;
}

template<typename Objet>
std::vector<int>		Graphe<Objet>::listerSommets() const
{
  std::vector<int>		listeSommet;
  Graphe<Objet>::Sommet		*tmp = m_listSommets;

  while (tmp)
    {
      listeSommet.push_back(tmp->m_numero);
      tmp = tmp->m_suivant;
    }
  return listeSommet;
}

template<typename Objet>
std::vector<Objet>		Graphe<Objet>::listerEtiquetteSommets() const
{
  std::vector<Objet>		listeEtiquetteSommet;
  Graphe<Objet>::Sommet		*tmp = m_listSommets;

  while (tmp)
    {
      listeEtiquetteSommet.push_back(tmp->m_etiquette);
      tmp = tmp->m_suivant;
    }
  return listeEtiquetteSommet;
}

/**
 * Donnees a propos des sommets
 */

template<typename Objet>
int				Graphe<Objet>::getNumeroSommet(const Objet& etiquette) const
{
  Graphe<Objet>::Sommet		*tmp = m_listSommets;

  while (tmp)
    {
      if (tmp->m_etiquette == etiquette)
	return tmp->m_numero;
      tmp = tmp->m_suivant;
    }
  throw std::logic_error("logic_error");
}

template<typename Objet>
bool				Graphe<Objet>::sommetExiste(int p_numero) const
{
  Graphe<Objet>::Sommet		*tmp = m_listSommets;

  while (tmp)
    {
      if (tmp->m_numero == p_numero)
	return true;
      tmp = tmp->m_suivant;
    }
  return false;
}

template<typename Objet>
Objet				Graphe<Objet>::getEtiquetteSommet(int p_numero) const
{
  if (sommetExiste(p_numero) == false)
    throw std::logic_error("logic_error");
  Graphe<Objet>::Sommet		*tmp = m_listSommets;

  while (tmp)
    {
      if (tmp->m_numero == p_numero)
	return tmp->m_etiquette;
      tmp = tmp->m_suivant;
    }
  throw std::logic_error("logic_error");
}

template<typename Objet>
int				Graphe<Objet>::ordreSortieSommet(int p_numero) const
{
  if (sommetExiste(p_numero) == false)
    throw std::logic_error("logic_error");
  Graphe<Objet>::Sommet		*tmp = m_listSommets;

  while (tmp)
    {
      if (tmp->m_numero == p_numero)
	{
	  Graphe<Objet>::Arc	*arcTmp = tmp->m_listeDest;
	  int			i = 0;
	  while (arcTmp)
	    {
	      arcTmp = arcTmp->m_suivDest;
	      ++i;
	    }
	  return i;
	}
      tmp = tmp->m_suivant;
    }
  throw std::logic_error("logic_error");
}

template<typename Objet>
int				Graphe<Objet>::ordreEntreeSommet(int p_numero) const
{
  if (sommetExiste(p_numero) == false)
    throw std::logic_error("logic_error");
  Graphe<Objet>::Sommet		*tmp = m_listSommets;
  int				i = 0;

  while (tmp)
    {
      Graphe<Objet>::Arc	*arcTmp = tmp->m_listeDest;
      while (arcTmp)
	{
	  if (arcTmp->m_dest->m_numero == p_numero)
	    ++i;
	  arcTmp = arcTmp->m_suivDest;
	}
      tmp = tmp->m_suivant;
    }
  return i;
}

template<typename Objet>
std::vector<int>		Graphe<Objet>::listerSommetsAdjacents(int p_numero) const
{
  if (sommetExiste(p_numero) == false)
    throw std::logic_error("logic_error");
  std::vector<int>		listeSommetsAdjacent;
  Graphe<Objet>::Sommet		*tmp = m_listSommets;

  while (tmp)
    {
      if (tmp->m_numero == p_numero)
	{
	  Graphe<Objet>::Arc	*arcTmp = tmp->m_listeDest;
	  while (arcTmp)
	    {
	      listeSommetsAdjacent.push_back(arcTmp->m_dest);
	      arcTmp = arcTmp->m_suivDest;
	    }
	  return listeSommetsAdjacent;
	}
      tmp = tmp->m_suivant;
    }
  return listeSommetsAdjacent;
}

/**
 * Donnees a propos des arcs
 */

template<typename Objet>
bool				Graphe<Objet>::arcExiste(int p_numOrigine,
							 int p_numDestination) const
{
  if (sommetExiste(p_numOrigine) == false || sommetExiste(p_numDestination) == false)
    return false;
  Graphe<Objet>::Sommet		*tmp = m_listSommets;

  while (tmp)
    {
      if (tmp->m_numero == p_numOrigine)
	{
	  Graphe<Objet>::Arc	*arcTmp = tmp->m_listeDest;
	  while (arcTmp)
	    {
	      if (arcTmp->m_dest->m_numero == p_numDestination)
		return true;
	      arcTmp = arcTmp->m_suivDest;
	    }
	}
      tmp = tmp->m_suivant;
    }
  return false;
}

template<typename Objet>
int				Graphe<Objet>::getCoutArc(int p_numOrigine,
							  int p_numDestination) const
{
  if (arcExiste(p_numOrigine, p_numDestination) == false)
    throw std::logic_error("logic_error");
  Graphe<Objet>::Sommet		*tmp = m_listSommets;

  while (tmp)
    {
      if (tmp->m_numero == p_numOrigine)
	{
	  Graphe<Objet>::Arc	*arcTmp = tmp->m_listeDest;
	  while (arcTmp)
	    {
	      if (arcTmp->m_dest->m_numero == p_numDestination)
		return arcTmp->m_cout;
	      arcTmp = arcTmp->m_suivDest;
	    }
	}
      tmp = tmp->m_suivant;
    }
  throw std::logic_error("logic_error");
}

/**
 * Friend
 */

//! \brief		Surcharge de l'opérateur de sortie.
//! \param[in]	p_out		Le flux de sortie.
//! \param[in]	p_graphe		Le graphe à afficher.
//! \return	Le flux de sortie.
//! \pre		l'étiquette est un objet comparable, l'opérateur << y est surchargé
//! \post		Le nombre de sommets du graphe sera affiché
//! \post		Pour chaque sommet, son numéro, son étiquette seront affichés
//! \post		Pour chaque sommet, tous ses liens, le numéro des voisins, seront affichés
template<typename Objet>
std::ostream			&operator<<(ostream &p_out, const Graphe<Objet> &p_graphe)
{
  p_out << "Le graphe contient " << p_graphe.nbSommets << " sommet(s)" << std::endl;
  typename Graphe<Objet>::Sommet* vertex = p_graphe.listSommets;

  while (vertex != NULL)
    {
      p_out << "Sommet no " << vertex->numero << vertex->m_etiquette << endl;// << std::endl;
      //Afficher les arcs.
      typename Graphe<Objet>::Arc* arc = vertex->listeDest;
      if (arc != NULL)
	{
	  p_out << "Ce sommet a des liens vers le(s) sommet(s) : ";
	  while (arc->suivDest != NULL)
	    {
	      p_out << arc->dest->numero << "(" << arc->cout << "), ";
	      arc = arc->suivDest;
	    }
	  p_out << arc->dest->numero << "(" << arc->cout << ")";
	}
      p_out << std::endl;
      vertex = vertex->suivant;
    }
  return p_out;
}

/**
 * Fonctions plus complexes
 */

template<typename Objet>
Graphe			Graphe<Objet>::fermetureGraphe() const
{

}

template<typename Objet>
bool			Graphe<Objet>::estFortementConnexe() const
{

}

template<typename Objet>
void			Graphe<Objet>::getComposantesFortementConnexes(std::vector<std::vector<Objet> > &p_composantes) const
{

}

template<typename Objet>
int			Graphe<Objet>::bellmanFord(const Objet &p_eOrigine,
						   const Objet &p_eDestination,
						   std::vector<Objet> &p_chemin)
{

}

template<typename Objet>
int			Graphe<Objet>::dijkstra(const Objet &p_eOrigine,
						const Objet &p_eDestination,
						std::vector<Objet> &p_chemin)
{

}

template<typename Objet>
void			Graphe<Objet>::getPointsArticulation(std::vector<Objet> &p_sommets)
{

}

/**
 * Methodes auxiliaires
 */

template<typename Objet>
Graphe<Objet>::Sommet		*Graphe<Objet>::_getSommet(int p_numero) const
{
  if (sommetExiste(p_numero) == false)
    throw std::logic_error("logic_error");
  Graphe<Objet>::Sommet		*tmp = m_listSommets;

  while (tmp)
    {
      if (tmp->m_numero == p_numero)
	return tmp;
      tmp = tmp->m_suivant;
    }
    throw std::logic_error("logic_error");
}

template<typename Objet>
Graphe<Objet>::Arc		*Graphe<Objet>::_getArc(Sommet *p_sommet1, Sommet *p_sommet2) const
{
  Graphe<Objet>::Sommet		*tmp = getSommet(p_sommet1);

  while (tmp->m_listeDest)
    {
      if (tmp->listeDest->m_dest->m_numero == p_sommet2)
	return tmp->listeDest;
      tmp->listeDest = tmp->m_listeDest->m_suivDest;
    }
  throw std::logic_error("logic_error");
}

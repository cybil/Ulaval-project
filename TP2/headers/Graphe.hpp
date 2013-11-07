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

//! \brief Constructeur avec parametres
//! \param[in] etiquette Les donnes d'un sommet
//! \param[in] numero Le numero du sommet
//! \post Le sommet est initialise avec les parametres indique
template<typename Objet>
Graphe<Objet>::Sommet::Sommet(int p_numero, const Objet &p_etiquette)
  : m_numero(p_numero), m_etiquette(p_etiquette), m_listeDest(NULL), m_suivant(NULL)
{
}

//! \brief Constructeur par copie
//! \param[in] source La source sommet a copier
//! \post Une copie profonde du sommet a ete effectuee a partir du sommet source
template<typename Objet>
Graphe<Objet>::Sommet::Sommet(Graphe<Objet>::Sommet *p_source)
{
  m_numero = p_source.m_numero;
  m_etiquette = p_source.m_etiquette;
  m_listeDest = p_source.m_listeDest;
  m_etat = p_source.m_etat;
  m_predecesseur = p_source.m_predecesseur;
  m_cout = p_source.m_cout;
  m_precedent = p_source.m_precedent;
  m_suivant = p_source.m_suivant;
}

//! \brief Destructeur
//! \post Le sommet est detruit
template<typename Objet>
Graphe<Objet>::Sommet::~Sommet()
{
  Graphe<Objet>::Arc		*arcTmp = m_listeDest;
  Graphe<Objet>::Arc		*aDetruire;

  while (arcTmp)
    {
      aDetruire = arcTmp;
      arcTmp = arcTmp->m_suivDest;
      delete aDetruire;
    }
  delete arcTmp;
}

//! \brief Constructeur avec parametres
//! \param[in] dest L'adresse du sommet de destination
//! \param[in] cout Le cout de l'arc
//! \post Un arc est cree avec les parametres indiques
template<typename Objet>
Graphe<Objet>::Arc::Arc(Graphe<Objet>::Sommet *p_dest, int p_cout)
  : m_dest(p_dest), m_cout(p_cout), m_suivDest(NULL)
{
}

//! \brief Destructeur
//! \post Un arc est detruit
template<typename Objet>
Graphe<Objet>::Arc::~Arc()
{
}

/**
 * Constructeur & destructeur (Graphe)
 */

//! \brief Constructeur par defaut
//! \post Un graphe vide est cree
template<typename Objet>
Graphe<Objet>::Graphe()
  : m_nbSommets(0), m_listSommets(NULL)
{
}

//! \brief Constructeur par copie
//! \param[in] source La source du graphe a copier
//! \pre Il y a assez de memoire pour copier le graphe 'source'
//! \exception bad_alloc Il n'y a pas assez de memoire pour copier le graphe 'source'
template<typename Objet>
Graphe<Objet>::Graphe(const Graphe<Objet> &p_source)
  : m_nbSommets(p_source.m_nbSommets), m_listSommets(p_source.m_listSommets)
{
}

//! \brief Destructeur
//! \post Le graphe est detruit
template<typename Objet>
Graphe<Objet>::~Graphe()
{
  Graphe<Objet>::Sommet	*aDetruire;

  while (m_listSommets)
    {
      aDetruire = m_listSommets;
      m_listSommets = m_listSommets->m_suivant;
      delete aDetruire;
    }
  delete m_listSommets;
}

/**
 * Surcharge d'operateur =
 */

//! \brief Surcharge de l'operateur d'affectation
//! \pre Il doit y avoir assez de memoire
//! \post Le graphe a un contenu identique a 'source'
//! \exception bad_alloc S'il n'y a pas assez de memoire
//! \param[in] source Le graphe a copier
template<typename Objet>
const Graphe<Objet>		&Graphe<Objet>::operator=(const Graphe<Objet> &p_source)
{
  m_nbSommets = p_source.m_nbSommets;
  m_listSommets = p_source.m_listSommets;
  return *this;
}

/**
 * Ajout/Suppression de sommets et d'arcs
 */

//! \brief Ajout d'un sommet au graphe
//! \param[in] etiquette Les donnees du sommet a ajouter
//! \param[in] numero Le numero du sommet a ajouter
//! \pre Il y a assez de memoire pour ajouter un sommet
//! \pre Il n'y a aucun sommet avec le meme numero dans le graphe
//! \post Un sommet contenant les informations passees en parametre a ete ajoute au Graphe
//! \exception bad_alloc Il n'y a pas assez de memoire pour ajouter un sommet
//! \exception logic_error Il y a un sommet avec le meme numero dans le graphe
template<typename Objet>
void				Graphe<Objet>::ajouterSommet(int p_numero, const Objet &p_etiquette)
{
  if (sommetExiste(p_numero) == true)
    throw std::logic_error("logic_error - ajouter sommet");
  Graphe<Objet>::Sommet		*nouveauSommet = new Graphe<Objet>::Sommet(p_numero, p_etiquette);

  if (m_nbSommets == 0)
    m_listSommets = nouveauSommet;
  else
    {
      Graphe<Objet>::Sommet	*tmp = m_listSommets;
      while (tmp && tmp->m_suivant != NULL)
	tmp = tmp->m_suivant;
      tmp->m_suivant = nouveauSommet;
      nouveauSommet->m_precedent = tmp;
    }
  ++m_nbSommets;
}

//! \brief Enleve un sommet du graphe ainsi aue tous les arcs qui vont et partent de ce sommet
//! \param[in] numero Le numero du sommet a enlever
//! \pre Il y a un sommet avec le numero 'm_numero' dans le graphe
//! \post Le sommet identifie par 'm_numero' a ete enleve du graphe
//! \exception logic_error Il n'y a aucun sommet avec le numero 'm_numero' dans le graphe
//!
template<typename Objet>
void				Graphe<Objet>::enleverSommet(int p_numero)
{
  if (sommetExiste(p_numero) == false)
    throw std::logic_error("logic_error - enlever sommet");
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

//! \brief Ajout d'un arc au graphe
//! \param[in] numOrigine Le numero du sommet d'origine
//! \param[in] numDestination Le numero du sommet de destination
//! \param[in] cout Le cout de l'arc
//! \pre Les deux sommets doivent exister
//! \post Un arc a ete ajoute entre le sommet 'numOrginine' et 'numDestination'
//! \exception bad_alloc Pas assez de memoire pour allouer le nouvel arc
//! \exception logic_error Un des deux sommets n'existe pas
//! \exception logic_error Il y a deja un arc oriente entre ces deux sommets
template<typename Objet>
void				Graphe<Objet>::ajouterArc(int p_numOrigine, int p_numDestination, int p_cout)
{
  if (sommetExiste(p_numOrigine) == false
      || sommetExiste(p_numDestination) == false)
    throw std::logic_error("logic_error - ajouter arc (sommet non existant)");
  Graphe<Objet>::Arc		*nouvelArc = new Graphe<Objet>::Arc(_getSommet(p_numDestination), p_cout);
  Graphe<Objet>::Sommet		*tmp = m_listSommets;

  while (tmp)
    {
      if (tmp->m_numero == p_numOrigine)
	{
	  if (tmp->m_listeDest == NULL)
	    tmp->m_listeDest = nouvelArc;
	  else
	    {
	      Graphe<Objet>::Arc	*arcTmp = tmp->m_listeDest;
	      while (arcTmp && arcTmp->m_suivDest)
		{
		  if (arcTmp->m_dest->m_numero == p_numDestination)
		    throw std::logic_error("logic_error - ajouter arc (arc deja existant)");
		  arcTmp = arcTmp->m_suivDest;
		}
	      arcTmp->m_suivDest = nouvelArc;
	    }
	}
      tmp = tmp->m_suivant;
    }
}

//! \brief Enleve un arc du graphe
//! \param[in] numOrigine Le numero du sommet d'origine
//! \param[in] numDestination Le numero de destination
//! \pre Les deux sommets identifies par leurs numero soivent appartenir au graphe
//! \pre Un arc reliant les deux sommets doit exister
//! \post Le graphe contient un arc en moins, le graphe reste inchange sinon
//! \exception logic_error Un des deux sommet, ou les deux, n'existent pas
//! \excpetion logic_error Il n'y a pas d'arc entre les deux sommets
template<typename Objet>
void				Graphe<Objet>::enleverArc(int p_numOrigine, int p_numDestination)
{
  if (arcExiste(p_numOrigine, p_numDestination) == false)
    throw std::logic_error("logic_error - enlever arc");
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
}

/**
 * Donnees sur le graphe
 */

//! \brief Retourne le nombre de sommets dans la liste des sommets
//! \return Le nombre de sommet dans le graphe
//! \post Le graphe reste inchange
template<typename Objet>
int				Graphe<Objet>::nombreSommets() const
{
  return m_nbSommets;  
}

//! \brief Indique si la liste de sommet est vide ou non
//! \post Le graphe reste inchange
//! \return True si le graphe ne contient pas de sommets, false sinon
template<typename Objet>
bool				Graphe<Objet>::estVide() const
{
  return m_nbSommets == 0 ? true : false;
}

//! \brief Retourne la liste des numeros des sommets dans un vecteur d'entier
//! \return Un vector de type int qui contient une liste de toutes les etiquettes des sommets
//! \post Le graphe reste inchange
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

//! \brief Retourne la liste des etiquettes des sommets dans un vecteur
//! \return Un vector de type Objet qui contient une liste de toutes les etiquettes des sommets
//! \post Le graphe reste inchange
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

//! \brief Retourne le numero d'un sommet selon son etiquette
//! \pre Le sommet doit faire partie du graphe
//! \post Le graphe reste inchange
//! \exception logic_error Le sommet n'existe pas
//! \param[in] etiquette L'etiquette d'un sommet
//! \return Le numero du sommet recherche
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
  throw std::logic_error("logic_error - get numero sommet");
}

//! \brief Retourne l'existence d'un sommet
//! \post Le graphe reste inchange
//! \param[in] numero Le numero du sommet
//! \return true si le sommet existe, false sinon
template<typename Objet>
bool				Graphe<Objet>::sommetExiste(int p_numero) const
{
  Graphe<Objet>::Sommet		*tmp = m_listSommets;

  while (tmp != NULL)
    {
      if (tmp->m_numero == p_numero)
	  return true;
      tmp = tmp->m_suivant;
    }
  return false;
}

//! \brief Retourne l'etiquette d'un sommet
//! \pre Le sommet doit exister
//! \exception logic_error Il n'y a pas de sommets dans le graphe
//! \exception logic_error Le sommet n'existe pas
//! \param[in] numero Le numero du sommet
//! \return L'etiquette du sommet recherche
template<typename Objet>
Objet				Graphe<Objet>::getEtiquetteSommet(int p_numero) const
{
  if (sommetExiste(p_numero) == false)
    throw std::logic_error("logic_error - get etiquette");
  Graphe<Objet>::Sommet		*tmp = m_listSommets;

  while (tmp)
    {
      if (tmp->m_numero == p_numero)
	return tmp->m_etiquette;
      tmp = tmp->m_suivant;
    }
  throw std::logic_error("logic_error - get etiquette");
}

//! \brief Retourne l'ordre d'entree d'un sommet
//! \pre Le sommet doit exister
//! \post Le graphe reste inchange
//! \exception logic_error Le sommet n'existe pas
//! \param[in] numero Le numero du sommet
//! \return L'ordre d'entree d'un sommet
template<typename Objet>
int				Graphe<Objet>::ordreSortieSommet(int p_numero) const
{
  if (sommetExiste(p_numero) == false)
    throw std::logic_error("logic_error - ordre de sortie");
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
  throw std::logic_error("logic_error - ordre de sortie");
}

//! \brief Retourne l'ordre d'entree d'un sommet
//! \pre Le sommet doit exister
//! \post Le graphe reste inchange
//! \exception logic_error Le sommet n'existe pas
//! \param[in] numero Le numero du sommet
//! \return L'ordre d'entree d'un sommet
template<typename Objet>
int				Graphe<Objet>::ordreEntreeSommet(int p_numero) const
{
  if (sommetExiste(p_numero) == false)
    throw std::logic_error("logic_error - ordre d'entree");
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

//! \brief Retourne la liste des numeros des sommets adjacents au sommet passe en argument dans un vecteur d'entiers
//! \pre Le sommet doit appartenir au graphe
//! \post Le graphe reste inchange
//! \exception logic_error si le sommet n'existe pas
//! \param[in] numero Le numero du sommet dont on cherche les sommets adjacents
//! \return Un vector de type int qui contient une liste de tous les numeros des sommets adjecents au sommet demande
template<typename Objet>
std::vector<int>		Graphe<Objet>::listerSommetsAdjacents(int p_numero) const
{
  if (sommetExiste(p_numero) == false)
    throw std::logic_error("logic_error - lister sommets adjacents");
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

//! \brief Retourne l'existence d'un arc
//! \pre Les sommets doivent appartenir au graphe
//! \post Le graphe reste inchange
//! \exception logic_error L'un ou l'autre, ou les deux sommets ne font pas partie du graphe
//! \param[in] numOrigine Le numero du sommet d'origine
//! \param[in] numDestination Le numero du sommet de destination
//! \return True si un arc existe entre les deux sommets, sinon false
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

//! \brief Retourne le cout d'un arc passe en argument
//! \pre L'arc doit exister
//! \post Le graphe reste inchange
//! \exception logic_error Le sommet source et/ou destination n'existe pas
//! \exception logic_error L'arc n'existe pas
//! \param[in] numOrigine Le numero du sommet d'origine
//! \param[in] numDestintion Le numero du sommet de destination
//! \return Le cout de l'arc entre les deux sommets
template<typename Objet>
int				Graphe<Objet>::getCoutArc(int p_numOrigine,
							  int p_numDestination) const
{
  if (arcExiste(p_numOrigine, p_numDestination) == false)
    throw std::logic_error("logic_error - get cout arc");
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
  throw std::logic_error("logic_error - get cout arc");
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
std::ostream			&operator<<(std::ostream &p_out, const Graphe<Objet> &p_graphe)
{
  p_out << "Le graphe contient " << p_graphe.m_nbSommets << " sommet(s)" << std::endl;
  typename Graphe<Objet>::Sommet* vertex = p_graphe.m_listSommets;

  while (vertex != NULL)
    {
      p_out << "Sommet no " << vertex->m_numero << " " << vertex->m_etiquette << std::endl;

      typename Graphe<Objet>::Arc* arc = vertex->m_listeDest;
      if (arc != NULL)
	{
	  p_out << "Ce sommet a des liens vers le(s) sommet(s) : ";
	  while (arc->m_suivDest != NULL)
	    {
	      p_out << arc->m_dest->m_numero << "(" << arc->m_cout << "), ";
	      arc = arc->m_suivDest;
	    }
	  p_out << arc->m_dest->m_numero << "(" << arc->m_cout << ")";
	}
      p_out << std::endl;
      vertex = vertex->m_suivant;
    }
  return p_out;
}

/**
 * Fonctions plus complexes
 */

#define	MIN(x, y) (x < y ? x : y)

//! \brief Determiner la fermeture transitive du graphe
//! \pre Le graphe est correctement initialise
//! \post La fermeture transitive du graphe est retournee
//! \post Le graphe original reste inchange
//! \exception bad_alloc si pas assez de memoire application de l'algorithme de Floyd-Warshall
template<typename Objet>
Graphe<Objet>			Graphe<Objet>::fermetureGraphe() const
{
  Graphe<Objet>			graphe;
  int				matriceAdj[m_nbSommets][m_nbSommets];	

  graphe = *this;
  for (int i = 0; i < m_nbSommets; i++)
    for (int j = 0; j < m_nbSommets; j++)
      matriceAdj[i][j] = 10000000;

  for (int i = 0; i < m_nbSommets; i++)
    matriceAdj[i][i] = 0;

  for (int i = 0; i < m_nbSommets; i++)
    for (int j = 0; j < m_nbSommets; j++)
      if (_getCoutArc(i, j) != -1)
	matriceAdj[i][j] = _getCoutArc(i, j);

  for (int k = 0; k < m_nbSommets; k++)
    for (int i = 0; i < m_nbSommets; i++)
      for (int j = 0; j < m_nbSommets; j++)
	if (_getCoutArc(i, k) != -1
	    && _getCoutArc(k, j) != -1
	    && (_getCoutArc(i, k) + _getCoutArc(k, j)) < matriceAdj[i][j])
	  matriceAdj[i][j] = MIN(matriceAdj[i][j], _getCoutArc(i, k) + _getCoutArc(k, j)); 

  for (int i = 0; i < graphe.nombreSommets(); i++)
    {
      for (int j = 0; j < graphe.nombreSommets(); j++)
  	{
  	  if (graphe.arcExiste(i, j) == false
	      && matriceAdj[i][j] != 10000000
	      && i != j)
  	    graphe.ajouterArc(i, j, matriceAdj[i][j]);
  	  else if (graphe.arcExiste(i, j) == true
		   && graphe.getCoutArc(i, j) > matriceAdj[i][j])
  	    graphe._modifierCoutArc(i, j, matriceAdj[i][j]);
  	}
    }  

  std::cout << graphe;
  return graphe;
}

template<typename Objet>
void			Graphe<Objet>::_modifierCoutArc(int p_numOrigine,
								int p_numDestination, int p_cout)
{  
  Graphe<Objet>::Sommet		*tmp = _getSommet(p_numOrigine);

  while (tmp->m_listeDest)
    {
      if (tmp->m_listeDest->m_dest->m_numero == p_numDestination)
	{
	  tmp->m_listeDest->m_cout = p_cout;
	  break;
	}
      tmp->m_listeDest = tmp->m_listeDest->m_suivDest;
    }
}

//! \brief Determine si le graphe est fortement connexe ou non
//! \post renvoie true si le graphe est fortement connexe, sinon renvoie false
//! \return true si fortement connexe, false sinon
template<typename Objet>
bool			Graphe<Objet>::estFortementConnexe() const
{
  return false;
}

//! \brief Determine les composantes fortement connexes et les memorise dans un conteneur passe en parametre
//! \pre Il y a assez de memoire pour placer les composantes fortement connexes dans 'composantes'
//! \post Les composantes fortement connexes du graphe sont placees dans 'composantes'
//! \exception bad_alloc Il n'y a pas assez de memoire pour placer les composantes fortements connexes dans 'composantes'
//! \param[in] composantes
template<typename Objet>
void			Graphe<Objet>::getComposantesFortementConnexes(std::vector<std::vector<Objet> > &p_composantes) const
{

}

//! \brief Trouve le plus court chemin entre deux point en utlisant l'algorithme de Bellman-Ford et le retourne
//! \pre Il y a assez de memoire pour placer les composantes du chemin 'chemin'
//! \post Le cout total est retourne, -1 s'il n'y a pas de chemin
//! \post Le graphe original reste inchange
//! \post La liste des etiquettes des sommets a parcourir est retournee dans le vector 'chemin'
//! \exception bad_alloc Il n'y a pas assez de memoire pour placer le chemin dans 'chemin'
//! \exception logic_error Le sommet d'origine ou de destination n'existe pas
//! \param[in] eOrigine l'etiquette du sommet d'origine
//! \param[in] eDestination l'etiquette du sommet de destination
//! \param[in] chemin Un vector de type etiquette aui contient le chemin du parcours
//! \return Le cout du parcours trouve
template<typename Objet>
int			Graphe<Objet>::bellmanFord(const Objet &p_eOrigine,
						   const Objet &p_eDestination,
						   std::vector<Objet> &p_chemin)
{
  return -1;
}

//! \brief Trouve le plus court chemin entre deux points en utlisant l'algorithme de Dijkstra et le retourne
//! \pre Il y a assez de memoire pour placer les composantes du chemin 'chemin'
//! \post Le temps de transmission total est retourne, -1 s'il n'y a pas de chemin
//! \post Le graphe original reste inchange
//! \post La liste des sommets a parcourir est retournee dans le vector 'chemin'
//! \exception bad_alloc Il n'y a pas assex de memoire pour placer le chemin dans 'chemin'
//! \exception logic_error Le sommet d'origine ou de destination n'existe pas
//! \param[in] eOrigine Nom du sommet d'origine
//! \param[in] eDestination Nom du sommet de destination
//! \param[in] chemin Un vector de type string qui contient le chemin du parcours
//! \return Le cout du parcours trouve
template<typename Objet>
int			Graphe<Objet>::dijkstra(const Objet &p_eOrigine,
						const Objet &p_eDestination,
						std::vector<Objet> &p_chemin)
{
  return -1;
}

//! \brief Trouve les points d'articulation du graphe et les retourne
//! \pre Il y a assez de memoire pour placer les sommets dans 'sommets'
//! \post La liste de tous les sommets d'articulation sont retournes dans le vector 'sommets'
//! \post Le graphe original reste inchange
//! \param[in] sommets Un vector de type Objet qui contient tous les sommets d'articulation
template<typename Objet>
void			Graphe<Objet>::getPointsArticulation(std::vector<Objet> &p_sommets)
{

}

/**
 * Methodes auxiliaires
 */

//! \brief Initialise les sommets du graphe dans le but d'utiliser des methodes pour trouver des chemins
//! \pre Le sommet d'origine et le sommet de destination existent
//! \post Le chemin a ete correctement initialise
//! \exception logic_error Le sommet d'origine ou de destination n'existe pas
//! \param[in] eOrigine l'etiquette du sommet d'origine
//! \param[in] eDestination l'etiquette du sommet de destination
//! \param[in] origine le sommet d'origine
//! \param[in] destination le sommet de destination
template<typename Objet>
void				Graphe<Objet>::_initPathFinding(const Objet &p_eOrigine,
								const Objet &p_eDestination,
								Sommet *&p_origine,
								Sommet *&p_destination)
{

}

//! \brief Trouve l'adresse d'un sommet a partir de son numero
//! \post L'adresse du sommet recherche est retournee
//! \param[in] numero Le numero du sommet
template<typename Objet>
typename Graphe<Objet>::Sommet		*Graphe<Objet>::_getSommet(int p_numero) const
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

//! \brief Trouve l'adresse d'un arc entre deux sommets
//! \post L'adresse de l'arc recherche est retournee, 0 si aucun arc n'a ete trouve
//! \param[in] origine L'adresse du sommet d'origine
//! \param[in] destination L'adresse du sommetde destination
//! \return L'adresse de l'arc trouve entre le sommet d'origine et le sommet de destination
template<typename Objet>
typename Graphe<Objet>::Arc		*Graphe<Objet>::_getArc(Sommet *p_sommet1, Sommet *p_sommet2) const
{
  Graphe<Objet>::Sommet		*tmp = getSommet(p_sommet1);

  while (tmp->m_listeDest)
    {
      if (tmp->listeDest->m_dest->m_numero == p_sommet2)
	return tmp->listeDest;
      tmp->listeDest = tmp->m_listeDest->m_suivDest;
    }
  return NULL;
}

//! \brief Retourne le cout d'un arc passe en argument
//! \pre L'arc doit exister
//! \post Le graphe reste inchange
//! \param[in] numOrigine Le numero du sommet d'origine
//! \param[in] numDestintion Le numero du sommet de destination
//! \return Le cout de l'arc entre les deux sommets, -1 si il n'existe pas
template<typename Objet>
int				Graphe<Objet>::_getCoutArc(int p_numOrigine,
							  int p_numDestination) const
{
  if (arcExiste(p_numOrigine, p_numDestination) == false)
    return -1;
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
  return -1;
}

//! \file	Graphe.h
//! \brief	D�finition de l'interface pour un graphe g�n�rique
//! \author	abder, thierry
//! \version	2.0 graphe template
//! \date	octobre 2013

#include <iostream>
#include <fstream>		// Pour les fichiers
#include <stdexcept>
#include <string>
#include <vector>

#ifndef GRAPHE__H
#define GRAPHE__H

//! \class	Graphe
//! \brief	Classe repr�sentant un graphe orient�, color� dont les �tiquettes sont des comparables
template<typename Objet>
class Graphe
{
private:

  // �������������������������������������������������������������������������������������������������
  //	Classes internes
  // _________________________________________________________________________________________________


  class Arc;

  //! \class	Sommet
  //! \brief	Classe repr�sentant un sommet dans un graphe
  class Sommet
  {
  public:

    Sommet();
    Sommet(int p_numero, const Objet &p_etiquette);
    Sommet(Sommet *p_source);

    ~Sommet();

    int		m_numero; /**< Le num�ro du sommet */
    Objet	m_etiquette;

    Arc		*m_listeDest; /**< La liste des arcs entre le sommet et les sommets qui lui sont adjacents */

    bool	m_etat; /**< Pour marquer un routeur */
    Sommet	*m_predecesseur; /**< Pour Dijkstra et Bellman-Ford */
    int		m_cout; /**< Pour Dijkstra et Bellman-Ford */

    Sommet	*m_precedent; /**< le sommet pr�c�dent dans la liste des sommets */
    Sommet	*m_suivant; /**< Le prochain sommet dans la liste */
  };

  //! \class	Arc
  //! \brief	Classe interne repr�sentant un arc entre deux sommets dans le graphe
  class Arc
  {
  public:

    Arc(Sommet *p_dest, int p_cout);
    ~Arc();

    Sommet	*m_dest; /**< Un pointeur sur le sommet de destination */
    int		m_cout; /**< Le co�t entre les deux sommets reli�s par l'arc */
    Arc		*m_suivDest; /**< Le prochain sommet de destination */
  };

public:

  // �������������������������������������������������������������������������������������������������
  //	Constructeurs et destructeur
  // _________________________________________________________________________________________________


  Graphe();
  Graphe(const Graphe &p_source);

  ~Graphe();

  // �������������������������������������������������������������������������������������������������
  //	Ajout/suppression de sommets et d'arcs
  // _________________________________________________________________________________________________

  void		ajouterSommet(int p_numero, const Objet &p_etiquette);
  void		enleverSommet(int p_numero);

  void		ajouterArc(int p_numOrigine, int p_numDestination, int p_cout);
  void		enleverArc(int p_numOrigine, int p_numDestination);

  // �������������������������������������������������������������������������������������������������
  //	Donn�es sur le graphe (incluant listes de sommets)
  // _________________________________________________________________________________________________

  int			nombreSommets() const;
  bool			estVide() const;
  std::vector<int>	listerSommets() const;
  std::vector<Objet>	listerEtiquetteSommets() const;

  // �������������������������������������������������������������������������������������������������
  //	Trouver num�ro sommet
  // _________________________________________________________________________________________________

  int			getNumeroSommet(const Objet& etiquette) const ;

  // �������������������������������������������������������������������������������������������������
  //	Donn�es � propos des sommets
  // _________________________________________________________________________________________________

  bool			sommetExiste(int p_numero) const;
  Objet			getEtiquetteSommet(int p_numero) const ;
  int			ordreSortieSommet(int p_numero) const ;
  int			ordreEntreeSommet(int p_numero) const ;
  std::vector<int>	listerSommetsAdjacents(int p_numeroSommetsAdjacents) const ;

  // �������������������������������������������������������������������������������������������������
  //	Donn�es � propos des arcs
  // _________________________________________________________________________________________________

  bool			arcExiste(int p_numOrigine, int p_numDestination) const;
  int			getCoutArc(int p_numOrigine, int p_numDestination) const;

  // �������������������������������������������������������������������������������������������������
  //	Surcharge d'op�rateurs
  // _________________________________________________________________________________________________

  const Graphe		&operator=(const Graphe &p_source);
  template<class U>
  friend std::ostream	&operator<<(std::ostream &p_out, const Graphe<U> &p_g);

  // �������������������������������������������������������������������������������������������������
  //	Fonctions plus complexes
  // _________________________________________________________________________________________________


  Graphe		fermetureGraphe() const ;
  bool			estFortementConnexe() const;
  void			getComposantesFortementConnexes(std::vector<std::vector<Objet> > &p_composantes) const;
  int			bellmanFord(const Objet &p_eOrigine, const Objet &p_eDestination,
				    std::vector<Objet> &p_chemin);
  int			dijkstra(const Objet &p_eOrigine, const Objet &p_eDestination,
				 std::vector<Objet> &p_chemin);
  void			getPointsArticulation(std::vector<Objet> &p_sommets);

private:

  // �������������������������������������������������������������������������������������������������
  //	Propri�t�s priv�es
  // _________________________________________________________________________________________________

  int			m_nbSommets; /**< Le nombre de sommets dans le graphe */
  Sommet		*m_listSommets; /**< Liste des sommets du graphe */

  // �������������������������������������������������������������������������������������������������
  //	M�thodes auxiliaires (getters)
  // _________________________________________________________________________________________________

  Sommet		*_getSommet(int p_numero) const;
  Arc			*_getArc(Sommet *p_sommet1, Sommet *p_sommet2) const;

  // �������������������������������������������������������������������������������������������������
  //	M�thodes auxiliaires (destruction + copie)
  // _________________________________________________________________________________________________

  void			_detruireGraphe();
  void			_copierGraphe(const Graphe &p_source);
  void			_enleverSommet(Sommet *p_sommetAEnlever);

  // �������������������������������������������������������������������������������������������������
  //	M�thodes auxiliaires (path finding)
  // _________________________________________________________________________________________________

  void			_initPathFinding(const Objet &p_eOrigine, const Objet &p_eDestination,
					 Sommet *&p_origine, Sommet *&p_destination);
  void			_recupererChemin(Sommet *p_destination, std::vector<Objet> &p_chemin);

};

#include "Graphe.hpp"
#endif

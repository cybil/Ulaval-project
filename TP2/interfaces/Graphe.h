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

		Sommet(int numero, const Objet& Etiquette);
		Sommet(Sommet * source);

		~Sommet();

		int m_numero; /**< Le num�ro du sommet */
		Objet m_etiquette;

		Arc * m_listeDest; /**< La liste des arcs entre le sommet et les sommets qui lui sont adjacents */

		bool m_etat; /**< Pour marquer un routeur */
		Sommet * m_predecesseur; /**< Pour Dijkstra et Bellman-Ford */
		int m_cout; /**< Pour Dijkstra et Bellman-Ford */

		Sommet *m_precedent; /**< le sommet pr�c�dent dans la liste des sommets */
		Sommet *m_suivant; /**< Le prochain sommet dans la liste */
	};

	//! \class	Arc
	//! \brief	Classe interne repr�sentant un arc entre deux sommets dans le graphe
	class Arc
	{
	public:

		Arc(Sommet * dest, int cout);
		~Arc();

		Sommet * m_dest; /**< Un pointeur sur le sommet de destination */
		int m_cout; /**< Le co�t entre les deux sommets reli�s par l'arc */
		Arc * m_suivDest; /**< Le prochain sommet de destination */
	};

public:

	// �������������������������������������������������������������������������������������������������
	//	Constructeurs et destructeur
	// _________________________________________________________________________________________________


	Graphe();
	Graphe(const Graphe &source);

	~Graphe();

	// �������������������������������������������������������������������������������������������������
	//	Ajout/suppression de sommets et d'arcs
	// _________________________________________________________________________________________________

	void ajouterSommet(int numero, const Objet& etiquette);
	void enleverSommet(int numero);

	void ajouterArc(int numOrigine, int numDestination, int cout);
	void enleverArc(int numOrigine, int numDestination);

	// �������������������������������������������������������������������������������������������������
	//	Donn�es sur le graphe (incluant listes de sommets)
	// _________________________________________________________________________________________________

	int nombreSommets() const;
	bool estVide() const;
	std::vector<int> listerSommets() const;
	std::vector<Objet> listerEtiquetteSommets() const;

	// �������������������������������������������������������������������������������������������������
	//	Trouver num�ro sommet
	// _________________________________________________________________________________________________

	int getNumeroSommet(const Objet& etiquette) const ;

	// �������������������������������������������������������������������������������������������������
	//	Donn�es � propos des sommets
	// _________________________________________________________________________________________________

	bool sommetExiste(int numero) const;
	Objet getEtiquetteSommet(int numero) const ;
	int ordreSortieSommet(int numero) const ;
	int ordreEntreeSommet(int numero) const ;
	std::vector<int> listerSommetsAdjacents(int numeroSommetsAdjacents) const ;

	// �������������������������������������������������������������������������������������������������
	//	Donn�es � propos des arcs
	// _________________________________________________________________________________________________

	bool arcExiste(int numOrigine, int numDestination) const;
	int getCoutArc(int numOrigine, int numDestination) const;

	// �������������������������������������������������������������������������������������������������
	//	Surcharge d'op�rateurs
	// _________________________________________________________________________________________________

	const Graphe& operator =(const Graphe& source);
	template<class U> friend std::ostream& operator <<(std::ostream& out,
			const Graphe<U>& g);

	// �������������������������������������������������������������������������������������������������
	//	Fonctions plus complexes
	// _________________________________________________________________________________________________


	Graphe fermetureGraphe() const ;
	bool estFortementConnexe() const;
	void getComposantesFortementConnexes(
			std::vector<std::vector<Objet> > & composantes) const;
	int bellmanFord(const Objet& eOrigine, const Objet& eDestination,
			std::vector<Objet> & chemin);
	int dijkstra(const Objet& eOrigine, const Objet& eDestination,
			std::vector<Objet> & chemin);
	void getPointsArticulation(std::vector<Objet> & sommets);

private:

	// �������������������������������������������������������������������������������������������������
	//	Propri�t�s priv�es
	// _________________________________________________________________________________________________

	int nbSommets; /**< Le nombre de sommets dans le graphe */
	Sommet * listSommets; /**< Liste des sommets du graphe */

	// �������������������������������������������������������������������������������������������������
	//	M�thodes auxiliaires (getters)
	// _________________________________________________________________________________________________

	Sommet *_getSommet(int numero) const;
	Arc * _getArc(Sommet * sommet1, Sommet * sommet2) const;

	// �������������������������������������������������������������������������������������������������
	//	M�thodes auxiliaires (destruction + copie)
	// _________________________________________________________________________________________________

	void _detruireGraphe();
	void _copierGraphe(const Graphe &source);
	void _enleverSommet(Sommet * sommetAEnlever);

	// �������������������������������������������������������������������������������������������������
	//	M�thodes auxiliaires (path finding)
	// _________________________________________________________________________________________________

	void _initPathFinding(const Objet& eOrigine, const Objet& eDestination,
			Sommet * & origine, Sommet * & destination);
	void _recupererChemin(Sommet * destination, std::vector<Objet> & chemin);

};
#include "Graphe.hpp"
#endif

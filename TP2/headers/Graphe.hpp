//! \file Graphe.hpp
//! \brief Impl�mentation des m�thodes d�finies dans Graphe.h
//! \author theud1
//! \version 0.1 graphe g�n�rique
//! \date 2013-10-03
#include "Graphe.h"
//vous pouvez inclure d'autres librairies si c'est n�cessaire


using namespace std;

//! \brief		Surcharge de l'op�rateur de sortie.
//! \param[in]	p_out		Le flux de sortie.
//! \param[in]	p_graphe		Le graphe � afficher.
//! \return	Le flux de sortie.
//! \pre		l'�tiquette est un objet comparable, l'op�rateur << y est surcharg�
//! \post		Le nombre de sommets du graphe sera affich�
//! \post		Pour chaque sommet, son num�ro, son �tiquette seront affich�s
//! \post		Pour chaque sommet, tous ses liens, le num�ro des voisins, seront affich�s

template<typename Objet>
ostream& operator <<(ostream& p_out, const Graphe<Objet>& p_graphe)
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

//� compl�ter par les autres m�thodes demand�es sur le type Graphe

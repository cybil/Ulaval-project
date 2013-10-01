//! \file Colonne.cpp
//! \brief Le code des methodes de la classe Colonne.
//! \author Cybil Bourely - CMBOU5
//! \version 0.1
//! \date 26 septembre 2013
//! Implémentation de la classe ColonneCarte

#include <iostream>
#include "Colonne.h"

ColonneCarte::ColonneCarte()
{
  m_nbCartesVisibles = 1;  
}

ColonneCarte::ColonneCarte(const ColonneCarte &p_rhs)
{

}

ColonneCarte::~ColonneCarte()
{
}

void		ColonneCarte::initColonneCarte(Liste<Cartes> &p_listeCartes)
{
  m_lesCartes = p_listeCartes;
}

void		ColonneCarte::ajoute(const Carte &p_carte)
{
  if (p_carte <= m_lesCartes.last()) // voir Liste
    {
      m_lesCartes.ajouter(p_carte);
      ++m_nbCartesVisibles;
    }
}

void		ColonneCarte::deplacePaquet(ColonneCarte &p_destination, int p_nombreCartes)
{
  
}

void		ColonneCarte::supprimerDerniereCarte()
{
  m_lesCartes.enlever();
  --m_nbCartesVisibles;
}

//************
// Accesseurs
//************

int		ColonneCarte::getNbCartesVisibles() const
{
  return m_nbCartesVisibles;
}

int		ColonneCarte::getTailleListe() const
{
  return m_lesCartes.taille();
}


std::ostream	&operator<<(std::ostream &p_f, const ColonneCarte &p_colonne)
{
  for (int i = 0; i < (p_colonne.getTailleListe() - p_colonne.getNbCartesVisibles()); i++)
    p_f << *;
  p_f << p_colonne.m_lesCartes;
  return p_f;
}



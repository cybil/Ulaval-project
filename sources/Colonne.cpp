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

ColonneCarte::~ColonneCarte()
{
}

void		ColonneCarte::initColonneCarte(Liste<Cartes> &p_listeCartes)
{
  m_lesCartes = p_listeCartes;
}

void		ColonneCarte::ajoute(const Cartes &p_carte)
{
  if (p_carte <= m_lesCartes.element(m_lesCartes.taille()))
    {
      m_lesCartes.ajouter(p_carte, m_lesCartes.taille() + 1);
      ++m_nbCartesVisibles;
      return ;
    }
  throw std::runtime_error("runtime_error AJOUTER");
}

void		ColonneCarte::deplacePaquet(ColonneCarte &p_destination, int p_nombreCartes)
{
  Liste<Cartes>	tmp;

  int	i = m_lesCartes.taille();
  int	j = (m_lesCartes.taille() - p_nombreCartes);
  while (i > j)
    {
      tmp.ajouter(m_lesCartes.element(i), tmp.taille() + 1);
      supprimerDerniereCarte();
      --i;
    }
  for (int i = tmp.taille(); i > 0; i--)
    p_destination.ajoute(tmp.element(i));
}

void		ColonneCarte::supprimerDerniereCarte()
{
  m_lesCartes.enleverPos(m_lesCartes.taille());
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

const Cartes	&ColonneCarte::getCarteAPosition(int p_pos) const
{
  return m_lesCartes.element(p_pos);
}

std::ostream	&operator<<(std::ostream &p_f, const ColonneCarte &p_colonne)
{
  for (int i = 0; i < p_colonne.getTailleListe() - p_colonne.getNbCartesVisibles(); i++)
    p_f << " ? ";
  for (int i = (p_colonne.getTailleListe() - p_colonne.getNbCartesVisibles()); i < p_colonne.getTailleListe(); i++)
    p_f << p_colonne.getCarteAPosition(i + 1);
  return p_f;
}




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

int		ColonneCarte::getNbCartesVisibles() const
{
  return m_nbCartesVisibles;
}

std::ostream	&operator<<(std::ostream &p_f, const ColonneCarte &p_colonne)
{

}



/**
 * \file Colonne.h
 * \brief Classe Définissant le type ColonneCarte
 * \author Cybil Bourely - CMBOU5
 * \version 0.1
 * \date 26 septembre 2013
 *
 * Description de la classe ColonneCarte
 */

#include "Liste.h"
#include "Cartes.h"

class ColonneCarte
{
public:
  ColonneCarte();
  ~ColonneCarte();

  void		initColonneCarte(Liste<Cartes> &);
  void		ajoute(const Cartes &);
  void		deplacePaquet(ColonneCarte &, int);
  void		supprimerDerniereCarte();
  int		getNbCartesVisibles() const;
  int		getTailleListe() const;
  const Cartes	&getCarteAPosition(int) const;

private:
  Liste<Cartes>		m_lesCartes;
  int			m_nbCartesVisibles;

  friend std::ostream	&operator<<(std::ostream &, const ColonneCarte &);

};

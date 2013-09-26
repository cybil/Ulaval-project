
#include "Liste.h"
#include "Cartes.h"

class Liste;

class ColonneCarte
{
public:
  ColonneCarte();
  ColonneCarte(const ColonneCarte &);
  ~ColonneCarte();

  void		initColonneCarte(Liste<Cartes> &);
  void		ajoute(const Carte &);
  void		deplacePaquet(ColonneCarte &, int);
  void		supprimerDerniereCarte();
  int		getNbCartesVisibles() const;

private:
  Liste<Cartes>		m_lesCartes;
  int			m_nbCartesVisibles;

  friend std::ostream	&operator<<(std::ostream &, const ColonneCarte &);

};

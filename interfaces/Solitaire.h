
#include <string>
#include "Colonne.h"
#include "File.h"
#include "Pile.h"

class Solitaire
{
public:
  Solitaire();
  ~Solitaire();

  void			avancerTalon();
  void			deplacerColonneAColonne(int p_colonneSource,
  						int p_colonneDestination, int p_nbCartes);
  void			deplacerTalonAColonne(int p_colonneDestination);
  void			deplacerTalonAPile(int p_PileDestination);
  void			deplacerColonneAPile(int p_colonneSource, int p_pileDestination);
  bool			verifieGagne() const;
  std::string		reqEtatJeu() const;

private:

  File<Cartes>		m_talon;
  ColonneCarte		m_colonnes[7];
  Pile<Cartes>		m_piles[4];
};

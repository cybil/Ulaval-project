

class Cartes
{
 public:
  enum Couleur
    {
      ROUGE,
      NOIR
    };
  enum Sorte
    {
      COEUR,
      PIQUE,
      CARREAU,
      TREFLE
    };
  enum Valeur
    {
      AS = 1,
      DEUX,
      TROIS,
      QUATRE,
      CINQ,
      SIX,
      SEPT,
      HUIT,
      NEUF,
      DIX,
      VALET,
      DAME,
      ROI
    };

  Cartes();
  Cartes(const Valeur, const Sorte);
  Cartes(const Cartes &);
  ~Cartes();

  const Cartes	&operator=(const Cartes &);
  // Renvoie true si les deux cartes ont la meme couleur
  bool		operator==(const Cartes &) const;
  // Renvoie true si la carte courante est la carte suivante de celle passee en parametre (dix < valet)
  bool		operator<(const Cartes &) const;
  // Renvoie true si la carte courante est la carte precedente de celle passee en parametre (dix < valet)
  bool		operator>(const Cartes &) const;

  bool		operator>=(const Cartes &) const;
  bool		operator<=(const Cartes &) const;
  bool		isAs() const;

 private:
  Couleur	couleur() const;

  Sorte		m_sorte;
  Valeur	m_valeur;

  // Affiche une carte sous la forme Valeur'Sorte (10'CO)
  friend std::ostream	&operator<<(std::ostream &, const Cartes &);
};

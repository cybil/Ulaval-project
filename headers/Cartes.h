
class Cartes
{
 public:
  Cartes();
  Cartes(const Cartes &);
  ~Cartes();

  const Cartes	&operator=(const Cartes &)
  // Renvoie true si les deux cartes ont la meme couleur
  bool		operator==(const Cartes &) const;
  // Renvoie true si la carte courante est la carte suivante de celle passee en parametre (dix < valet)
  bool		operator<(const Cartes &) const;

  // Getters
  Sorte		getSorte() const;
  Valeur	getValeur() const;    

 private:
  enum Sorte
    {
      COEUR = "CO",
      CARREAU = "CA",
      PIQUE = "PI",
      TREFLE = "TR"
    };
  enum Valeur
    {
      AS = "1",
      DEUX = "2",
      TROIS = "3",
      QUATRE = "4",
      CINQ = "5",
      SIX = "6",
      SEPT = "7",
      HUIT = "8",
      NEUF = "9",
      DIX = "10",
      VALET = "V",
      DAME = "D",
      ROI = "R"
    };

  Sorte		m_sorte;
  Valeur	m_valeur;

  // Affiche une carte sous la forme Valeur'Sorte (10'CO)
  friend std::ostream	operator<<(std::ostream &, const Cartes &);
};

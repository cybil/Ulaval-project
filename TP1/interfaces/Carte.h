/**
 * \file Carte.h
 * \brief Classe définissant le type Carte
 * \author Cybil Bourely - CMBOU5
 * \version 0.1
 * \date 02 octobre 2013
 *
 * Représentation de la classe Carte 
 */

/** 
 * \class Carte
 *
 * \brief classe représentant une Carte
 *
 *  La classe gère une carte.
 */
class Carte
{
 public:
  /**
   * \enum Couleur
   *
   * \brief enum representant les deux couleurs de carte du jeu 
   */
  enum Couleur
    {
      ROUGE,
      NOIR
    };
  /**
   * \enum Sorte
   *
   * \brief enum representant les differentes sortes de carte 
   */
  enum Sorte
    {
      COEUR,
      PIQUE,
      CARREAU,
      TREFLE
    };
  /**
   * \enum Valeur
   *
   * \brief enum representant les differentes valeurs de carte 
   */
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

  //*****************************
  // Constructeurs & Destructeur
  //*****************************

  //! \brief Constructeur par defaut
  //! \post Une instance de la classe Carte est cree
  Carte();

  //! \brief Constructeur avec initialisation des attributs
  //! \post Une instance de la classe Carte est initialisee
  Carte(const Valeur, const Sorte);

  //! \brief Constructeur par copie
  //! \post Une copie profonde la carte source
  Carte(const Carte &);
  ~Carte();

  //***********************
  //Surcharge d'opérateurs
  //***********************

  //! \brief Surcharge l'operateur =
  //! \post une copie d'une carte est retournee
  const Carte	&operator=(const Carte &);

  //! \brief Surcharge l'operateur ==
  //! \return TRUE si les deux cartes sont identiques
  bool		operator==(const Carte &) const;

  //! \brief Surcharge l'operateur <
  //! \return TRUE si la carte courante est la valeur suivante de celle en parametre sinon FALSE
  bool		operator<(const Carte &) const;

  //! \brief Surcharge l'operateur >
  //! \return TRUE si la carte courante est la valeur precedente de celle en parametre sinon FALSE
  bool		operator>(const Carte &) const;

  //! \brief Surcharge l'operateur >=
  //! \return TRUE si la carte courante peut etre superposee a celle en parametre dans les Piles
  bool		operator>=(const Carte &) const;

  //! \brief Surcharge l'operateur <=
  //! \return TRUE si la carte courante peut etre superposee a celle en parametre dans les Colonnes
  bool		operator<=(const Carte &) const;

  //! \brief Verifie si la carte est un AS
  //! return TRUE si la carte est un AS sinon FALSE
  bool		isAs() const;
 
  //! \brief Verifie si la carte est un ROI
  //! return TRUE si la carte est un ROI sinon FALSE
  bool		isRoi() const;

 private:

  //! \brief Renvoie la couleur de la carte
  //! \post La valeur ROUGE ou NOIR est renvoyee selon la carte
  Couleur	couleur() const;

  Sorte		m_sorte;
  Valeur	m_valeur;

  //! \brief Surcharge de l'operateur << affichage sous la forme [valeur]'[sorte]
  //! \param[in] f est une reference sur le flux utilise
  //! \param[in] carte est une reference constante sur la carte que l'on veut afficher
  //! \post Un flux de sortie correspondant a la liste est retourne
  friend std::ostream	&operator<<(std::ostream &, const Carte &);
};


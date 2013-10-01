
#include <iostream>
#include <string>
#include "Cartes.h"

//*****************************
// Constructeurs & Destructeur
//*****************************

//! \brief Constructeur par defaut
//! \post Une instance de la classe Cartes est cree
Cartes::Cartes()
{
}

//! \brief Constructeur avec initialisation des attributs
//! \post Une instance de la classe Cartes est initialisee
Cartes::Cartes(const Cartes::Valeur p_valeur, const Cartes::Sorte p_sorte)
{
  m_valeur = p_valeur;
  m_sorte = p_sorte;
}

//! \brief Constructeur par copie
//! \post Une copie profonde la carte source
Cartes::Cartes(const Cartes &p_rhs)
{
  m_sorte = p_rhs.m_sorte;
  m_valeur = p_rhs.m_valeur;
}

//! \brief Destructeur par defaut
//! \post L'instance de Cartes est detruite
Cartes::~Cartes()
{
}


//***********************
//Surcharge d'opérateurs
//***********************

//! \brief Surcharge l'operateur =
//! \post une copie d'une carte est retournee
const Cartes	&Cartes::operator=(const Cartes &p_rhs)
{
  m_sorte = p_rhs.m_sorte;
  m_valeur = p_rhs.m_valeur;
  return *this;
}

//! \brief Surcharge l'operateur ==
//! \return TRUE si les deux cartes ont la meme sorte sinon FALSE
bool		Cartes::operator==(const Cartes &p_carte) const
{
  return m_sorte == p_carte.m_sorte ? true : false;
}

//! \brief Surcharge l'operateur <
//! \return TRUE si la carte courante est la valeur suivante de celle en parametre sinon FALSE
bool		Cartes::operator<(const Cartes &p_carte) const
{
  return m_valeur == p_carte.m_valeur - 1 ? true : false;
}

//! \brief Surcharge l'operateur >
//! \return TRUE si la carte courante est la valeur precedente de celle en parametre sinon FALSE
bool		Cartes::operator>(const Cartes &p_carte) const
{
  return m_valeur == p_carte.m_valeur + 1 ? true : false;
}

//! \brief Surcharge l'operateur >=
//! \return TRUE si la carte courante peut etre superposee a celle en parametre dans les Piles
bool		Cartes::operator>=(const Cartes &p_carte) const
{
  if (*this == p_carte && *this > p_carte)
    return true;
  return false;
}

//! \brief Surcharge l'operateur <=
//! \return TRUE si la carte courante peut etre superposee a celle en parametre dans les Colonnes
bool		Cartes::operator<=(const Cartes &p_carte) const
{
  if (p_carte.couleur() != couleur() && *this < p_carte)
    return true;
  return false;
}


//***********
// Accesseur
//***********

bool		Cartes::isAs() const
{
  return m_valeur == Cartes::AS ? true : false;
}

//*********
// Private
//*********

//! \brief Renvoie la couleur de la carte
//! \post La valeur ROUGE ou NOIR est renvoyee selon la carte
Cartes::Couleur		Cartes::couleur() const
{
  return (m_sorte == Cartes::COEUR) || (m_sorte == Cartes::CARREAU) ? Cartes::ROUGE : Cartes::NOIR;
}

//*********
// Friend
//*********

//! \brief Surcharge de l'operateur << affichage sous la forme [valeur]'[sorte]
//! \param[in] f est une reference sur le flux utilise
//! \param[in] carte est une reference constante sur la carte que l'on veut afficher
//! \post Un flux de sortie correspondant a la liste est retourne
std::ostream	&operator<<(std::ostream &p_f, const Cartes &p_carte)
{
  std::string	tab[] =
    {
      "CO",
      "PI",
      "CA",
      "TR"
    };
  if (p_carte.m_valeur == Cartes::VALET)
    p_f << "V'";
  else if (p_carte.m_valeur == Cartes::DAME)
    p_f << "D'";
  else if (p_carte.m_valeur == Cartes::ROI)
    p_f << "R'";
  else
      p_f << p_carte.m_valeur << "'";
  p_f << tab[p_carte.m_sorte];
  return p_f;
}

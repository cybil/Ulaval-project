//! \file Carte.cpp
//! \brief Le code des opérateurs de carte.
//! \author Cybil Bourely - CMBOU5
//! \version 1.0
//! \date 02 octobre 2013
//!
//! Implémentation de la classe Carte


#include <iostream>
#include <string>
#include "Carte.h"

//*****************************
// Constructeurs & Destructeur
//*****************************

//! \brief Constructeur par defaut
//! \post Une instance de la classe Carte est cree
Carte::Carte()
{
}

//! \brief Constructeur avec initialisation des attributs
//! \post Une instance de la classe Carte est initialisee
Carte::Carte(const Carte::Valeur p_valeur, const Carte::Sorte p_sorte)
{
  m_valeur = p_valeur;
  m_sorte = p_sorte;
}

//! \brief Constructeur par copie
//! \post Une copie profonde la carte source
Carte::Carte(const Carte &p_rhs)
{
  m_sorte = p_rhs.m_sorte;
  m_valeur = p_rhs.m_valeur;
}

//! \brief Destructeur par defaut
//! \post L'instance de Carte est detruite
Carte::~Carte()
{
}


//***********************
//Surcharge d'opérateurs
//***********************

//! \brief Surcharge l'operateur =
//! \post une copie d'une carte est retournee
const Carte	&Carte::operator=(const Carte &p_rhs)
{
  m_sorte = p_rhs.m_sorte;
  m_valeur = p_rhs.m_valeur;
  return *this;
}

//! \brief Surcharge l'operateur ==
//! \return TRUE si les deux cartes sont identiques
bool		Carte::operator==(const Carte &p_carte) const
{
  return (m_sorte == p_carte.m_sorte && m_valeur == p_carte.m_valeur) ? true : false;
}

//! \brief Surcharge l'operateur <
//! \return TRUE si la carte courante est la valeur suivante de celle en parametre sinon FALSE
bool		Carte::operator<(const Carte &p_carte) const
{
  return m_valeur == p_carte.m_valeur - 1 ? true : false;
}

//! \brief Surcharge l'operateur >
//! \return TRUE si la carte courante est la valeur precedente de celle en parametre sinon FALSE
bool		Carte::operator>(const Carte &p_carte) const
{
  return m_valeur == p_carte.m_valeur + 1 ? true : false;
}

//! \brief Surcharge l'operateur >=
//! \return TRUE si la carte courante peut etre superposee a celle en parametre dans les Piles
bool		Carte::operator>=(const Carte &p_carte) const
{
  if (m_sorte == p_carte.m_sorte && *this > p_carte)
    return true;
  return false;
}

//! \brief Surcharge l'operateur <=
//! \return TRUE si la carte courante peut etre superposee a celle en parametre dans les Colonnes
bool		Carte::operator<=(const Carte &p_carte) const
{
  if (p_carte.couleur() != couleur() && *this < p_carte)
    return true;
  return false;
}


//***********
// Accesseur
//***********


//! \brief Verifie si la carte est un AS
//! return TRUE si la carte est un AS sinon FALSE
bool		Carte::isAs() const
{
  return m_valeur == Carte::AS ? true : false;
}

//! \brief Verifie si la carte est un ROI
//! return TRUE si la carte est un ROI sinon FALSE
bool		Carte::isRoi() const
{
  return m_valeur == Carte::ROI ? true : false;
}

//*********
// Private
//*********

//! \brief Renvoie la couleur de la carte
//! \post La valeur ROUGE ou NOIR est renvoyee selon la carte
Carte::Couleur		Carte::couleur() const
{
  return (m_sorte == Carte::COEUR) || (m_sorte == Carte::CARREAU) ? Carte::ROUGE : Carte::NOIR;
}

//*********
// Friend
//*********

//! \brief Surcharge de l'operateur << affichage sous la forme [valeur]'[sorte]
//! \param[in] f est une reference sur le flux utilise
//! \param[in] carte est une reference constante sur la carte que l'on veut afficher
//! \post Un flux de sortie correspondant a la carte est retourne
std::ostream	&operator<<(std::ostream &p_f, const Carte &p_carte)
{
  std::string	tab[] =
    {
      "CO",
      "PI",
      "CA",
      "TR"
    };
  if (p_carte.m_valeur == Carte::VALET)
    p_f << "V'";
  else if (p_carte.m_valeur == Carte::DAME)
    p_f << "D'";
  else if (p_carte.m_valeur == Carte::ROI)
    p_f << "R'";
  else
      p_f << p_carte.m_valeur << "'";
  p_f << tab[p_carte.m_sorte];
  return p_f;
}


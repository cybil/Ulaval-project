//! \file Colonne.cpp
//! \brief Le code des methodes de la classe Colonne.
//! \author Cybil Bourely - CMBOU5
//! \version 0.1
//! \date 26 septembre 2013
//! Implémentation de la classe ColonneCarte

#include <iostream>
#include "Colonne.h"

//**************
// Constructeur
//**************

//! \brief Constructeur par defaut
//! \post Une colonne de carte vide est construite
ColonneCarte::ColonneCarte()
{
  m_nbCartesVisibles = 1;  
}

//! \brief Destructeur par defaut
//! \post Une instance de colonne de carte est detruite
ColonneCarte::~ColonneCarte()
{
}

//**************
// Modificateur
//**************

//! \brief initialise une colonne de carte
//! \param[in] listeCarte une liste de cartes permettant d'initialiser la colonne de cartes
void		ColonneCarte::initColonneCarte(Liste<Carte> &p_listeCartes)
{
  m_lesCartes = p_listeCartes;
}

//! \brief Ajoute une carte a la colonne
//! \param[in] carte est une carte a ajouter sur le dessus de la colonne
//! \pre L'ajout est realisable selon les regles du jeu
//! \exception runtime_error si le parametre n'est pas coherent avec les regles du jeu
void		ColonneCarte::ajoute(const Carte &p_carte)
{
  if (p_carte.isRoi() == true && m_lesCartes.taille() == 0
      || m_lesCartes.taille() > 0 && p_carte <= m_lesCartes.element(m_lesCartes.taille()))
    {
      m_lesCartes.ajouter(p_carte, m_lesCartes.taille() + 1);
      ++m_nbCartesVisibles;
      return ;
    }
  throw std::runtime_error("runtime_error AJOUTER");
}

//! \brief Deplace un paquet de carte de la colonne courante a une autre
//! \param[in] destination est la colonne de destination
//! \param[in] nombreCartes est le nombre de cartes du paquet a deplacer
//! \pre Le deplacement peut se faire selon les regles du jeu
//! \exception runtime_error si le deplacement n'est pas coherent avec les regles du jeu
void		ColonneCarte::deplacePaquet(ColonneCarte &p_destination, int p_nombreCartes)
{
  Liste<Carte>	tmp;

  for (int i = 0; i < p_nombreCartes; i++)
    {
      tmp.ajouter(m_lesCartes.element(m_lesCartes.taille()), tmp.taille() + 1);
      supprimerDerniereCarte();
    }
  for (int i = tmp.taille(); i >= 1; i--)
    p_destination.ajoute(tmp.element(i));
}

//! \brief Supprime la derniere carte de la colonne
//! \post La colonne contient une carte de moins. Si la carte supprimee est la derniere visible alors la carte suivante sera decouverte
void		ColonneCarte::supprimerDerniereCarte()
{
  m_lesCartes.enleverPos(m_lesCartes.taille());
  --m_nbCartesVisibles;
  if (m_nbCartesVisibles == 0 && m_lesCartes.taille() > 0)
    m_nbCartesVisibles = 1;
}

//************
// Accesseurs
//************

//! \brief Donne le nombre le carte visible dans la colonne
//! \return un entier representant le nombre de carte visible dans la colonne
int		ColonneCarte::getNbCartesVisibles() const
{
  return m_nbCartesVisibles;
}

//! \brief Donne la taille de la liste de la colonne
//! \return un entier representant la taille de la liste de la colonne
int		ColonneCarte::getTailleListe() const
{
  return m_lesCartes.taille();
}

//! \brief Donne une carte a une position donnee dans la colonne de carte
//! \param[in] pos est la position de la carte souhaitee
//! \return une reference constante sur la carte se situant a la position pos
const Cartes	&ColonneCarte::getCarteAPosition(int p_pos) const
{
  return m_lesCartes.element(p_pos);
}

//*********
// Friend
//*********

//! \brief Surcharge de l'operateur << 
//! \param[in] f est une reference sur le flux utilise
//! \param[in] colonne est une reference constante sur la colonne que l'on veut afficher
//! \post Un flux de sortie correspondant a la colonne est retourne
std::ostream	&operator<<(std::ostream &p_f, const ColonneCarte &p_colonne)
{
  if (p_colonne.getTailleListe() == 0)
    return p_f;
  for (int i = 0; i < p_colonne.getTailleListe() - p_colonne.getNbCartesVisibles(); i++)
    p_f << " ?";
  for (int i = (p_colonne.getTailleListe() - p_colonne.getNbCartesVisibles());
       i < p_colonne.getTailleListe(); i++)
    p_f << " " << p_colonne.getCarteAPosition(i + 1);
  return p_f;
}



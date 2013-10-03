/**
 * \file Solitaire.cpp
 * \brief 
 * \author Cybil Bourely - CMBOU5
 * \version 0.1
 * \date 27 septembre 2013
 */

#include <sstream>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>
#include "Solitaire.h"

//*****************************
// Constructeurs & Destructeur
//*****************************

//! \brief Constructeur par defaut
//! \post Une instance de la classe Soliataire est initialisee
Solitaire::Solitaire() : m_talon(24)
{
  std::vector<Carte>	tabTmp;

   for (int i = 0; i < 4; i++)
     for (int j = 1; j <= 13; j++)
       {
	 Carte	newCarte((Carte::Valeur)j, (Carte::Sorte)i);
	 tabTmp.push_back(newCarte); 
       }

   srand(time(NULL));
   std::random_shuffle(tabTmp.begin(), tabTmp.end());

   int			nbCarteParColonne = 1;
   int			k = 0;
   for (int j = 0; j < 7; j++)
     {
       Liste<Carte>	newListe;
       for (int i = 0; i < nbCarteParColonne; i++)
	 newListe.ajouter(tabTmp[k++], i + 1);
       m_colonnes[j].initColonneCarte(newListe);
       nbCarteParColonne++;
     }
   while (k < tabTmp.size())
     m_talon.enfiler(tabTmp[k++]);
   
}

//! \brief Destructeur par defaut
//! \post Une instance de la classe Soliataire est detruite
Solitaire::~Solitaire()
{
  std::cout << "Solitaire destroyed." << std::endl;
}


//***************
// Modificateurs
//***************

//! \brief Fait avancer le talon d'une carte
//! \post La premiere carte est placee a la fin du talon
void			Solitaire::avancerTalon()
{
  m_talon.enfiler(m_talon.defiler());
}

//! \brief Deplace un nombre de carte d'une colonne a une autre
//! \param[in] p_colonneSource est le numero de la colonne source
//! \param[in] p_colonneDestination est le numero de la colonne de destination
//! \param[in] p_nbCarte est le nombre de cartes a deplacer
//! \pre p_colonneSource et p_colonneDestination doivent etre compris entre 0 et 6 inclusivement
//! \exception runtime_error si les parametres ne sont pas coherents avec les regles du jeu
void			Solitaire::deplacerColonneAColonne(int p_colonneSource,
							   int p_colonneDestination,
							   int p_nbCarte)
{
  if (p_nbCarte > m_colonnes[p_colonneSource].getNbCarteVisibles())
    throw std::runtime_error("runtime_error");
  m_colonnes[p_colonneSource].deplacePaquet(m_colonnes[p_colonneDestination], p_nbCarte);
}


//! \brief Deplace la carte du dessus du talon sur la colonne specifiee
//! \param[in] p_colonneDestination est le numero de la colonne de destination
//! \pre p_colonneDestination doit etre compris entre 0 et 6 inclus
//! \exception runtime_error si le deplacement demande par l'appel n'est pas reglementaire
void			Solitaire::deplacerTalonAColonne(int p_colonneDestination)
{
  if (p_colonneDestination < 0 || p_colonneDestination > 6)
    throw std::runtime_error("runtime_error");
  m_colonnes[p_colonneDestination].ajoute(m_talon.defiler());
}


//! \brief Deplace la carte du dessus du talon sur la pile specifiee
//! \param[in] p_pileDestination est le numero de la pile de destination
//! \pre p_pileDestination doit etre compris entre 0 et 3 inclus
//! \exception runtime_error si le deplacement demande par l'appel n'est pas reglementaire
void			Solitaire::deplacerTalonAPile(int p_pileDestination)
{
  if (p_pileDestination < 0 || p_pileDestination > 3)
    throw std::runtime_error("!! Coup inalide !!");

  if (m_piles[p_pileDestination].estVide() == true && m_talon.premier().isAs() == false)
    throw std::runtime_error("!! Coup invalide !!");
  else if (m_piles[p_pileDestination].estVide() == true
	   || m_talon.premier() >= m_piles[p_pileDestination].top())
    m_piles[p_pileDestination].empiler(m_talon.defiler());
  else
    throw std::runtime_error("!! Coup invalide !!");
}


//! \brief Deplace la derniere carte de la colonne specifiee vers la pile specifiee
//! \param[in] p_colonneSource est le numero de la colonne source
//! \pre p_colonneSource doit etre compris entre 0 et 6 inclus
//! \param[in] p_pileDestination est le numero de la pile de destination
//! \pre p_pileDestination doit etre compris entre 0 et 3 inclus
//! \exception runtime_error si le deplacement demande par l'appel n'est pas reglementaire
void			Solitaire::deplacerColonneAPile(int p_colonneSource, int p_pileDestination)
{
  if (p_pileDestination < 0 || p_pileDestination > 4 
      || p_colonneSource < 0 || p_colonneSource > 6)
    throw std::runtime_error("!! Coup inalide !!");

  if (m_piles[p_pileDestination].estVide() == true
      && m_colonnes[p_colonneSource].getCarteAPosition(m_colonnes[p_colonneSource].getTailleListe()).isAs() == false)
    throw std::runtime_error("!! Coup invalide !!");
  else if (m_piles[p_pileDestination].estVide() == true
	   || m_colonnes[p_colonneSource].getCarteAPosition(m_colonnes[p_colonneSource].getTailleListe()) >= m_piles[p_pileDestination].top())
    {
      m_piles[p_pileDestination].empiler(m_colonnes[p_colonneSource].getCarteAPosition(m_colonnes[p_colonneSource].getTailleListe()));
      m_colonnes[p_colonneSource].supprimerDerniereCarte();
    }
  else
    throw std::runtime_error("!! Coup invalide !!");
}


//***********
//Sélécteurs
//***********

//! \brief Verifie si le joueur a gagne la partie
//! \return TRUE si le joueur a gagne la partie sinon FALSE
bool			Solitaire::verifieGagne() const
{
  if (m_talon.estVide() == false)
    return false;
  for (int i = 0; i < 7; i++)
    if (m_colonnes[i].getTailleListe() != 0)
      return false;
  return true;
}


//! \brief Retourne l'etat du jeu
//! \return l'etat du jeu formate dans une string sous la forme d'une interface
std::string		Solitaire::reqEtatJeu() const
{
  std::ostringstream	oss;
  std::string		etatJeu;

  oss << "Talon: " << m_talon.premier() << "\t\tPiles ";
  for (int i = 0; i < 4; i++)
    (m_piles[i].taille() == 0 ? oss << "   X" : oss << "   " << m_piles[i].top());
  oss << std::endl << std::endl;
  for (int i = 0; i < 7; i++) 
    oss << "Col." << i << ": " << m_colonnes[i] << std::endl;
  etatJeu = oss.str();
  return etatJeu;
}

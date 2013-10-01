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
  std::vector<Cartes>	tabTmp;

   for (int i = 0; i < 4; i++)
     for (int j = 1; j <= 13; j++)
       {
	 Cartes	newCartes((Cartes::Valeur)j, (Cartes::Sorte)i);
	 tabTmp.push_back(newCartes); 
       }

   srand(time(NULL));
   std::random_shuffle(tabTmp.begin(), tabTmp.end());

   int			nbCartesParColonne = 1;
   int			k = 0;
   for (int j = 0; j < 7; j++)
     {
       Liste<Cartes>	newListe;
       for (int i = 0; i < nbCartesParColonne; i++)
	 newListe.ajouter(tabTmp[k++], i + 1);
       m_colonnes[j].initColonneCarte(newListe);
       nbCartesParColonne++;
     }
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
// void			Solitaire::avancerTalon()
// {
  
// }

//! \brief Deplace un nombre de carte d'une colonne a une autre
//! \param[in] p_colonneSource est le numero de la colonne source
//! \param[in] p_colonneDestination est le numero de la colonne de destination
//! \param[in] p_nbCartes est le nombre de cartes a deplacer
//! \pre p_colonneSource et p_colonneDestination doivent etre compris entre 0 et 6 inclusivement
//! \exception runtime_error si les parametres ne sont pas coherents avec les regles du jeu
// void			Solitaire::deplacerColonneAColonne(int p_colonneSource,
// 							   int p_colonneDestination,
// 							   int p_nbCartes)
// {

// }


//! \brief Deplace la carte du dessus du talon sur la colonne specifiee
//! \param[in] p_colonneDestination est le numero de la colonne de destination
//! \pre p_colonneDestination doit etre compris entre 0 et 6 inclus
//! \exception runtime_error si le deplacement demande par l'appel n'est pas reglementaire
// void			Solitaire::deplacerTalonAColonne(int p_colonneDestination)
// {

// }


//! \brief Deplace la carte du dessus du talon sur la pile specifiee
//! \param[in] p_pileDestination est le numero de la pile de destination
//! \pre p_pileDestination doit etre compris entre 0 et 3 inclus
//! \exception runtime_error si le deplacement demande par l'appel n'est pas reglementaire
// void			Solitaire::deplacerTalonAPile(int p_PileDestination)
// {
//   if (p_piledestination < 0 || p_piledestination > 6)
//     throw std::runtime_error("!! Coup inalide !!");
//   if (m_piles[p_PileDestination].estVide() == true && m_talon.top().isAs() == false)
//     throw std::runtime_error("!! Coup invalide !!");
//   else if (m_piles[p_PileDestination].estVide() == true)
//     m_piles[p_piledestination].ajouterm_talon.premier();
//   if (m_talon.top() >= m_pile[p_piledestination].premier())
//     m_piles[p_piledestination].ajouterm_talon.premier();
//   else
//     throw std::runtime_error("!! Coup invalide !!");
// }


//! \brief Deplace la derniere carte de la colonne specifiee vers la pile specifiee
//! \param[in] p_colonneSource est le numero de la colonne source
//! \pre p_colonneSource doit etre compris entre 0 et 6 inclus
//! \param[in] p_pileDestination est le numero de la pile de destination
//! \pre p_pileDestination doit etre compris entre 0 et 3 inclus
//! \exception runtime_error si le deplacement demande par l'appel n'est pas reglementaire
// void			Solitaire::deplacerColonneAPile(int p_colonneSource, int p_pileDestination)
// {
//   if (p_piledestination < 0 || p_piledestination > 4 
//       || p_colonneSource < 0 || p_colonneSource > 6)
//     throw std::runtime_error("!! Coup inalide !!");
//   m_colonnes[p_colonneSource].deplacePaquet()
// }


//***********
//Sélécteurs
//***********

//! \brief Verifie si le joueur a gagne la partie
//! \return TRUE si le joueur a gagne la partie sinon FALSE
// bool			Solitaire::verifieGagne() const
// {

// }


//! \brief Retourne l'etat du jeu
//! \return l'etat du jeu formate dans une string sous la forme d'une interface
std::string		Solitaire::reqEtatJeu() const
{
  std::ostringstream	oss;
  std::string		etatJeu;

  oss << "Talon:" << m_talon[0] << "\t\tPiles ";
  for (int i = 0; i < 4; i++)
    oss << "   " // << m_piles[i].top()
      ;
  oss << std::endl;
  for (int i = 0; i < 7; i++) 
    oss << "Col." << i << ": " << m_colonnes[i] << std::endl;
  etatJeu = oss.str();
  return etatJeu;
}

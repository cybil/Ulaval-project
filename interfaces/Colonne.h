/**
 * \file Colonne.h
 * \brief Classe Définissant le type ColonneCarte
 * \author Cybil Bourely - CMBOU5
 * \version 0.1
 * \date 02 octobre 2013
 *
 * Description de la classe ColonneCarte
 */

#include "Liste.h"
#include "Carte.h"

/** 
 * \class ColonneCarte
 *
 * \brief classe représentant une Colonne de carte
 *
 *  La classe gère une colonne de carte.
 */
class ColonneCarte
{
public:
  //**************
  // Constructeur
  //**************

  //! \brief Constructeur par defaut
  //! \post Une colonne de carte vide est construite
  ColonneCarte();

  //! \brief Destructeur par defaut
  //! \post Une instance de colonne de carte est detruite
  ~ColonneCarte();

  //**************
  // Modificateur
  //**************

  //! \brief initialise une colonne de carte
  //! \param[in] listeCarte une liste de cartes permettant d'initialiser la colonne de cartes
  void		initColonneCarte(Liste<Carte> &);

  //! \brief Ajoute une carte a la colonne
  //! \param[in] carte est une carte a ajouter sur le dessus de la colonne
  //! \pre L'ajout est realisable selon les regles du jeu
  //! \exception runtime_error si le parametre n'est pas coherent avec les regles du jeu
  void		ajoute(const Carte &); 

  //! \brief Deplace un paquet de carte de la colonne courante a une autre
  //! \param[in] destination est la colonne de destination
  //! \param[in] nombreCartes est le nombre de cartes du paquet a deplacer
  //! \pre Le deplacement peut se faire selon les regles du jeu
  //! \exception runtime_error si le deplacement n'est pas coherent avec les regles du jeu
  void		deplacePaquet(ColonneCarte &, int);

  //! \brief Supprime la derniere carte de la colonne
  //! \post La colonne contient une carte de moins. Si la carte supprimee est la derniere visible alors la carte suivante sera decouverte
  void		supprimerDerniereCarte();

  //************
  // Accesseurs
  //************

  //! \brief Donne le nombre le carte visible dans la colonne
  //! \return un entier representant le nombre de carte visible dans la colonne
  int		getNbCartesVisibles() const;
  
  //! \brief Donne la taille de la liste de la colonne
  //! \return un entier representant la taille de la liste de la colonne
  int		getTailleListe() const;
  
  //! \brief Donne une carte a une position donnee dans la colonne de carte
  //! \param[in] pos est la position de la carte souhaitee
  //! \return une reference constante sur la carte se situant a la position pos
  const Carte	&getCarteAPosition(int) const;

private:
  Liste<Carte>		m_lesCartes;
  int			m_nbCartesVisibles;

  //*********
  // Friend
  //*********

  //! \brief Surcharge de l'operateur << 
  //! \param[in] f est une reference sur le flux utilise
  //! \param[in] colonne est une reference constante sur la colonne que l'on veut afficher
  //! \post Un flux de sortie correspondant a la colonne est retourne
  friend std::ostream	&operator<<(std::ostream &, const ColonneCarte &);
};

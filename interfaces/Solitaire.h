
#include <string>
#include "Colonne.h"
#include "File.h"
#include "Pile.h"

class Solitaire
{
public:
  
  //***********************************
  //	Constructeur & Destructeurs
  //***********************************
  
  //! \brief Constructeur par defaut
  //! \post Une instance de la classe Soliataire est initialisee
  Solitaire();
  
  //! \brief Destructeur par defaut
  //! \post Une instance de la classe Soliataire est detruite
  ~Solitaire();
  
  //*****************
  //	Modificateur
  //*****************

  //! \brief Fait avancer le talon d'une carte
  //! \post La premiere carte est placee a la fin du talon
  void			avancerTalon();

  //! \brief Deplace un nombre de carte d'une colonne a une autre
  //! \param[in] p_colonneSource est le numero de la colonne source
  //! \param[in] p_colonneDestination est le numero de la colonne de destination
  //! \param[in] p_nbCartes est le nombre de cartes a deplacer
  //! \pre p_colonneSource et p_colonneDestination doivent etre compris entre 0 et 6 inclusivement
  //! \exception runtime_error si les parametres ne sont pas coherents avec les regles du jeu
  void			deplacerColonneAColonne(int p_colonneSource,
  						int p_colonneDestination, int p_nbCartes);
  
  //! \brief Deplace la carte du dessus du talon sur la colonne specifiee
  //! \param[in] p_colonneDestination est le numero de la colonne de destination
  //! \pre p_colonneDestination doit etre compris entre 0 et 6 inclus
  //! \exception runtime_error si le deplacement demande par l'appel n'est pas reglementaire
  void			deplacerTalonAColonne(int p_colonneDestination);

  //! \brief Deplace la carte du dessus du talon sur la pile specifiee
  //! \param[in] p_pileDestination est le numero de la pile de destination
  //! \pre p_pileDestination doit etre compris entre 0 et 3 inclus
  //! \exception runtime_error si le deplacement demande par l'appel n'est pas reglementaire
  void			deplacerTalonAPile(int p_PileDestination);
  
  //! \brief Deplace la derniere carte de la colonne specifiee vers la pile specifiee
  //! \param[in] p_colonneSource est le numero de la colonne source
  //! \pre p_colonneSource doit etre compris entre 0 et 6 inclus
  //! \param[in] p_pileDestination est le numero de la pile de destination
  //! \pre p_pileDestination doit etre compris entre 0 et 3 inclus
  //! \exception runtime_error si le deplacement demande par l'appel n'est pas reglementaire
  void			deplacerColonneAPile(int p_colonneSource, int p_pileDestination);
  
  //****************
  //	Selecteurs
  //****************

  //! \brief Verifie si le joueur a gagne la partie
  //! \return TRUE si le joueur a gagne la partie sinon FALSE
  bool			verifieGagne() const;
  
  //! \brief Retourne l'etat du jeu
  //! \return l'etat du jeu formate dans une string sous la forme d'une interface
  std::string		reqEtatJeu() const;

private:

  File<Carte>		m_talon;
  ColonneCarte		m_colonnes[7];
  Pile<Carte>		m_piles[4];
};

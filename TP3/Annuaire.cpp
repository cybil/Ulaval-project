
#include "Annuaire.h"

Annuaire::Annuaire()
{

}

Annuaire::Annuaire(std::ifstream &p_fichierEntree)
{

}

Annuaire::~Annuaire()
{

}

//! \brief Pour inscrire une personne dans l'annuaire
//! \param[in] p_personne la personne a ajouter
//! \param[in] p_adresse l'adresse de la personne a ajouter
void				Annuaire::inscire(const Personne &p_personne, const Adresse &p_adresse)
{

}

//! \brief Ajoute un enfant a un parent dans un arbre genealogique
//! \brief Si p_parent == p_enfant, il s'agit d'un ancetre, un nouvel arbre est ajoute dans la liste des arbres genealogiques
//! \param[in] p_parent le parent dans l'arbre genealogique
//! \pre p_parent existe dans le bottin
//! \param[in] p_enfant l'enfant a ajouter au parent
//! \pre p_enfant existe dans le bottin
//! \exception logic_error si le parent n'existe pas dans le bottin
//! \exception logic_error si l'enfant n'existe pas dans le bottin
void				Annuaire::ajouterEnfant(const Personne &p_parent, const Personne &p_enfant)
{

}


//! \brief Operateur de sortie du contenu de l'annuaire formatage des infos dans une string puis sortie
//! \param[in] p_annuaire l'annuaire a sortir
//! \pre l'annuaire n'est pas vide
//! \param[out] p_os le flux de sortie contenant l'annuaire
//! \return un flux de sortie pour les appels en cascade
// std::ostream		&operator<<(std::ostream &p_os, const Annuaire &p_annuaire) const
// {
//   return os;
// }

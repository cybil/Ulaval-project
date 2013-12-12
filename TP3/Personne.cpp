
#include "Personne.h"

//! \brief Constructeur par parametres
//! \param[in] p_nom le nom de la personne
//! \param[in] p_prenom le prenom de la personne
//! \param[in] p_date la date de naissance de la personne
Personne::Personne(const std::string &p_nom, const std::string &p_prenom, int p_date)
{

}

//! \brief Constructeur par copie
//! \param[in] p_personne la personne a copier
Personne::Personne(const Personne &p_personne)
{

}

//! \brief Surcharge de l'operateur <
//! \param[in] p_personne la personne a comparer
//! \return true si la personne actuelle est nee apres p_personne
bool			Personne::operator<(const Personne &p_personne) const
{

}

//! \brief Surcharge de l'operateur >
//! \param[in] p_personne la personne a comparer
//! \return true si la personne actuelle est nee avant p_personne
bool			Personne::operator>(const Personne &p_personne) const
{

}

//! \brief Surcharge de l'operateur <=
//! \param[in] p_personne la personne a comparer
//! \return true si la personne actuelle est nee apres ou en meme temps que p_personne
bool			Personne::operator<=(const Personne &p_personne) const
{

}

//! \brief Surcharge de l'operateur ==
//! \param[in] p_personne la personne a comparer
//! \return true si la personne actuelle est en meme temps que p_personne
bool			Personne::operator==(const Personne &p_personne) const
{

}

//! \brief Retourne la date de naissance de la personne
//! \return la date de naissance (m_dateNaissance)
int			Personne::reqDateNaissance() const
{

}

//! \brief Retourne le nom de la personne
//! \return le nom de la personne (m_nom)
std::string		Personne::reqNom() const
{

}

//! \brief Retourne le prenom de la personne
//! \return le prenom de la personne (m_prenom)
std::string		Personne::reqPrenom() const
{

}

//! \brief Surcharge de l'operateur <<
//! \param[in] p_personne la personne a sortir
//! \param[out] p_os le flux de sortie contenant la personne formatee
//! \return un flux de sortie pour les appels en cascade
// std::ostream	&operator<<(std::ostream &p_os, const Personne &p_personne)
// {

// }

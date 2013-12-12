
#include "Adresse.h"

Adresse::Adresse(int p_numero, const std::string &p_rue, const std::string &p_ville)
{

}

//! \brief Constructeur par copie
//! \param[in] p_adresse l'objet a copier
Adresse::Adresse(const Adresse &p_adresse)
{

}

//! \brief Surcharge de l'operateur ==
//! \param[in] p_adresse l'adresse compare
//! \return true si les deux adresses sont egales sinon false
bool			Adresse::operator==(const Adresse &p_adresse) const
{

}

//! \brief Retourne le numero de la rue
//! \return le numero de la rue (m_numero)
int			Adresse::reqNumero() const
{

}

//! \brief Retourne le nom de la rue
//! \return le nom de la rue (m_rue)
std::string		Adresse::reqRue() const
{

}

//! \brief Retourne le nom de la ville
//! \return le nom de la ville (m_ville)
std::string		Adresse::reqVille() const
{

}

// std::ostream	&operator<<(std::ostream &p_os, const Adresse &p_adresse) const
// {
  
// }


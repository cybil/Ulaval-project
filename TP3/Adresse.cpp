
#include "Adresse.h"

//! \brief Constructeur par parametres
//! \param [in] p_numero le numero de la rue
//! \param [in] p_rue le nom de la rue
//! \param [in] p_ville la ville ou se situe l'adresse
Adresse::Adresse(int p_numero, const std::string &p_rue, const std::string &p_ville)
  : m_numero(p_numero), m_rue(p_rue), m_ville(p_ville)
{
}

//! \brief Constructeur par copie
//! \param[in] p_adresse l'objet a copier
Adresse::Adresse(const Adresse &p_adresse)
{
  this->m_numero = p_adresse.m_numero;
  this->m_rue = p_adresse.m_rue;
  this->m_ville = p_adresse.m_ville;
}

//! \brief Surcharge de l'operateur ==
//! \param[in] p_adresse l'adresse compare
//! \return true si les deux adresses sont egales sinon false
bool			Adresse::operator==(const Adresse &p_adresse) const
{
  if (p_adresse.reqNumero() == this->m_numero
      && p_adresse.reqRue() == this->m_rue
      && p_adresse.reqVille()== this->m_ville)
    return true;
  return false;
}

//! \brief Retourne le numero de la rue
//! \return le numero de la rue (m_numero)
int			Adresse::reqNumero() const
{
  return m_numero;
}

//! \brief Retourne le nom de la rue
//! \return le nom de la rue (m_rue)
std::string		Adresse::reqRue() const
{
  return m_rue;
}

//! \brief Retourne le nom de la ville
//! \return le nom de la ville (m_ville)
std::string		Adresse::reqVille() const
{
  return m_ville;
}

std::ostream	&operator<<(std::ostream &p_os, const Adresse &p_adresse)
{
  p_os << "Adresse: " << p_adresse.reqNumero() << ", " << p_adresse.reqRue() <<  " - " << p_adresse.reqVille();
  return p_os;
}


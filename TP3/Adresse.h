
#ifndef		ADRESSE_H__
#define		ADRESSE_H__

#include <string>
#include <ostream>

class Adresse
{
public:
  //! \brief Constructeur par parametres
  //! \param [in] p_numero le numero de la rue
  //! \param [in] p_rue le nom de la rue
  //! \param [in] p_ville la ville ou se situe l'adresse
  Adresse(int p_numero, const std::string &p_rue, const std::string &p_ville);

  //! \brief Constructeur par copie
  //! \param[in] p_adresse l'objet a copier
  Adresse(const Adresse &p_adresse);

  //! \brief Surcharge de l'operateur ==
  //! \param[in] p_adresse l'adresse compare
  //! \return true si les deux adresses sont egales sinon false
  bool			operator==(const Adresse &p_adresse) const;

  //! \brief Retourne le numero de la rue
  //! \return le numero de la rue (m_numero)
  int			reqNumero() const;

  //! \brief Retourne le nom de la rue
  //! \return le nom de la rue (m_rue)
  std::string		reqRue() const;

  //! \brief Retourne le nom de la ville
  //! \return le nom de la ville (m_ville)
  std::string		reqVille() const;

  /* friend std::ostream	&operator<<(std::ostream &p_os, const Adresse &p_adresse) const; */

private :

  int			m_numero;
  std::string		m_rue;
  std::string		m_ville;

};

#endif		// !ADRESSE_H__

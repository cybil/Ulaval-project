//! \file Ville.h
//! \brief interface de la classe Ville mod�lisant des villes o� sont situ�s des a�roports
//! \author Benjamin De Almeida - BEDEA1
//! \version 0.1
//! \date 2013-11-07
//! une ville est caract�ris�e par son nom et le code de son a�roport
#ifndef VILLE_H_
#define VILLE_H_
#include <string>
#include <iostream>

namespace tp2
{
  class Ville
  {
  public:
    Ville(const std::string &p_nom,
	  const std::string &p_codeAeroport);
    std::string			reqCodeAeroport() const;
    std::string			reqNom() const;
    bool			operator==(const Ville &p_ville) const;
    friend std::ostream		&operator<<(std::ostream &p_out, const Ville &p_ville);

  private:
    std::string			m_nom;
    std::string			m_codeAeroport;
  };

  inline std::string		Ville::reqCodeAeroport() const
  {
    return m_codeAeroport;
  }

  inline std::string		Ville::reqNom() const
  {
    return m_nom;
  }
}

#endif /* VILLE_H_ */

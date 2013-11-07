//! \file Ville.cpp
//! \brief Methode Class Ville
//! \author Benjamin De Almeida - BEDEA1
//! \version 1.0
//! \date 06 novembre 2013
//!
//! Methode De Classe Ville

//! \brief Constructeur avec parametres
//! \param[in] nom de la ville
//! \param[in] code de l'aeroport
//! \post initialise la ville
Ville(const std::string &p_nom, const std::string &p_codeAeroport)
{
  m_nom = p_nom;
  m_codeAeroport = p_codeAeroport;
}

//! \brief Accesseur au code de l'aeroport
//! \param[out] Code de l'aeroport
std::string			reqCodeAeroport() const
{
  return (m_codeAeroport);
}

//! \brief Accesseur de la ville
//! \param[out] Nom de la ville
std::string			reqNom() const
{
  return (m_nom);
}

/**
 * Surcharge d'operateur =
 */

//! \brief Surcharge de l'operateur d'affectation
//! \pre Il doit y avoir assez de memoire
//! \post La ville a un contenu identique a la ville source
//! \param[in] source La ville a copier
bool			operator==(const Ville &p_ville) const
{
  if (!m_nom.compare(p_ville.reqNom) && !m_codeAeroport.compare(p_ville.reqCodeAeroport))
    return (true);
  return (false);
}

/**
 * Surcharge d'operateur <<
 */

//! \brief Surcharge de l'operateur <<
//! \post Affichage de la ville nom et code d aeroport
//! \param[in] Ville à afficher
friend std::ostream		&operator<<(std::ostream &p_out, const Ville &p_ville)
{
  p_out << p_ville.reqNom() << std::endl << p_ville.reqCodeAeroport() << std::endl;
  return (p_out);
}

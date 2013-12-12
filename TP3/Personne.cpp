//! \file Personne.cpp
//! \brief Implemantation des fonction membres de la classe Personne
//! \author 
//! \author 
//! \version 1.0
//! \date 13/12/2013

#include "Personne.h"

//! \brief     Constructeur de la classe Personne
//! \param[in] p_nom nom de la personne a ajouter
//! \param[in] p_prenom prenom de la personne a ajouter
//! \param[in] p_date date de naissance de la personne a ajouter
Personne::Personne(std::string const & p_nom, std::string const & p_prenom, int p_date) {
	m_nom           = p_nom;
	m_prenom        = p_prenom;
	m_dateNaissance = p_date;
}

//! \brief     Constructeur par copie de la classe Personne
//! \param[in] p_personne instance de la classe personne que l'on copie
Personne::Personne(Personne const & p_personne) {
	m_nom           = p_personne.m_nom;
	m_prenom        = p_personne.m_prenom;
	m_dateNaissance = p_personne.m_dateNaissance;
}

//! \brief  Getter de la date de naissance
//! \return int m_dateNaissance
int Personne::reqDateNaissance(void) const { return m_dateNaissance; }

//! \brief  Getter de la date de naissance
//! \return string m_nom
std::string Personne::reqNom(void) const { return m_nom; }

//! \brief  Getter du prenom
//! \return string m_prenom
std::string Personne::reqPrenom(void) const { return m_prenom; }

//! \brief     Surcharge de l'operateur inferieur
//! \param[in] p_personne une instance de la classe Personne
//! \return    un booleen : true si this < p_personne
bool Personne::operator<(Personne const & p_personne) const {
	return m_nom < p_personne.m_nom;
}

//! \brief     Surcharge de l'operateur superieur
//! \param[in] p_personne une instance de la classe Personne
//! \return    un booleen : true si this > p_personne
bool Personne::operator>(Personne const & p_personne) const {
	return m_nom > p_personne.m_nom;
}

//! \brief     Surcharge de l'operateur inferieur ou egal
//! \param[in] p_personne une instance de la classe Personne
//! \return    un booleen : true si this <= p_personne
bool Personne::operator<=(Personne const & p_personne) const {
	return
		*this <  p_personne ||
		*this == p_personne;
}

//! \brief     Surcharge de l'operateur superieur ou egal
//! \param[in] p_personne une instance de la classe Personne
//! \return    un booleen : true si this >= p_personne
bool Personne::operator>=(Personne const & p_personne) const {
	return
		*this >  p_personne ||
		*this == p_personne;
}

//! \brief     Surcharge de l'operateur egalite
//! \param[in] p_personne une instance de la classe Personne
//! \return    un booleen : true si this == p_personne
bool Personne::operator==(Personne const & p_personne) const {
	return
		m_nom           == p_personne.m_nom    &&
		m_prenom        == p_personne.m_prenom &&
		m_dateNaissance == p_personne.m_dateNaissance;
}

//! \brief     Surcharge de l'operateur de flux de sortie
//! \param[in] p_personne une instance de la classe Personne
//! \param[in] p_os flux de sortie
//! \return    le flux de sortie modifie
std::ostream & operator<<(std::ostream & p_os, Personne const & p_personne) {
	p_os << p_personne.reqNom() << " " << p_personne.reqPrenom() << " " << p_personne.reqDateNaissance();
	return p_os;
}

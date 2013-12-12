//! \file Personne.h
//! \brief Implemantation de la classe Personne
//! \author 
//! \author 
//! \version 1.0
//! \date 13/12/2013

#ifndef PERSONNE_H_
#define PERSONNE_H_

#include <iostream>
#include <string>

class Personne {
public:
	// Constructors/Destructor
	Personne(std::string const & p_nom, std::string const & p_prenom, int p_date);
	Personne(Personne const &);
	//Getters
	int         reqDateNaissance(void) const;
	std::string reqNom(void) const;
	std::string reqPrenom(void) const;
	//Operators
	bool operator< (Personne const &) const;
	bool operator> (Personne const &) const;
	bool operator<=(Personne const &) const;
	bool operator>=(Personne const &) const;
	bool operator==(Personne const &) const;
	friend std::ostream & operator<<(std::ostream &, Personne const &);
private:
	int         m_dateNaissance;
	std::string m_nom;
	std::string m_prenom;
};

#endif /* PERSONNE_H_ */

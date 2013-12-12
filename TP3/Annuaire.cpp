
#include <ostream>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include "Annuaire.h"

Annuaire::Annuaire()
{
}

//! \brief Constructeur a partir d'un fichier en entree
//! \param[in] p_fichierEntree un flux d'entree vers un fichier contenant la liste des personnes a charger
//! \pre Il y a assez de memoire pour charger toutes les personnes de la liste
//! \pre Le fichier p_fichierEntree est ouvert correctement
//! \post Le fichier p_fichierEntree n'est pas ferme par la fonction
//! \post Si les preconditions sont respectees, les donnees de l'annuaire contenues dans le fichier en entree sont orgnisees dans une structure de donnees
//! \exception bad_alloc si pas assez de memoire pour contenir toute la liste du fichier
//! \exception logic_error si p_fichierEntree n'est pas ouvert correctement
Annuaire::Annuaire(std::ifstream &p_fichierEntree)
{
  if (p_fichierEntree.is_open() == false)
    throw std::logic_error("Annuaire: fichier non ouvert");
  
  bool		separateur = false;
  std::string	nom;
  std::string	prenom;
  std::string	date;
  std::string	numero;
  std::string	rue;
  std::string	ville;

  // try {
    while (!p_fichierEntree.eof())
      {
	if (separateur == false)
	  {
	    getline(p_fichierEntree, nom);
	    if (nom == "$")
	      separateur = true;
	    else
	      {
		getline(p_fichierEntree, prenom);
		getline(p_fichierEntree, date);
		getline(p_fichierEntree, numero);
		getline(p_fichierEntree, rue);
		getline(p_fichierEntree, ville);
		Personne	personne(nom, prenom, atoi(date.c_str()));
		Adresse	adresse(atoi(numero.c_str()), rue, ville);
		inscrire(personne, adresse);
	      }
	  }
	else
	  {
	    getline(p_fichierEntree, nom);
	    getline(p_fichierEntree, prenom);
	    getline(p_fichierEntree, date);
	    Personne	personne1(nom, prenom, atoi(date.c_str()));
	  
	    getline(p_fichierEntree, nom);
	    getline(p_fichierEntree, prenom);
	    getline(p_fichierEntree, date);
	    Personne	personne2(nom, prenom, atoi(date.c_str()));

	    ajouterEnfant(personne1, personne2);
	  }
      }
  // } catch (std::exception e) {
  //   std::cerr << "Annuaire: Invalid file" << std::endl;
  // }
}

Annuaire::~Annuaire()
{

}

//! \brief Pour inscrire une personne dans l'annuaire
//! \param[in] p_personne la personne a ajouter
//! \param[in] p_adresse l'adresse de la personne a ajouter
void				Annuaire::inscrire(const Personne &p_personne, const Adresse &p_adresse)
{
  m_bottin.inserer(p_personne, p_adresse);
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
  if (m_bottin.appartient(p_parent) == false
      || m_bottin.appartient(p_enfant) == false)
    throw std::logic_error("Annuaire: le parent ou l'enfant n'existe pas dans le bottin");

  if (p_parent == p_enfant)
    {
      ArbreGenealogique	nouvelArbre(p_parent);
      m_listArbreGene.push_back(nouvelArbre);
    }

  std::list<ArbreGenealogique>::iterator	it = m_listArbreGene.begin();
  while (it != m_listArbreGene.end())
    {
      it->ajouterEnfant(p_parent, p_enfant);
      ++it;
    }

}


//! \brief Retourne le bottin
ArbreAVL<Personne, Adresse>		Annuaire::getBottin() const
{
  return m_bottin;
}

//! \brief Retourne la liste des arbres genealogique
std::list<ArbreGenealogique>		Annuaire::getListArbreGen() const
{
  return m_listArbreGene;
}

//! \brief Operateur de sortie du contenu de l'annuaire formatage des infos dans une string puis sortie
//! \param[in] p_annuaire l'annuaire a sortir
//! \pre l'annuaire n'est pas vide
//! \param[out] p_os le flux de sortie contenant l'annuaire
//! \return un flux de sortie pour les appels en cascade
std::ostream		&operator<<(std::ostream &p_os, const Annuaire &p_annuaire)
{
  // p_os << p_annuaire.getBottin() << p_annuaire.getListArbreGen();
  return p_os;
}

//! \file Couverture.cpp
//! \brief impl�mentation de l'interface pour une couverture a�rienne
//! \author theud1
//! \version 0.1
//! \date 2013-10-03
#include <algorithm>
#include <stdexcept>
#include <string>
#include <fstream>
#include <iostream>
#include "Couverture.h"

namespace tp2
{
  //! \brief		Constructeur � partir d'un fichier en entr�e.
  //! \param[in]	p_fichierEntree pointeur sur le fichier contenant la liste des villes � charger ainsi que les liaisons.
  //! \pre		Il y a assez de m�moire pour charger toutes les ville de la liste.
  //! \pre		Le fichier \a fichierEntree est ouvert corectement.
  //! \post		Le fichier \a fichierEntree n'est pas ferm� par la fonction.
  //! \post		Si les pr�conditions sont respect�es, les donn�es de la couverture contenues
  //!				dans le fichier en entr�e sont organis�es dans un graphe en m�moire.
  //! \exception	bad_alloc si pas assez de m�moire contenir toute la liste du fichier.
  //! \exception	logic_error si le fichier \a fichierEntree n'est pas ouvert correctement.
  Couverture::Couverture(std::ifstream &p_fichierEntree)
  {
    if (p_fichierEntree == NULL)
      throw std::logic_error("Couverture: fichier non ouvert\n");

    //Lecture des donn�es sur les villes
    string		nom; //Pour le nom des villes
    string		codeAeroport;
    int			numero = 1;
    vector<string>	tabNomVilles;

    bool		sentinelle = false;

    while (!p_fichierEntree.eof() && sentinelle == false)
      {
	getline(p_fichierEntree, nom);
	if (nom == "$")//limite de la premi�re partie du fichier
	  {
	    sentinelle = true;
	  }
	else
	  {
	    getline(p_fichierEntree, codeAeroport);
	    m_graphe.ajouterSommet(numero, Ville(nom, codeAeroport));
	    ++numero;
	    tabNomVilles.push_back(nom);
	  }
      }

    int			dureeVol;
    string		villeDestination;//nom de la ville de destination
    int			indiceSource;
    int			indiceDestination;
    char		buff[255];
    vector<string>::iterator position;

    while (!p_fichierEntree.eof())
      {
	p_fichierEntree.getline(buff, 100);
	nom = buff;
	position = find(tabNomVilles.begin(), tabNomVilles.end(), nom);
	indiceSource = position - tabNomVilles.begin();
	p_fichierEntree.getline(buff, 100);
	villeDestination = buff;
	position = find(tabNomVilles.begin(), tabNomVilles.end(),
			villeDestination);
	indiceDestination = position - tabNomVilles.begin();
	p_fichierEntree >> dureeVol;
	p_fichierEntree.ignore();
	m_graphe.ajouterArc(indiceSource + 1, indiceDestination + 1, dureeVol);
      }
    //	cout << m_graphe;
  }

  //! \brief		Affiche une liste de villes de la couverture � l'�cran.
  //! \param[in]	p_vVilles		Une liste de villes dans un vector.
  //! \post		Le contenu de la liste p_vVilles est affich�.
  void		Couverture::afficherVilles(std::vector<Ville> &p_vVilles)
  {
    if (p_vVilles.size() == 0)
      {
	std::cout << "La liste est vide\n";
      }
    else
      {
	for (unsigned int i = p_vVilles.size(); i > 0; i--)
	    std::cout << p_vVilles[i - 1] << std::endl;
      }
  }
  
  void			afficherVilles()
  {
    afficherVilles(m_graphe.listerSommets);
  }
  
  bool			villesAccessibles()
  {
    if (m_graphe.estFortementConnexe())
      return (true);
    return (false);
  }

  std::vector<Ville>	villesCritiques()
  {
    std::vector<Ville> critiques;

    m_graphe.getPointsArticulation(critiques);
    return (critiques);
  }

  std::vector<Ville>	determinerMinParcours(const Ville & p_origine,
					      const Ville & p_destination, int & p_duree)
  {
    
  }

  std::vector<Ville>	bellManFord(const Ville & p_origine,
				    const Ville & p_destination, int & p_duree)
  {

  }

}//namespace tp2

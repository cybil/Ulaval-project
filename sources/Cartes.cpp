
#include <iostream>
#include "Cartes.h"

Cartes::Cartes(const Cartes::Valeur p_valeur, const Cartes::Sorte p_sorte)
{
  m_valeur = p_valeur;
  m_sorte = p_sorte;
  std::cout << "Cartes created." << std::endl;
}

Cartes::Cartes(const Cartes &p_rhs)
{
  m_sorte = p_rhs.m_sorte;
  m_valeur = p_rhs.m_valeur;
  std::cout << "Cartes created." << std::endl;
}

Cartes::~Cartes()
{
  std::cout << "Cartes destroyed." << std::endl;
}

const Cartes	&Cartes::operator=(const Cartes &p_rhs)
{
  m_sorte = p_rhs.m_sorte;
  m_valeur = p_rhs.m_valeur;
  return *this;
}

bool		Cartes::operator==(const Cartes &p_carte) const
{
  return m_sorte == p_carte.m_sorte ? true : false;
}

bool		Cartes::operator<(const Cartes &p_carte) const
{
  return m_valeur == p_carte.m_valeur + 1 ? true : false;
}

std::ostream	operator<<(std::ostream &p_f, const Cartes &p_carte)
{
  // p_f << p_carte.m_valeur;
  // p_f << "'";
  // p_f << p_carte.m_sorte;
  // return p_f;
}

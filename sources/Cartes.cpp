
#include <iostream>
#include "Cartes.h"

Cartes::Cartes(Carte::Valeur p_valeur, Cartes::Sorte p_sorte)
{
  m_valeur = p_valeur;
  m_sorte = p_sorte;
  std::cout << "Cartes created." << std::endl;
}

Cartes::Cartes(const Cartes &p_rhs)
{
  m_sorte = p_rhs.getSorte();
  m_valeu = p_rhs.getValeur();
  std::cout << "Cartes created." << std::endl;
}

Cartes::~Cartes()
{
  std::cout << "Cartes destroyed." << std::endl;
}

const Cartes	&Cartes::operator=(const Cartes &p_rhs)
{
  m_sorte = p_rhs.getSorte();
  m_valeur = p_rhs.getValeur();
  return *this;
}

bool		Cartes::operator==(const Cartes &p_carte) const
{
  return m_sorte == p_carte.getSorte() ? true : false;
}

bool		Cartes::operator<(const Cartes &p_carte) const
{
  return m_valeur == p_carte.getValeur() + 1 ? true : false;
}

// Getters
Sorte		Cartes::getSorte() const
{
  return m_sorte;
}

Valeur		Cartes::getValeur() const
{
  return m_valeur;
}

std::ostream	operator<<(std::ostream &p_f, const Cartes &p_carte);
{
  p_f << p_carte.getValeur();
  p_f << "'";
  p_f << p_carte.getSorte();
  return p_f;
}

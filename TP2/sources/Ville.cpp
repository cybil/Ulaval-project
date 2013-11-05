Ville(const std::string &p_nom, const std::string &p_codeAeroport)
{
  m_nom = p_nom;
  m_codeAeroport = p_codeAeroport;
}

std::string			reqCodeAeroport() const
{
  return (m_codeAeroport);
}

std::string			reqNom() const
{
  return (m_nom);
}

bool			operator==(const Ville &p_ville) const
{
  if (!m_nom.compare(p_ville.reqNom) && !m_codeAeroport.compare(p_ville.reqCodeAeroport))
    return (true);
  return (false);
}

friend std::ostream		&operator<<(std::ostream &p_out, const Ville &p_ville)
{
  p_out << p_ville.reqNom() << std::endl << p_ville.reqCodeAeroport() << std::endl;
  return (p_out);
}

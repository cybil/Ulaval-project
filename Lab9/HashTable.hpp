/**
 * \file HashTable.hpp
 * \brief Impl�mentation de la classe HashTable
 * \author Mon �tudiant pr�f�r�
 * \version 0.1
 * \date mai 2011
 *
 * R�solution de collisions par adressage ouvert et sondage quadratique
 */

namespace HashTable_Lab9
{
  /**
   * \fn HashTable<TypeClef, T, FoncHachage>:: HashTable( int size) 
   *
   * \param[in] size La taille de la hash table
   */
  template<typename TypeClef, typename T, class FoncHachage>
  HashTable<TypeClef, T, FoncHachage>::HashTable(int p_size) 
  : m_tab(nextPrime(p_size))
  { 
    makeEmpty(); 
  }
	    
  /**
   * \fn void HashTable<TypeClef, T, FoncHachage>::makeEmpty( )
   */
  template<typename TypeClef, typename T, class FoncHachage>
  void HashTable<TypeClef, T, FoncHachage>::makeEmpty()
  {
    m_currentSize = 0;
    for (unsigned int i = 0; i < m_tab.size(); i++)
      m_tab[i].m_info = EMPTY;
  }

  /**
   * \fn void HashTable<TypeClef, T, FoncHachage>::  rehash()
   */
  template<typename TypeClef, typename T, class FoncHachage>
  void		HashTable<TypeClef, T, FoncHachage>::rehash()
  {
    std::vector<HashEntry> oldArray = m_tab;

    // Cr�ation d'une nouvelle table 2 fois plus grande
    m_tab.resize(nextPrime( 2 * oldArray.size()));
    for (unsigned int j = 0; j < m_tab.size(); j++)
      m_tab[ j ].m_info = EMPTY;

    // Copie de la table
    m_currentSize = 0;
    for (unsigned int i = 0; i < oldArray.size(); i++)
      if (oldArray[ i ].m_info == ACTIVE)
	insert(oldArray[ i ].m_key, oldArray[i].m_element);
  }


  /**
   *  \brief Recherche d'un �l�ment � partir d'une cl�
   *
   *  Recherche dans la table de dipsersion
   *
   * \post VRAI est retourn� si l'�l�ment est pr�sent, FAUX sinon
   */
  template<typename TypeClef, typename T, class FoncHachage>
  bool		HashTable<TypeClef, T, FoncHachage>::contains(const TypeClef &p_x)
  {
    if (m_tab[m_myhash(p_x) % m_tab.size()].m_key == p_x
    	&& m_tab[m_myhash(p_x) % m_tab.size()].m_info == ACTIVE)
      return true;
    for (unsigned int i = 0; i < m_tab.size(); i++)
      {
    	if (m_tab[i].m_info == EMPTY)
    	  return false;
    	if (m_tab[i].m_key == p_x
    	    && m_tab[i].m_info == ACTIVE)
    	  return true;
      }
    return false;
  }


  /**
   * \brief Localise une place vacante dans la table de dispersion
   * \param[in] x est la clef de l'entree a inserer dans la table
   * \return La position de la place libre trouvee
   */
  template<typename TypeClef, typename T, class FoncHachage>
  unsigned int		HashTable<TypeClef, T, FoncHachage>::findPos(const TypeClef &p_x)
  {
    unsigned int	i = m_myhash(p_x);

    ++i;
    while (m_tab[i % m_tab.size()].m_key != p_x)
      {
	i = (i + 1) * (i + 1);
	if (m_tab[i % m_tab.size()].m_info != ACTIVE)
	  return i % m_tab.size();
      }
    throw std::logic_error("logic_error : aucune place vacante trouvee dans la table");
  }


  /**
   *  \brief Insertion d'une paire (cl�, valeur) dans la table de dispersion
   *
   *  Une redispersion quadratique serait utilis�e en cas de collision
   *  La m�thode fait appel � la m�thode priv�e findPos() pour localiser
   *  une place vacante dans la table de dispersion.
   *
   * Si, apr�s une insertion, le taux de remplissage atteint le maximum, on double la taille
   * de la table de dispersion en appelant (dans la m�thode inert()) rehash().
   *
   * \pre la cl� � ins�rer n'est pas d�j� pr�sente dans la table
   * \post La paire a �t� ins�r�e dans la table
   * \exception logic_error si la cl� est d�j� dans la table
   */
  template<typename TypeClef, typename T, class FoncHachage>
  void		HashTable<TypeClef, T, FoncHachage>::insert(const TypeClef &p_x, const T &p_val)
  {
    if (contains(p_x) == true)
      throw std::logic_error("logic_error : la clef est deja dans la table.");
    
    HashEntry  	newEntry(p_x, p_val);
    newEntry.m_info = ACTIVE;
    
    if (m_tab[m_myhash(p_x) % m_tab.size()].m_info == ACTIVE)
      m_tab[findPos(p_x)] = newEntry;
    else
      m_tab[m_myhash(p_x) % m_tab.size()] = newEntry;

    ++m_currentSize;
    if (m_currentSize >= (m_tab.size() * m_TAUX_MAX / 100))
      rehash();
  }

  template<typename TypeClef, typename T, class FoncHachage>
  void		HashTable<TypeClef, T, FoncHachage>::display() const
  {
    for (unsigned int i = 0; i < m_tab.size(); i++)
      {
	std::cout << "m_tab[ = " << i << "] :: ";
	if (m_tab[i].m_info == ACTIVE)
	  std::cout << m_tab[i].m_key;
	else if (m_tab[i].m_info == DELETED)
	  std::cout << "DELETED";
	else
	  std::cout << "EMPTY";
	std::cout << " :: " << m_tab[i].m_element << std::endl;
      }
  } 

  /**
   *  \brief Supprimer un �l�ment de la table
   *
   * \pre la cl� � supprimer doit �tre pr�sente dans la table
   * \post La table comprend un �l�ment de moins
   * \exception logic_error si la cl� n'est pas dans la table
   */
  template<typename TypeClef, typename T, class FoncHachage>
  void		HashTable<TypeClef, T, FoncHachage>::remove(const TypeClef &p_x)
  {
    if (contains(p_x) == true)
      {
	unsigned int	it = m_myhash(p_x);

	if (m_tab[it % m_tab.size()].m_key == p_x)
	  m_tab[it % m_tab.size()].m_info = DELETED;
	else
	  {
	    for (unsigned int i = 0; i < m_tab.size(); i++)
	      {
		if (m_tab[i].m_key == p_x
		    && m_tab[i].m_info == ACTIVE)
		  {
		    m_tab[i].m_info = DELETED;
		    break;
		  }
	      }
	  }
	--m_currentSize;
	return ;
      }
    throw std::logic_error("logic_error : la clef n'est pas dans la table.");
  }


}//Fin du namespace
  

/**
 * \file HashTableD.hpp
 * \brief Implémentation de la classe HashTable
 * \author Cybil Bourely - CMBOU5
 * \version 0.1
 * \date 22 novembre 2013
 *
 * Résolution de collisions par adressage ouvert et sondage quadratique
 */

#include <math.h>

namespace HashTable_Lab9
{
  /**
   * \fn HashTable<TypeClef, T, FoncHachage>:: HashTable( int size) 
   *
   * \param[in] size La taille de la hash table
   */
  template<typename TypeClef, typename T, class FoncHachage1, class FoncHachage2>
  HashTableD<TypeClef, T, FoncHachage1, FoncHachage2>::HashTableD(int p_size) 
  : m_tab(nextPrime(p_size))
  { 
    m_nbCollision = 0;
    makeEmpty(); 
  }
	    
  /**
   * \fn void HashTable<TypeClef, T, FoncHachage1, FoncHachage2>::makeEmpty( )
   */
  template<typename TypeClef, typename T, class FoncHachage1, class FoncHachage2>
  void HashTableD<TypeClef, T, FoncHachage1, FoncHachage2>::makeEmpty()
  {
    m_currentSize = 0;
    for (unsigned int i = 0; i < m_tab.size(); i++)
      m_tab[i].m_info = EMPTY;
  }

  /**
   * \fn void HashTableD<TypeClef, T, FoncHachage1, FoncHachage2>::  rehash()
   */
  template<typename TypeClef, typename T, class FoncHachage1, class FoncHachage2>
  void		HashTableD<TypeClef, T, FoncHachage1, FoncHachage2>::rehash()
  {
    std::vector<HashEntry> oldArray = m_tab;

    m_tab.resize(nextPrime(2 * oldArray.size()));
    for (unsigned int j = 0; j < m_tab.size(); j++)
      m_tab[ j ].m_info = EMPTY;

    m_currentSize = 0;
    for (unsigned int i = 0; i < oldArray.size(); i++)
      if (oldArray[ i ].m_info == ACTIVE)
	insert(oldArray[ i ].m_key, oldArray[i].m_element);
  }


  /**
   *  \brief Recherche d'un élément à partir d'une clé
   *
   *  Recherche dans la table de dipsersion
   *
   * \post VRAI est retourné si l'élément est présent, FAUX sinon
   */
  template<typename TypeClef, typename T, class FoncHachage1, class FoncHachage2>
  bool		HashTableD<TypeClef, T, FoncHachage1, FoncHachage2>::contains(const TypeClef &p_x)
  {
    if (m_tab[m_myhash1(p_x) % m_tab.size()].m_key == p_x
    	&& m_tab[m_myhash1(p_x) % m_tab.size()].m_info == ACTIVE)
      return true;
    ++m_nbCollision;
    unsigned int	i = 0;
    while (i < m_tab.size())
      {
    	if (m_tab[i].m_key == p_x
    	    && m_tab[i].m_info == ACTIVE)
    	  return true;
	++i;
      }
    return false;
  }

  /**
   * \brief Calcule le resultat d'un nombre eleve a une puissance donnee
   * \param[in] value est le nombre a elever
   * \param[in] p est la puissance
   * \return value a la puissance p
   */
  template<typename TypeClef, typename T, class FoncHachage1, class FoncHachage2>
  int		HashTableD<TypeClef, T, FoncHachage1, FoncHachage2>::power(int value, int p)
  {
    int		ret = value;
    
    for (int i = 0; i < p; i++)
      ret *= ret;
    return ret;
  }


  /**
   * \brief Localise une place vacante dans la table de dispersion
   * \param[in] x est la clef de l'entree a inserer dans la table
   * \return La position de la place libre trouvee
   */
  template<typename TypeClef, typename T, class FoncHachage1, class FoncHachage2>
  unsigned int		HashTableD<TypeClef, T, FoncHachage1, FoncHachage2>::findPos(const TypeClef &p_x)
  {
    unsigned int	pos = m_myhash1(p_x) % m_tab.size();
    unsigned int	i = 0;

    while (m_tab[pos].m_key != p_x)
      {
	pos = (pos + (m_myhash1(p_x) + i * m_myhash2(p_x))) % m_tab.size();
	if (m_tab[pos].m_info != ACTIVE)
	  return pos;
	++i;
      }
    throw std::logic_error("logic_error : aucune place vacante trouvee dans la table");
  }


  /**
   *  \brief Insertion d'une paire (clé, valeur) dans la table de dispersion
   *
   *  Une redispersion quadratique serait utilisée en cas de collision
   *  La méthode fait appel à la méthode privée findPos() pour localiser
   *  une place vacante dans la table de dispersion.
   *
   * Si, après une insertion, le taux de remplissage atteint le maximum, on double la taille
   * de la table de dispersion en appelant (dans la méthode inert()) rehash().
   *
   * \pre la clé à insérer n'est pas déjà présente dans la table
   * \post La paire a été insérée dans la table
   * \exception logic_error si la clé est déjà dans la table
   */
  template<typename TypeClef, typename T, class FoncHachage1, class FoncHachage2>
  void		HashTableD<TypeClef, T, FoncHachage1, FoncHachage2>::insert(const TypeClef &p_x, const T &p_val)
  {
    if (contains(p_x) == true)
      throw std::logic_error("logic_error : la clef est deja dans la table.");
    
    HashEntry  	newEntry(p_x, p_val);
    newEntry.m_info = ACTIVE;
    
    if (m_tab[m_myhash1(p_x) % m_tab.size()].m_info == ACTIVE)
      m_tab[findPos(p_x)] = newEntry;
    else
      m_tab[m_myhash1(p_x) % m_tab.size()] = newEntry;

    ++m_currentSize;
    if (m_currentSize >= (m_tab.size() * m_TAUX_MAX / 100))
      rehash();
  }


  /**
   *  \brief Supprimer un élément de la table
   *
   * \pre la clé à supprimer doit être présente dans la table
   * \post La table comprend un élément de moins
   * \exception logic_error si la clé n'est pas dans la table
   */
  template<typename TypeClef, typename T, class FoncHachage1, class FoncHachage2>
  void		HashTableD<TypeClef, T, FoncHachage1, FoncHachage2>::remove(const TypeClef &p_x)
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


}
  

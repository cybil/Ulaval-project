/**
 * \file FileTableau.inl
 * \brief Le code des opérateurs de la file.
 * \author Abder revise Thierry
 * \version 1.0
 * \brief correction operator[], ecritures non standard vs->g++, return(s) mal places
 * \date octobre 2012
 *
 * Implémentation de la classe générique File dans un tableau dynamique
 */

/**
 * \fn File<T>::File(int max) throw(std::bad_alloc)
 *
 * \param[in] max La taille de la file
 */
template<typename T>
File<T>::File(int max) throw (std::bad_alloc)
{
  tete = 0;
  queue = 0;
  cpt = 0;
  tailleMax = max;
  tab = new T[max];
}

/**
 * \fn File<T>::File(const File &source) throw(std::bad_alloc)
 *
 * \param[in] source La file source
 */
template<typename T>
File<T>::File(const File &source) throw (std::bad_alloc)
{
  tete = source.tete;
  queue = source.queue;
  cpt = source.cpt;
  tailleMax = source.tailleMax;
  tab = new T[tailleMax];

  for (int temp = 0; temp < source.cpt; temp++)
    tab[temp] = source.tab[temp];
}

/**
 * \fn File<T>::~File()
 */
template<typename T>
File<T>::~File()
{
  delete[] tab;
  cpt = 0;
}

/**
 * \fn void File<T>::enfiler(const T& elementAEnfiler)throw (std::length_error)
 *
 * \param[in] elementAEnfiler Élément à enfiler
 */
template<typename T>
void File<T>::enfiler(const T& elementAEnfiler) throw (std::length_error)
{
  // enfiler un élément dans la file
  if (cpt < tailleMax)
    {
      tab[queue] = elementAEnfiler;
      queue = (queue + 1) % tailleMax;
      cpt++;
    }
  else
    throw std::length_error("Enfiler: la file est pleine\n");

}

/**
 * \fn T File<T>::defiler()throw(std::logic_error)
 *
 * \return T - Élément défilé
 */
template<typename T>
T File<T>::defiler() throw (std::logic_error)
{
  T elementaDefiler;
  // defiler un élément dans la file
  if (cpt != 0)
    {
      elementaDefiler = tab[tete];
      tete = (tete + 1) % tailleMax;
      cpt--;
      return elementaDefiler;
    }
  else
    throw std::logic_error("Defiler: La file est vide!");

}

/**
 * \fn  int File<T>:: taille() const
 *
 * \return Une copie de T, l'élément en tête de file
 */
template<typename T>
int File<T>::taille() const
{
  return cpt;
}

/**
 * \fn  bool File<T>::estVide() const
 *
 * \return true ou false
 */
template<typename T>
bool File<T>::estVide() const
{
  return cpt == 0;
}

/**
 * \fn  bool File<T>::estPleine()const
 *
 * \return true ou false
 */
template<typename T>
bool File<T>::estPleine() const
{
  return cpt == tailleMax;
}

/**
 * \fn const T& File<T>:: premier()throw (std::logic_error)
 *
 * \return Une copie de T, l'élément en tête de file
 */
template<typename T>
const T& File<T>::premier() const throw (std::logic_error)
{
  if (cpt == 0)
    {
      throw std::logic_error("Premier: la file est vide!");
    }
  return tab[tete];
}

/**
 * \fn const T& File<T>:: dernier()throw (std::logic_error)
 *
 * \return Une copie de T, l'élément en queue de file
 */
template<typename T>
const T& File<T>::dernier() throw (std::logic_error)
// retourne un élément de la file
{
  if (cpt == 0)
    {
      throw std::logic_error("Dernier: la file est vide!");
    }
  return tab[queue - 1];
}

/**
 * \fn const T& File<T>::operator [](int indice) const throw (std::out_of_range)
 *
 * \param[in] indice L'indice de l'élément
 * \return T - Element recherche
 */
template<typename T>
const T& File<T>::operator [](int indice) const throw (std::out_of_range)
{
  if ((indice < 0) || (indice > tailleMax))
    {
      throw std::out_of_range("Operateur []:Debordement d'indice");
    }
  return tab[indice];
}

/**
 * \fn const File<T>& File<T>::operator = (const File<T>& f) throw(std::bad_alloc)
 *
 * \param[in] f La pile qu'on veut affecter
 * \return Une file, copie profonde de la source
 */
template<typename T>
const File<T>& File<T>::operator =(const File<T>& f) throw (std::bad_alloc)
{
  if (tab != 0)
    delete[] tab; //nettoyer ...
  tab = new T[f.tailleMax];
  for (int i = 0; i < f.cpt; i++)
    tab[i] = f.tab[i];
  tailleMax = f.tailleMax;
  cpt = f.cpt;
  tete = f.tete;
  queue = f.queue;

  return (*this);
}

/**
 * \fn std::ostream& operator << (std::ostream& f, const File<T>& q)
 *
 * \param[in, out] f Le flux de sortie
 * \param[in] q Une file
 * \return Une référence sur le flux de sortie
 */
template<typename T>
std::ostream& operator <<(std::ostream& f, const File<T>& q)
{
  for (int i = 0; i < q.cpt; i++)
    f << q.tab[i] << " ";
  return f;
}


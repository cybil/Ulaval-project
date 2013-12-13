#include <stdexcept>
#include <exception>
#include "ArbreAVL.h"

// ******************
// Constructeur / Destructeur Noeud
// ******************

//! \brief Constructeur par parametre
//! \param[in] p_clef la clef du noeud
//! \param[in] p_valeur la valeur du noeud
//! \post un noeud typique est initialise
template<typename TypeCle, typename TypeValeur>
ArbreAVL< TypeCle, TypeValeur >::Noeud::Noeud(const TypeCle &p_cle, const TypeValeur &p_valeur)
  : m_cle(p_cle), m_valeur(p_valeur), m_gauche(NULL), m_droite(NULL), m_hauteur(0)
{
}

//! \brief Destructeur par defaut
//! \post une instance de l'arbre est detruite
template<typename TypeCle, typename TypeValeur>
ArbreAVL< TypeCle, TypeValeur >::Noeud::~Noeud()
{

}

// ******************
// Constructeur / Destructeur ArbreAVL
// ******************

//! \brief Constructeur
//! \post une instance de la classe ArbreAVL est initialisee
template<typename TypeCle, typename TypeValeur>
ArbreAVL<TypeCle, TypeValeur>::ArbreAVL()
  : m_cardinalite(0), m_racine(NULL)
{

}

//! \brief Constructeur par copie (appelle _copier)
//! \param[in] p_source un autre arbre
//! \pre Il doit y avoir assez de memoire
//! \post une copie profonde de l'arbre p_source est instanciee
//! \exception bad_alloc si pas assez de memoire
template<typename TypeCle, typename TypeValeur>
ArbreAVL<TypeCle, TypeValeur>::ArbreAVL(const ArbreAVL<TypeCle, TypeValeur> &p_source)
{
  m_cardinalite = p_source.m_cardinalite;
  m_racine = _copier(p_source.m_racine);
}

//! \brief Destructeur
//! \post l'instance de l'arbre est detruite
template<typename TypeCle, typename TypeValeur>
ArbreAVL<TypeCle, TypeValeur>::~ArbreAVL()
{
  _detruire(m_racine);
}

// ******************
// Surcharges d'operateur
// ******************

//! \brief Surcharge de l'operateur =
//! \param[in] p_arbre une reference constante sur l'arbre a copier
//! \pre Il y a assez de memoire pour l'operation
//! \post Une copie profonde de l'arbre est cree
//! \post Une reference sur l'element courant est retournee
//! \exception bad_alloc si pas assez de memoire
template<typename TypeCle, typename TypeValeur>
ArbreAVL<TypeCle, TypeValeur>	&ArbreAVL<TypeCle, TypeValeur>::operator=(const ArbreAVL<TypeCle, TypeValeur> &p_arbre)
{
  ArbreAVL< TypeCle, TypeValeur > newArbre = new ArbreAVL();

  newArbre.m_racine = _copier(p_arbre.m_racine);
  newArbre.m_cardinalite = p_arbre.m_cardinalite;
  return newArbre;
}

//! \brief Surcharge de l'operateur ==
//! \param[in] p_arbre arbre avec lequel est effectue la comparaison
//! \post Les deux arbres sont inchanges
//! \return True si identique sinon false
template<typename TypeCle, typename TypeValeur>
bool ArbreAVL<TypeCle, TypeValeur>::operator==(const ArbreAVL<TypeCle, TypeValeur> &p_arbre) const
{

}

//! \brief Verifier si l'arbre est vide
//! \return true si l'arbre est vide sinon false
template<typename TypeCle, typename TypeValeur>
bool ArbreAVL<TypeCle, TypeValeur>::estVide() const
{
  return m_cardinalite == 0;
}

//! \brief Retourner le nombre d'element dans l'arbre
//! \post L'arbre est inchange
//! \return le nombre d'elements dans l'arbre
template<typename TypeCle, typename TypeValeur>
long ArbreAVL<TypeCle, TypeValeur>::taille() const
{
  return m_cardinalite;
}

//! \brief Retourner la hauteur de l'arbre
//! \brief La determination de la hauteur se fait par parcours de l'arbre
//! \pre l'arbre n'est pas vide
//! \post l'arbre est inchange
//! \return la hauteur de l'arbre
//! \exception logic_error si l'arbre est vide
template<typename TypeCle, typename TypeValeur>
int ArbreAVL<TypeCle, TypeValeur>::hauteur() const
{
  if (estVide())
    throw std::logic_error("Hauteur: l'arbre est vide");
  return m_racine->m_hauteur;
}

//! \brief Verifier si un element est dans l'arbre
//! \param[in] p_cle la cle de l'element recherche
//! \post l'arbre est inchange
//! \return true si l'element est dans l'arbre sinon false
template<typename TypeCle, typename TypeValeur>
bool ArbreAVL<TypeCle, TypeValeur>::appartient(const TypeCle &p_cle) const
{
  return _auxAppartient(m_racine, p_cle) != NULL;
}

//! \brief Retourner le parent d'un element
//! \param[in] p_cle la cle de l'element dont on desir obtenir les informations de son parent
//! \pre l'arbre n'est pas vide
//! \pre l'element fait partie de l'arbre
//! \post l'arbre est inchange
//! \return une paire de Cle, Valeur du parent de l'element parent
//! \exception logic_error si l'arbre est vide
//! \exception logic_error si l'element n'est pas dans l'arbre
template<typename TypeCle, typename TypeValeur>
std::pair<TypeCle, TypeValeur> ArbreAVL<TypeCle, TypeValeur>::parent(const TypeCle &p_cle)
{
	if (estVide())
		throw std::logic_error("L'arbre est vide");
	if (_auxAppartient(m_racine, p_cle) == NULL)
		throw std::logic_error("La cle n'existe pas dans l'arbre");
	Noeud* parentDeEl = _parent(m_racine, p_cle);
	return parentDeEl->m_cle;
}

//! \brief Retourner le successeur d'un element
//! \param[in] p_cle la cle de l'element dont on veut le successeur
//! \pre l'arbre n'est pas vide
//! \pre l'element fait partie de l'arbre
//! \pre l'element n'est pas le maximum dans l'arbre
//! \post l'arbre est inchange
//! \return une paire Cle, Valeur du successeur de l'element
//! \exception logic_error si les preconditions ne sont pas respectees
template<typename TypeCle, typename TypeValeur>
std::pair<TypeCle, TypeValeur> ArbreAVL<TypeCle, TypeValeur>::successeur(const TypeCle &p_cle)
{
  Noeud * tmp;
  if (estVide())
    throw std::logic_error("Successeur: l'arbre est vide");
  if (appartient(p_cle) == false)
    throw std::logic_error("Successeur: la cle n'existe pas dans l'arbre");
  tmp = _max(m_racine);
  if (tmp->m_cle == p_cle)
    throw std::logic_error("Successeur: cet element est le maximum de l'arbre");
}

//! \brief Trouver une valeur a une cle donnee
//! \param[in] p_cle la cle de l'element recherche
//! \return la valeur de l'element recherche
template<typename TypeCle, typename TypeValeur>
TypeValeur ArbreAVL<TypeCle, TypeValeur>::valeur(const TypeCle &p_cle) const
{
  return _valeur(p_cle, m_racine);
}

//! \brief Recherche de l'adresse d'un element dans l'arbre
//! \param[in] p_cle la cle de l'element recherche
//! \pre l'element doit exister
//! \return la cle de l'element recherche
//! \exception logic_error si l'element n'existe pas
template<typename TypeCle, typename TypeValeur>
TypeCle * ArbreAVL<TypeCle, TypeValeur>::cle(const TypeCle &p_cle)
{

}

//! \brief Lister un arbre en ordre
//! \pre Il y a assez de memoire
//! \post l'arbre est inchange
//! \return un vector de paire contenant les couples de Cle, Valeur
//! \exception bad_alloc si il n'y a pas assez de memoire
template<typename TypeCle, typename TypeValeur>
std::vector<std::pair<TypeCle, TypeValeur> > ArbreAVL<TypeCle, TypeValeur>::lister() const
{

}

//! \brief Lister un arbre pre-ordre
//! \pre Il y a assez de memoire
//! \post l'arbre est inchange
//! \return un vector de paire contenant les couples de Cle, Valeur
//! \exception bad_alloc si il n'y a pas assez de memoire
template<typename TypeCle, typename TypeValeur>
std::vector<std::pair<TypeCle, TypeValeur> > ArbreAVL<TypeCle, TypeValeur>::listerPreOrdre() const
{

}

template<typename TypeCle, typename TypeValeur>
void ArbreAVL<TypeCle, TypeValeur>::valider() const
{

}

//! \brief Insertion dans l'ordre de tri avec balancement
//! \pre Il doit y avoir assez de memoire
//! \param[in] p_cle la cle de l'element a inserer
//! \param[in] p_valeur la valeur de l'element a inserer
//! \exception bad_alloc si pas assez de memoire
template<typename TypeCle, typename TypeValeur>
void ArbreAVL<TypeCle, TypeValeur>::inserer(const TypeCle &p_cle, const TypeValeur &p_valeur)
{
  _inserer(m_racine, p_cle, p_valeur);
}

//! \brief Enlever un element dans l'arbre tout en conservant le balancement
//! \param[in] p_cle la cle de l'element a enlever
//! \exception logic_error si l'element n'existe pas
template<typename TypeCle, typename TypeValeur>
void ArbreAVL<TypeCle, TypeValeur>::enlever(const TypeCle &p_cle)
{
  _enlever(m_racine, p_cle);
}


//******************
// Methodes privees
//******************

//! \brief Retourne le plus grand nombre
//! \param[in] p_premier le premier nombre a comparer
//! \param[in] p_second le second nombre a comparer
//! \return le plus grand des deux nombres
template<typename TypeCle, typename TypeValeur>
int ArbreAVL<TypeCle, TypeValeur>::_maximum(int p_premier, int p_second) const
{
  return p_premier > p_second ? p_premier : p_second;
}

template<typename TypeCle, typename TypeValeur>
typename ArbreAVL<TypeCle, TypeValeur>::Noeud * ArbreAVL<TypeCle, TypeValeur>::_max(ArbreAVL<TypeCle, TypeValeur>::Noeud *p_racine)
{
	if (estVide())
		throw std::logic_error("max: l'arbre est vide!\n");
	if (!p_racine->m_droite)
		return p_racine;
	Noeud * temp = p_racine->m_droite;
	while (temp->m_droite)
		temp = temp->m_droite;
	return temp;
}

template<typename TypeCle, typename TypeValeur>
typename ArbreAVL<TypeCle, TypeValeur>::Noeud * ArbreAVL<TypeCle, TypeValeur>::_min(ArbreAVL<TypeCle, TypeValeur>::Noeud *p_racine)
{
	if (estVide())
		throw std::logic_error("max: l'arbre est vide!\n");
	if (p_racine->m_gauche == 0)
		return p_racine;
	Noeud * temp = p_racine->m_gauche;
	while (temp->m_gauche)
		temp = temp->m_gauche;
	return temp;
}

template<typename TypeCle, typename TypeValeur>
typename ArbreAVL<TypeCle, TypeValeur>::Noeud * ArbreAVL<TypeCle, TypeValeur>::_copier(ArbreAVL<TypeCle, TypeValeur>::Noeud *p_noeud)
{

}

//! \brief Detruit un arbre
//! \param[in] p_racine le noeud a partir duquel on veut demarrer la destruction
template<typename TypeCle, typename TypeValeur>
void ArbreAVL<TypeCle, TypeValeur>::_detruire(ArbreAVL<TypeCle, TypeValeur>::Noeud *p_racine)
{

}
  
template<typename TypeCle, typename TypeValeur>
typename ArbreAVL<TypeCle, TypeValeur>::Noeud * ArbreAVL<TypeCle, TypeValeur>::_trouver(const TypeCle &p_cle, Noeud *&p_noeud)
{

}

//! \param[in] p_racine la racine de l'arbre ou chercher
//! \param[in] p_cle la cle de l'element recherche
//! \return pointeur sur l'element recherche ou NULL s'il n'existe pas
template<typename TypeCle, typename TypeValeur>
typename ArbreAVL<TypeCle, TypeValeur>::Noeud * ArbreAVL<TypeCle, TypeValeur>::_auxAppartient(ArbreAVL<TypeCle, TypeValeur>::Noeud *p_racine, const TypeCle &p_cle) const
{
  if (estVide())
    return NULL;
  if (p_racine->m_cle == p_cle)
    return p_racine;
  if (p_racine->m_cle > p_cle)
    return _auxAppartient(p_racine->m_gauche, p_cle);
  return _auxAppartient(p_racine->m_droite, p_cle);
}

//! \param[in] p_cle la cle de l'element recherche
//! \param[in] p_racine racine de l'arbre dans lequel on recherche
//! \return la valeur de l'element recherche
template<typename TypeCle, typename TypeValeur>
TypeValeur ArbreAVL<TypeCle, TypeValeur>::_valeur(const TypeCle &p_cle, ArbreAVL<TypeCle, TypeValeur>::Noeud *&p_racine) const
{

}

//! \param[in] p_racine la racine de l'arbre ou inserer l'element
//! \param[in] p_cle la cle de l'element a inserer
//! \param[in] p_valeur la valeur de l'element a inserer
template<typename TypeCle, typename TypeValeur>
void ArbreAVL<TypeCle, TypeValeur>::_inserer(ArbreAVL<TypeCle, TypeValeur>::Noeud *&p_racine, const TypeCle &p_cle, const TypeValeur &p_valeur)
{
  if (estVide())
    {
      p_racine = new Noeud(p_cle, p_valeur);
      m_cardinalite++;
      return;
    }
  if (p_racine->m_cle > p_cle)
    {
      _inserer(p_racine->m_gauche, p_cle, p_valeur);
      if ((_hauteur(p_racine->m_gauche) - _hauteur(p_racine->m_droite)) == 2)
	{
	  if (p_racine->m_gauche->m_cle > p_cle)
	    _zigZigGauche(p_racine);
	  else 
	    _zigZagGauche(p_racine);
	}
      else
	p_racine->m_hauteur = 1 + _maximum(_hauteur(p_racine->m_gauche), _hauteur(p_racine->m_droite));
    }
  else
    {
      _inserer(p_racine->m_droite, p_cle, p_valeur);
      if ((_hauteur(p_racine->m_droite) - _hauteur(p_racine->m_gauche)) == 2)
	{
	  if (p_racine->m_droite->m_cle > p_cle)
	    _zigZigDroit(p_racine);
	  else
	    _zigZagDroit(p_racine);
	}
      else
	p_racine->m_hauteur = 1 + _maximum(_hauteur(p_racine->m_droite),
					   _hauteur(p_racine->m_gauche));
    }
}

//! \param[in] p_cle la cle du noeud que l'on veut enlever
//! \param[in] p_racine la racine de l'arbre ou enlever l'element
template<typename TypeCle, typename TypeValeur>
void ArbreAVL<TypeCle, TypeValeur>::_enlever(const TypeCle &p_cle, ArbreAVL<TypeCle, TypeValeur>::Noeud *&p_racine)
{
  if (p_racine->m_cle > p_cle)
    _enlever(p_cle, p_racine->m_gauche);
  else if (p_racine->m_cle < p_cle)
    _enlever(p_cle, p_racine->m_droite);
  else if (p_racine->m_gauche != NULL && p_racine->m_droite != NULL)
    {
      Noeud	       *tmp = p_racine->m_droite;
      while (tmp->m_gauche != NULL)
	tmp = tmp->m_gauche;
      p_racine->m_cle = tmp->m_cle;
      _auxRetireMin(p_racine->m_droite);
    }
  else
    {
      Noeud		*vieuxNoeud = p_racine;
      p_racine = (p_racine->m_gauche != NULL) ? p_racine->m_gauche : p_racine->m_droite;
      delete vieuxNoeud;
    }
  _balancer(p_racine);
}

template<typename TypeCle, typename TypeValeur>
void		ArbreAVL<TypeCle, TypeValeur>::_auxRetireMin(ArbreAVL<TypeCle, TypeValeur>::Noeud *&p_noeud)
{
  if (p_noeud == NULL)
    throw std::logic_error("RetireMin: pointeur NULL");
  else if (p_noeud->m_gauche != NULL)
    _auxRetireMin(p_noeud->m_gauche);
  else
    {
      Noeud		*tmp = p_noeud;
      p_noeud = p_noeud->m_droite;
      delete tmp;
    }
}

//! \param[in] p_racine la noeud dont on veut faire un rebalancement si necessaire
template<typename TypeCle, typename TypeValeur>
void ArbreAVL<TypeCle, TypeValeur>::_balancer(ArbreAVL<TypeCle, TypeValeur>::Noeud *&p_racine)
{

}

//! \brief Cas de balancement zig zag droit
//! \param[in] p_noeudCritique le noeud qu'il faut deplacer
template<typename TypeCle, typename TypeValeur>
void ArbreAVL<TypeCle, TypeValeur>::_zigZagDroit(ArbreAVL<TypeCle, TypeValeur>::Noeud *&p_noeudCritique)
{
	_zigZigGauche(p_noeudCritique->m_droite);
	_zigZigDroit(p_noeudCritique);
}

//! \brief Cas de balancement zig zag gauche
//! \param[in] p_noeudCritique le noeud qu'il faut deplacer
template<typename TypeCle, typename TypeValeur>
void ArbreAVL<TypeCle, TypeValeur>::_zigZagGauche(ArbreAVL<TypeCle, TypeValeur>::Noeud *&p_noeudCritique)
{
	_zigZigDroit(p_noeudCritique->m_gauche);
	_zigZigGauche(p_noeudCritique);
}

//! \brief Cas de balancement zig zig droit
//! \param[in] p_noeudCritique le noeud qu'il faut deplacer
template<typename TypeCle, typename TypeValeur>
void ArbreAVL<TypeCle, TypeValeur>::_zigZigDroit(ArbreAVL<TypeCle, TypeValeur>::Noeud *&p_noeudCritique)
{
	Noeud * tmp;
	tmp = p_noeudCritique->m_droite;
	p_noeudCritique->m_droite = tmp->m_gauche;
	tmp->m_gauche = p_noeudCritique;
	p_noeudCritique->m_hauteur = 1 + _maximum(_hauteur(p_noeudCritique->m_droite), _hauteur(p_noeudCritique->m_gauche));
	tmp->m_hauteur = 1 + _maximum(_hauteur(tmp->m_droite), p_noeudCritique->m_hauteur);
	p_noeudCritique = tmp;
}

//! \brief Cas de balancement zig zig gauche
//! \param[in] p_noeudCritique le noeud qu'il faut deplacer
template<typename TypeCle, typename TypeValeur>
void ArbreAVL<TypeCle, TypeValeur>::_zigZigGauche(ArbreAVL<TypeCle, TypeValeur>::Noeud *&p_noeudCritique)
{
	Noeud * tmp;
  tmp = p_noeudCritique->m_gauche;
  p_noeudCritique->m_gauche = tmp->m_droite;
  tmp->m_droite = p_noeudCritique;
  p_noeudCritique->m_hauteur = 1 + _maximum(_hauteur(p_noeudCritique->m_gauche),_hauteur(p_noeudCritique->m_droite));
  tmp->m_hauteur = 1 + _maximum(_hauteur(tmp->m_gauche),p_noeudCritique->m_hauteur);
  p_noeudCritique = tmp;
}

//! \param[in] p_noeud le noeud dont on desire obtenir la hauteur
//! \return la hauteur du noeud passe en parametre
template<typename TypeCle, typename TypeValeur>
int ArbreAVL<TypeCle, TypeValeur>::_hauteur(ArbreAVL<TypeCle, TypeValeur>::Noeud *&p_noeud) const
{
  
}

//! \param[in] p_cle la cle dont on desire obtenir des informations sur son parent
//! \param[in] p_racine la racine de l'arbre dasns lequel on cherche
//! \return le noeud parent de l'element dont la cle est en parametre
template<typename TypeCle, typename TypeValeur>
typename ArbreAVL<TypeCle, TypeValeur>::Noeud			*ArbreAVL<TypeCle, TypeValeur>::_parent(const TypeCle &p_cle, ArbreAVL<TypeCle, TypeValeur>::Noeud *p_racine)
{
	Noeud * sArb = _auxAppartient(m_racine, p_cle);
	if (sArb == p_racine)
		throw std::logic_error("parent: Le parent de la racine d'existe pas!\n");
	if ( sArb->m_cle < p_racine->m_cle )
	{
		if (p_racine->m_gauche == sArb) return p_racine;
		else return _parent(p_racine->m_gauche, sArb);
	}
	else
	{
		if (p_racine->m_droite == sArb) return p_racine;
		else return _parent(p_racine->m_droite, sArb);
	}
}

//! \param[in] p_racine racine de l'arbre ou on cherche
//! \param[in] p_sArb element dont on cherche le parent
//! \return le noeud parent de l'element
template<typename TypeCle, typename TypeValeur>
typename ArbreAVL<TypeCle, TypeValeur>::Noeud * ArbreAVL<TypeCle, TypeValeur>::_successeurParent(ArbreAVL<TypeCle, TypeValeur>::Noeud *p_racine, ArbreAVL<TypeCle, TypeValeur>::Noeud *sArb)
{

}

//! \param[in] p_racine la racine de l'arbre ou l'on cherche le successeur
//! \param[in] p_cle la cle de l'element dont on cherche le successeur
//! \return le noeud parent de l'element
template<typename TypeCle, typename TypeValeur>
typename ArbreAVL<TypeCle, TypeValeur>::Noeud * ArbreAVL<TypeCle, TypeValeur>::_successeur(ArbreAVL<TypeCle, TypeValeur>::Noeud *p_racine, const TypeCle &p_cle)
{

}

//! \brief Parcours de l'arbre de facon symetrique
//! \param[in] p_racine la racine de l'arbre
//! \param[out] le vector ou l'on stocke les couples de Cle, Valeur en ordre
template<typename TypeCle, typename TypeValeur>
void ArbreAVL<TypeCle, TypeValeur>::_visiteSymetrique(ArbreAVL<TypeCle, TypeValeur>::Noeud *p_racine, std::vector<std::pair<TypeCle, TypeValeur> > &p_vecteur) const
{

}

//! \param[in] p_racine la racine de l'arbre dont on veut la hauteur
//! \return la hauteur de l'arbre dont la racine est passee en parametre
template<typename TypeCle, typename TypeValeur>
int ArbreAVL<TypeCle, TypeValeur>::_hauteurParcours(ArbreAVL<TypeCle, TypeValeur>::Noeud *p_racine) const
{
	if (estVide())
		return -1;
	return 1 + _maximum(_hauteur(p_racine->m_gauche), _hauteur(p_racine->m_droite));
}

//! \param[in] p_racine la racine de l'arbre parcouru
//! \param[out] structure ou stocker les elements parcourus 
template<typename TypeCle, typename TypeValeur>
void ArbreAVL<TypeCle, TypeValeur>::_auxPreOrdre(ArbreAVL<TypeCle, TypeValeur>::Noeud *p_racine, std::vector<std::pair<TypeCle, TypeValeur> > &p_vecteur) const
{

}

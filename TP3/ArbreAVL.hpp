
#include "ArbreAVL.h"

//! \brief Constructeur
//! \post une instance de la classe ArbreAVL est initialisee
template<typename TypeCle, typename TypeValeur>
ArbreAVL<TypeCle, TypeValeur>::ArbreAVL()
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

}

//! \brief Destructeur
//! \post l'instance de l'arbre est detruite
template<typename TypeCle, typename TypeValeur>
ArbreAVL<TypeCle, TypeValeur>::~ArbreAVL()
{

}

//! \brief Surcharge de l'operateur =
//! \param[in] p_arbre une reference constante sur l'arbre a copier
//! \pre Il y a assez de memoire pour l'operation
//! \post Une copie profonde de l'arbre est cree
//! \post Une reference sur l'element courant est retournee
//! \exception bad_alloc si pas assez de memoire
template<typename TypeCle, typename TypeValeur>
ArbreAVL<TypeCle, TypeValeur>	&ArbreAVL<TypeCle, TypeValeur>::operator=(const ArbreAVL<TypeCle, TypeValeur> &p_arbre)
{

}

//! \brief Surcharge de l'operateur ==
//! \param[in] p_arbre arbre avec lequel est effectue la comparaison
//! \post Les deux arbres sont inchanges
//! \return True si identique sinon false
template<typename TypeCle, typename TypeValeur>
bool				ArbreAVL<TypeCle, TypeValeur>::operator==(const ArbreAVL<TypeCle, TypeValeur> &p_arbre) const
{

}

//! \brief Verifier si l'arbre est vide
//! \return true si l'arbre est vide sinon false
template<typename TypeCle, typename TypeValeur>
bool				ArbreAVL<TypeCle, TypeValeur>::estVide() const
{

}

//! \brief Retourner le nombre d'element dans l'arbre
//! \post L'arbre est inchange
//! \return le nombre d'elements dans l'arbre
template<typename TypeCle, typename TypeValeur>
long				ArbreAVL<TypeCle, TypeValeur>::taille() const
{

}

//! \brief Retourner la hauteur de l'arbre
//! \brief La determination de la hauteur se fait par parcours de l'arbre
//! \pre l'arbre n'est pas vide
//! \post l'arbre est inchange
//! \return la hauteur de l'arbre
//! \exception logic_error si l'arbre est vide
template<typename TypeCle, typename TypeValeur>
int				ArbreAVL<TypeCle, TypeValeur>::hauteur() const
{

}

//! \brief Verifier si un element est dans l'arbre
//! \param[in] p_cle la cle de l'element recherche
//! \post l'arbre est inchange
//! \return true si l'element est dans l'arbre sinon false
template<typename TypeCle, typename TypeValeur>
bool				ArbreAVL<TypeCle, TypeValeur>::appartient(const TypeCle &p_cle) const
{

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

}

//! \brief Trouver une valeur a une cle donnee
//! \param[in] p_cle la cle de l'element recherche
//! \return la valeur de l'element recherche
template<typename TypeCle, typename TypeValeur>
TypeValeur			ArbreAVL<TypeCle, TypeValeur>::valeur(const TypeCle &p_cle) const
{

}

//! \brief Recherche de l'adresse d'un element dans l'arbre
//! \param[in] p_cle la cle de l'element recherche
//! \pre l'element doit exister
//! \return la cle de l'element recherche
//! \exception logic_error si l'element n'existe pas
template<typename TypeCle, typename TypeValeur>
TypeCle			*ArbreAVL<TypeCle, TypeValeur>::cle(const TypeCle &p_cle)
{

}

//! \brief Lister un arbre en ordre
//! \pre Il y a assez de memoire
//! \post l'arbre est inchange
//! \return un vector de paire contenant les couples de Cle, Valeur
//! \exception bad_alloc si il n'y a pas assez de memoire
template<typename TypeCle, typename TypeValeur>
std::vector<std::pair<TypeCle, TypeValeur> >	ArbreAVL<TypeCle, TypeValeur>::lister() const
{

}

//! \brief Lister un arbre pre-ordre
//! \pre Il y a assez de memoire
//! \post l'arbre est inchange
//! \return un vector de paire contenant les couples de Cle, Valeur
//! \exception bad_alloc si il n'y a pas assez de memoire
template<typename TypeCle, typename TypeValeur>
std::vector<std::pair<TypeCle, TypeValeur> >	ArbreAVL<TypeCle, TypeValeur>::listerPreOrdre() const
{

}

template<typename TypeCle, typename TypeValeur>
void				ArbreAVL<TypeCle, TypeValeur>::valider() const
{

}

//! \brief Insertion dans l'ordre de tri avec balancement
//! \pre Il doit y avoir assez de memoire
//! \param[in] p_cle la cle de l'element a inserer
//! \param[in] p_valeur la valeur de l'element a inserer
//! \exception bad_alloc si pas assez de memoire
template<typename TypeCle, typename TypeValeur>
void				ArbreAVL<TypeCle, TypeValeur>::inserer(const TypeCle &p_cle, const TypeValeur &p_valeur)
{

}

//! \brief Enlever un element dans l'arbre tout en conservant le balancement
//! \param[in] p_cle la cle de l'element a enlever
//! \exception logic_error si l'element n'existe pas
template<typename TypeCle, typename TypeValeur>
void				ArbreAVL<TypeCle, TypeValeur>::enlever(const TypeCle &p_cle)
{

}



#ifndef		ARBREAVL_H__
#define		ARBREAVL_H__

#include <vector>
#include <utility>

template<typename TypeCle, typename TypeValeur>
class ArbreAVL
{
public :

  class Noeud
  {
  public:
    //! \brief Constructeur par parametre
    //! \param[in] p_clef la clef du noeud
    //! \param[in] p_valeur la valeur du noeud
    //! \post un noeud typique est initialise
    Noeud(const TypeCle &p_cle, const TypeValeur &p_valeur);

    //! \brief La cle du noeud
    TypeCle		m_cle;

    //! \brief La valeur du noeud 
    TypeValeur		m_valeur;

    //! \brief Pointe vers le fils gauche
    Noeud		*m_gauche;

    //! \brief Pointe vers le fils droit
    Noeud		*m_droite;

    //! \brief La hauteur du noeud, utile pour le balancement
    int			m_hauteur;

  };

  //! \brief Constructeur
  //! \post une instance de la classe ArbreAVL est initialisee
  ArbreAVL();

  //! \brief Constructeur par copie (appelle _copier)
  //! \param[in] p_source un autre arbre
  //! \pre Il doit y avoir assez de memoire
  //! \post une copie profonde de l'arbre p_source est instanciee
  //! \exception bad_alloc si pas assez de memoire
  ArbreAVL(const ArbreAVL<TypeCle, TypeValeur> &p_source);

  //! \brief Destructeur
  //! \post l'instance de l'arbre est detruite
  ~ArbreAVL();

  //! \brief Surcharge de l'operateur =
  //! \param[in] p_arbre une reference constante sur l'arbre a copier
  //! \pre Il y a assez de memoire pour l'operation
  //! \post Une copie profonde de l'arbre est cree
  //! \post Une reference sur l'element courant est retournee
  //! \exception bad_alloc si pas assez de memoire
  ArbreAVL<TypeCle, TypeValeur>	&operator=(const ArbreAVL<TypeCle, TypeValeur> &p_arbre);

  //! \brief Surcharge de l'operateur ==
  //! \param[in] p_arbre arbre avec lequel est effectue la comparaison
  //! \post Les deux arbres sont inchanges
  //! \return True si identique sinon false
  bool				operator==(const ArbreAVL<TypeCle, TypeValeur> &p_arbre) const;

  //! \brief Verifier si l'arbre est vide
  //! \return true si l'arbre est vide sinon false
  bool				estVide() const;

  //! \brief Retourner le nombre d'element dans l'arbre
  //! \post L'arbre est inchange
  //! \return le nombre d'elements dans l'arbre
  long				taille() const;

  //! \brief Retourner la hauteur de l'arbre
  //! \brief La determination de la hauteur se fait par parcours de l'arbre
  //! \pre l'arbre n'est pas vide
  //! \post l'arbre est inchange
  //! \return la hauteur de l'arbre
  //! \exception logic_error si l'arbre est vide
  int				hauteur() const;

  //! \brief Verifier si un element est dans l'arbre
  //! \param[in] p_cle la cle de l'element recherche
  //! \post l'arbre est inchange
  //! \return true si l'element est dans l'arbre sinon false
  bool				appartient(const TypeCle &p_cle) const;

  //! \brief Retourner le parent d'un element
  //! \param[in] p_cle la cle de l'element dont on desir obtenir les informations de son parent
  //! \pre l'arbre n'est pas vide
  //! \pre l'element fait partie de l'arbre
  //! \post l'arbre est inchange
  //! \return une paire de Cle, Valeur du parent de l'element parent
  //! \exception logic_error si l'arbre est vide
  //! \exception logic_error si l'element n'est pas dans l'arbre
  std::pair<TypeCle, TypeValeur> parent(const TypeCle &p_cle);

  //! \brief Retourner le successeur d'un element
  //! \param[in] p_cle la cle de l'element dont on veut le successeur
  //! \pre l'arbre n'est pas vide
  //! \pre l'element fait partie de l'arbre
  //! \pre l'element n'est pas le maximum dans l'arbre
  //! \post l'arbre est inchange
  //! \return une paire Cle, Valeur du successeur de l'element
  //! \exception logic_error si les preconditions ne sont pas respectees
  std::pair<TypeCle, TypeValeur> successeur(const TypeCle &p_cle);

  //! \brief Trouver une valeur a une cle donnee
  //! \param[in] p_cle la cle de l'element recherche
  //! \return la valeur de l'element recherche
  TypeValeur			valeur(const TypeCle &p_cle) const;

  //! \brief Recherche de l'adresse d'un element dans l'arbre
  //! \param[in] p_cle la cle de l'element recherche
  //! \pre l'element doit exister
  //! \return la cle de l'element recherche
  //! \exception logic_error si l'element n'existe pas
  TypeCle			*cle(const TypeCle &p_cle);

  //! \brief Lister un arbre en ordre
  //! \pre Il y a assez de memoire
  //! \post l'arbre est inchange
  //! \return un vector de paire contenant les couples de Cle, Valeur
  //! \exception bad_alloc si il n'y a pas assez de memoire
  std::vector<std::pair<TypeCle, TypeValeur> >	lister() const;

  //! \brief Lister un arbre pre-ordre
  //! \pre Il y a assez de memoire
  //! \post l'arbre est inchange
  //! \return un vector de paire contenant les couples de Cle, Valeur
  //! \exception bad_alloc si il n'y a pas assez de memoire
  std::vector<std::pair<TypeCle, TypeValeur> >	listerPreOrdre() const;

  void				valider() const;

  //! \brief Insertion dans l'ordre de tri avec balancement
  //! \pre Il doit y avoir assez de memoire
  //! \param[in] p_cle la cle de l'element a inserer
  //! \param[in] p_valeur la valeur de l'element a inserer
  //! \exception bad_alloc si pas assez de memoire
  void				inserer(const TypeCle &p_cle, const TypeValeur &p_valeur);

  //! \brief Enlever un element dans l'arbre tout en conservant le balancement
  //! \param[in] p_cle la cle de l'element a enlever
  //! \exception logic_error si l'element n'existe pas
  void				enlever(const TypeCle &p_cle);

private :

  //! \brief Retourne le plus grand nombre
  //! \param[in] p_premier le premier nombre a comparer
  //! \param[in] p_second le second nombre a comparer
  //! \return le plus grand des deux nombres
  int				_maximum(int p_premier, int p_second) const;

  Noeud				*_max(Noeud *p_racine);
  Noeud				*_min(Noeud *p_racine);
  Noeud				*_copier(Noeud *p_noeud);

  //! \brief Detruit un arbre
  //! \param[in] p_racine le noeud a partir duquel on veut demarrer la destruction
  void				_detruire(Noeud *p_racine);

  
  Noeud				*_trouver(const TypeCle &p_cle, Noeud *&p_noeud);
  
  //! \param[in] p_racine la racine de l'arbre ou chercher
  //! \param[in] p_cle la cle de l'element recherche
  //! \return pointeur sur l'element recherche ou NULL s'il n'existe pas
  Noeud			        *_auxAppartient(Noeud *p_racine, const TypeCle &p_cle) const;

  //! \param[in] p_cle la cle de l'element recherche
  //! \param[in] p_racine racine de l'arbre dans lequel on recherche
  //! \return la valeur de l'element recherche
  TypeValeur			_valeur(const TypeCle &p_cle, Noeud *&p_racine) const;


  //! \param[in] p_racine la racine de l'arbre ou inserer l'element
  //! \param[in] p_cle la cle de l'element a inserer
  //! \param[in] p_valeur la valeur de l'element a inserer
  void				_inserer(Noeud *&p_racine, const TypeCle &p_cle,
					 const TypeValeur &p_valeur);

  //! \param[in] p_cle la cle du noeud que l'on veut enlever
  //! \param[in] p_racine la racine de l'arbre ou enlever l'element
  void				_enlever(const TypeCle &p_cle, Noeud *&p_racine);

  //! \param[in] p_racine la noeud dont on veut faire un rebalancement si necessaire
  void				_balancer(Noeud *&p_racine);

  //! \brief Cas de balancement zig zag droit
  //! \param[in] p_noeudCritique le noeud qu'il faut deplacer
  void				_zigZagDroit(Noeud *&p_noeudCritique);

  //! \brief Cas de balancement zig zag gauche
  //! \param[in] p_noeudCritique le noeud qu'il faut deplacer
  void				_zigZagGauche(Noeud *&p_noeudCritique);

  //! \brief Cas de balancement zig zig droit
  //! \param[in] p_noeudCritique le noeud qu'il faut deplacer
  void				_zigZigDroit(Noeud *&p_noeudCritique);

  //! \brief Cas de balancement zig zig gauche
  //! \param[in] p_noeudCritique le noeud qu'il faut deplacer
  void				_zigZigGauche(Noeud *&p_noeudCritique);

  //! \param[in] p_noeud le noeud dont on desire obtenir la hauteur
  //! \return la hauteur du noeud passe en parametre
  int				_hauteur(Noeud *&p_noeud) const;

  //! \param[in] p_cle la cle dont on desire obtenir des informations sur son parent
  //! \param[in] p_racine la racine de l'arbre dasns lequel on cherche
  //! \return le noeud parent de l'element dont la cle est en parametre
  Noeud				*_parent(const TypeCle &p_cle, Noeud *p_racine);

  //! \param[in] p_racine racine de l'arbre ou on cherche
  //! \param[in] p_sArb element dont on cherche le parent
  //! \return le noeud parent de l'element
  Noeud				*_successeurParent(Noeud *p_racine, Noeud *sArb);

  //! \param[in] p_racine la racine de l'arbre ou l'on cherche le successeur
  //! \param[in] p_cle la cle de l'element dont on cherche le successeur
  //! \return le noeud parent de l'element
  Noeud				*_successeur(Noeud *p_racine, const TypeCle &p_cle);

  //! \brief Parcours de l'arbre de facon symetrique
  //! \param[in] p_racine la racine de l'arbre
  //! \param[out] le vector ou l'on stocke les couples de Cle, Valeur en ordre
  void				_visiteSymetrique(Noeud *p_racine, std::vector<
						    std::pair<TypeCle,
							      TypeValeur> > &p_vecteur) const;

  //! \param[in] p_racine la racine de l'arbre dont on veut la hauteur
  //! \return la hauteur de l'arbre dont la racine est passee en parametre
  int				_hauteurParcours(Noeud *p_racine) const;

  //! \param[in] p_racine la racine de l'arbre parcouru
  //! \param[out] structure ou stocker les elements parcourus 
  void				_auxPreOrdre(Noeud *p_racine, std::vector<
					       std::pair<TypeCle,
							 TypeValeur> > &p_vecteur) const;

  // Attributs prives

  Noeud				*m_racine;
  long				m_cardinalite;

};

#endif		// !ARBREAVL_H__

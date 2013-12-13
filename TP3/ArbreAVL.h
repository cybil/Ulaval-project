
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
    Noeud(const TypeCle &p_cle, const TypeValeur &p_valeur);
    ~Noeud();

    TypeCle		m_cle;
    TypeValeur		m_valeur;
    Noeud		*m_gauche;
    Noeud		*m_droite;
    int			m_hauteur;

  };

  ArbreAVL();
  ArbreAVL(const ArbreAVL<TypeCle, TypeValeur> &p_source);
  ~ArbreAVL();

  ArbreAVL<TypeCle, TypeValeur>	&operator=(const ArbreAVL<TypeCle, TypeValeur> &p_arbre);
  bool				operator==(const ArbreAVL<TypeCle, TypeValeur> &p_arbre) const;
  bool				estVide() const;
  long				taille() const;
  int				hauteur() const;
  bool				appartient(const TypeCle &p_cle) const;
  std::pair<TypeCle, TypeValeur> parent(const TypeCle &p_cle);
  std::pair<TypeCle, TypeValeur> successeur(const TypeCle &p_cle);

  TypeValeur			valeur(const TypeCle &p_cle) const;
  TypeCle			*cle(const TypeCle &p_cle);
  std::vector<std::pair<TypeCle, TypeValeur> >	lister() const;
  std::vector<std::pair<TypeCle, TypeValeur> >	listerPreOrdre() const;

  void				valider() const;
  void				inserer(const TypeCle &p_cle, const TypeValeur &p_valeur);
  void				enlever(const TypeCle &p_cle);
  void              show() const;

private :

  void _show(Noeud const * node, int h) const;

  int				_maximum(int p_premier, int p_second) const;
  Noeud				*_max(Noeud *p_racine);
  Noeud				*_min(Noeud *p_racine);
  Noeud				*_copier(Noeud *p_noeud);
  void				_auxCopier(Noeud *p_source, Noeud *p_dest);
  void				_detruire(Noeud *p_racine);

  Noeud				*_trouver(const TypeCle &p_cle, Noeud *&p_noeud) const;
  Noeud			        *_auxAppartient(Noeud *p_racine, const TypeCle &p_cle) const;
  TypeValeur			_valeur(const TypeCle &p_cle, Noeud *&p_racine) const;
  void				_inserer(Noeud *&p_racine, const TypeCle &p_cle,
					 const TypeValeur &p_valeur);
  void				_enlever(const TypeCle &p_cle, Noeud *&p_racine);
  void				_auxRetireMin(Noeud *&p_noeud);

  void				_balancer(Noeud *&p_racine);
  void				_zigZagDroit(Noeud *&p_noeudCritique);
  void				_zigZagGauche(Noeud *&p_noeudCritique);
  void				_zigZigDroit(Noeud *&p_noeudCritique);
  void				_zigZigGauche(Noeud *&p_noeudCritique);
  int				_hauteur(Noeud *&p_noeud) const;
  Noeud				*_parent(const TypeCle &p_cle, Noeud *p_racine);
  Noeud				*_successeurParent(Noeud *p_racine, Noeud *sArb);
  Noeud				*_successeur(Noeud *p_racine, const TypeCle &p_cle);
  void				_visiteSymetrique(Noeud *p_racine, std::vector<
						    std::pair<TypeCle,
							      TypeValeur> > &p_vecteur) const;
  int				_hauteurParcours(Noeud *p_racine) const;
  void				_auxPreOrdre(Noeud *p_racine, std::vector<
					       std::pair<TypeCle,
							 TypeValeur> > &p_vecteur) const;


  // Attributs prives

  long				m_cardinalite;
  Noeud				*m_racine;
};


#include "ArbreAVL.hpp"

#endif		// !ARBREAVL_H__

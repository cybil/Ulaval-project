/**
 * \file HashTable.h
 * \brief Classe définissant une table de hachage
 * \author Abder
 * \version 0.1
 * \date mai 2011
 *
 * Résolution de collisions par adressage ouvert et sondage quadratique
 */

#ifndef _HACHAGE_TABLE
#define _HACHAGE_TABLE

#include <iostream>
#include <stdexcept>
#include <vector>
#include "Prime.h"

namespace HashTable_Lab9
{
	/**
	* \class HashTable
	*
	* \brief classe générique représentant une table de dispersion
	*
	*  La tables est implémentée dans un vector. La résolution des collisions
	*  se fait par redispersion quadratique tel que vu dans le cours.
	*/
	template<typename TypeClef, typename T, typename FoncHachage>
	// TypeClef   : le type des clefs
	// T          : le type des éléments
	// FoncHachage: classe fonction de hachage (foncteur)
	class HashTable
	{
	  public:
	 /**
	 *  \brief Constructeur  - Méthode fournie
	 *
	 * Prépare une table vide de taille 101 (un nombre premier) par défaut
	 * Sinon, l'appelant peut l'appeler avec un argument explicite, dans ce cas
	 * le constructeur doit préparer une table vide de taille = prochain nombre premier
	 * qui suit la valeur de l'argument. Utilisez la méthode nextPrime() de la classe Prime.
	 *
	 * \post Une instance de la classe HashTable est initialisée
	 */
		  HashTable( int size = 101 );

	/**
	 *  \brief Vider la table de dispersion -  Méthode fournie
	 *
	 * \post  la table est vide
	 */
		void makeEmpty( );

	/**
	 *  \brief Recherche d'un élément à partir d'une clé
	 *
	 *  Recherche dans la table de dipsersion
	 *
	 * \post VRAI est retourné si l'élément est présent, FAUX sinon
	 */
		bool contains( const TypeClef & x ) const;



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
		void insert( const TypeClef & x, const T& val );

	/**
	 *  \brief Supprimer un élément de la table
	 *
	 * \pre la clé à supprimer doit être présente dans la table
	 * \post La table comprend un élément de moins
	 * \exception logic_error si la clé n'est pas dans la table
	 */
		void remove( const TypeClef & x );

	private:

	/**
	 * \enum EntryType
	 * \brief Les tags pour définir l'état d'une entrée dans la table
	 */
		enum EntryType {
			ACTIVE, /*!< l'entrée est occupée*/
			EMPTY,	/*!< l'entrée est vide*/
			DELETED /*!< l'entrée a été supprimée*/
		};

		/**
		* \class HashEntry
		*
		* \brief Classe interne pour définir une entrée dans la table
		*/
		class HashEntry
		{
		public:
			TypeClef key;	/*!< la clé de hachage*/
			T element;		/*!< la valeur associée à la clé*/
			EntryType info; /*!< tag pour préciser l'état de l'enrée (vide, active ou supprimée) */

			/**
			 *  \brief Constructeur par défaut qui ne fait rien
			 */
			HashEntry(){}; //

			/**
			 *  \brief Constructeur avec argument pour initialiser les membres de la classe
			 */
			 HashEntry(const TypeClef& k, const T & e,  EntryType i = EMPTY )
			   : key(k), element( e ),info( i ) { }
		};

		std::vector<HashEntry> tab; /*!<  la table de hachage*/
		unsigned int currentSize;	/*!< le nombre d'éléments courant dans la table*/
		static const int TAUX_MAX = 50;	/*!< 50%:taux de remplissage maximum dans la table,
		sinon, on double sa taille. L'attribut static est pour fixer le même taux
		pour n'importe quelle instance de la classe en cas de modification*/

		/**
		 *  \brief Redimensionner la capacité de la table de dispersion - Méthode fournie
		 *
		 * Cette méthode peut être appelée par insert(). Si, après une insertion,
		 * le taux de remplissage atteint le maximum, cette méthode la taille
		 * de la table de dispersion.
		*/
		void rehash( );

		FoncHachage myhash; /*!<fonction de hachage, voir les paramètres "template" de la classe
							  ainsi que comment le main() prépare la classe FoncHachage*/
	};
}//Fin du namespace

#include "HashTable.hpp"

#endif

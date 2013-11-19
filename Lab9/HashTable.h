/**
 * \file HashTable.h
 * \brief Classe d�finissant une table de hachage
 * \author Abder
 * \version 0.1
 * \date mai 2011
 *
 * R�solution de collisions par adressage ouvert et sondage quadratique
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
	* \brief classe g�n�rique repr�sentant une table de dispersion
	*
	*  La tables est impl�ment�e dans un vector. La r�solution des collisions
	*  se fait par redispersion quadratique tel que vu dans le cours.
	*/
	template<typename TypeClef, typename T, typename FoncHachage>
	// TypeClef   : le type des clefs
	// T          : le type des �l�ments
	// FoncHachage: classe fonction de hachage (foncteur)
	class HashTable
	{
	  public:
	 /**
	 *  \brief Constructeur  - M�thode fournie
	 *
	 * Pr�pare une table vide de taille 101 (un nombre premier) par d�faut
	 * Sinon, l'appelant peut l'appeler avec un argument explicite, dans ce cas
	 * le constructeur doit pr�parer une table vide de taille = prochain nombre premier
	 * qui suit la valeur de l'argument. Utilisez la m�thode nextPrime() de la classe Prime.
	 *
	 * \post Une instance de la classe HashTable est initialis�e
	 */
		  HashTable( int size = 101 );

	/**
	 *  \brief Vider la table de dispersion -  M�thode fournie
	 *
	 * \post  la table est vide
	 */
		void makeEmpty( );

	/**
	 *  \brief Recherche d'un �l�ment � partir d'une cl�
	 *
	 *  Recherche dans la table de dipsersion
	 *
	 * \post VRAI est retourn� si l'�l�ment est pr�sent, FAUX sinon
	 */
		bool contains( const TypeClef & x ) const;



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
		void insert( const TypeClef & x, const T& val );

	/**
	 *  \brief Supprimer un �l�ment de la table
	 *
	 * \pre la cl� � supprimer doit �tre pr�sente dans la table
	 * \post La table comprend un �l�ment de moins
	 * \exception logic_error si la cl� n'est pas dans la table
	 */
		void remove( const TypeClef & x );

	private:

	/**
	 * \enum EntryType
	 * \brief Les tags pour d�finir l'�tat d'une entr�e dans la table
	 */
		enum EntryType {
			ACTIVE, /*!< l'entr�e est occup�e*/
			EMPTY,	/*!< l'entr�e est vide*/
			DELETED /*!< l'entr�e a �t� supprim�e*/
		};

		/**
		* \class HashEntry
		*
		* \brief Classe interne pour d�finir une entr�e dans la table
		*/
		class HashEntry
		{
		public:
			TypeClef key;	/*!< la cl� de hachage*/
			T element;		/*!< la valeur associ�e � la cl�*/
			EntryType info; /*!< tag pour pr�ciser l'�tat de l'enr�e (vide, active ou supprim�e) */

			/**
			 *  \brief Constructeur par d�faut qui ne fait rien
			 */
			HashEntry(){}; //

			/**
			 *  \brief Constructeur avec argument pour initialiser les membres de la classe
			 */
			 HashEntry(const TypeClef& k, const T & e,  EntryType i = EMPTY )
			   : key(k), element( e ),info( i ) { }
		};

		std::vector<HashEntry> tab; /*!<  la table de hachage*/
		unsigned int currentSize;	/*!< le nombre d'�l�ments courant dans la table*/
		static const int TAUX_MAX = 50;	/*!< 50%:taux de remplissage maximum dans la table,
		sinon, on double sa taille. L'attribut static est pour fixer le m�me taux
		pour n'importe quelle instance de la classe en cas de modification*/

		/**
		 *  \brief Redimensionner la capacit� de la table de dispersion - M�thode fournie
		 *
		 * Cette m�thode peut �tre appel�e par insert(). Si, apr�s une insertion,
		 * le taux de remplissage atteint le maximum, cette m�thode la taille
		 * de la table de dispersion.
		*/
		void rehash( );

		FoncHachage myhash; /*!<fonction de hachage, voir les param�tres "template" de la classe
							  ainsi que comment le main() pr�pare la classe FoncHachage*/
	};
}//Fin du namespace

#include "HashTable.hpp"

#endif

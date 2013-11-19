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
	HashTable<TypeClef, T, FoncHachage>:: HashTable( int size) 
		: tab( nextPrime( size ) )
	{ 
		makeEmpty( ); 
	}
	    
	/**
	 * \fn void HashTable<TypeClef, T, FoncHachage>::makeEmpty( )
	 */
	template<typename TypeClef, typename T, class FoncHachage>
	void HashTable<TypeClef, T, FoncHachage>::makeEmpty( )
	{
			currentSize = 0;
			for( unsigned int i = 0; i < tab.size( ); i++ )
				tab[ i ].info = EMPTY;
	}

	/**
	 * \fn void HashTable<TypeClef, T, FoncHachage>::  rehash( )
	 */
	template<typename TypeClef, typename T, class FoncHachage>
	void HashTable<TypeClef, T, FoncHachage>::  rehash( )
	{
		std::vector<HashEntry> oldArray = tab;

		// Cr�ation d'une nouvelle table 2 fois plus grande
		tab.resize( nextPrime( 2 * oldArray.size( ) ) );
		for( unsigned int j = 0; j < tab.size( ); j++ )
			tab[ j ].info = EMPTY;

		// Copie de la table
		currentSize = 0;
		for(unsigned int i = 0; i < oldArray.size( ); i++ )
			if( oldArray[ i ].info == ACTIVE )
				insert( oldArray[ i ].key, oldArray[ i ].element);
	}



	//Compl�ter le fichier par les autres m�thodes demand�es


}//Fin du namespace
  

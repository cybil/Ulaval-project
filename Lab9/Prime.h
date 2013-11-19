/**
 * \file Prime.h
 * \brief Définitions de 2 fonction sur les nombres premiers
 * \author Abder
 * \version 0.1
 * \date mai 2011
 */

#ifndef PRIME_H
#define PRIME_H

	/**
	 *  \brief Cherche le prochain nombre premier après n 
	 *
	 * On assume que n est > 0
	 */
	int nextPrime (int n);

	//
	/**
	 *  \brief Vérifie si n est premier  
	 *
	 * On assume que n est > 0
	 */
	bool isPrime (int n);

#endif //PRIME_H

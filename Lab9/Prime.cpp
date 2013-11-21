/**
 * \file Prime.cpp
 * \brief Implémentation de fonction sur les nombres premiers
 * \author Abder
 * \version 0.1
 * \date mai 2011
 */

#include "Prime.h"
#include <cmath>

/**
 * \fn int nextPrime (int n)
 *
 * \param[in] n Un nombre entier > 0
 */
int		nextPrime(int n)
{
  if((n % 2) == 0) 
    n++;
  while(!isPrime(n))
    n += 2;
  return n;
}

/**
 * \fn bool isPrime (int n)
 *
 * \param[in] n Un nombre entier > 0
 * \return true ou false suivant que n est premier ou non
 */
bool		isPrime(int n)
{
  if (n <= 1)
    return false;
  if (n == 2)              // le seul nombre premier pair
    return true;
  else if (n % 2 == 0)     // sinon, ce n'est pas un nombre premier
    return false;
  else
    {
      int	divisor = 3;
      int	upperLimit = static_cast<int>(sqrt((float)n) + 1);

      while (divisor <= upperLimit)
	{
	  if (n % divisor == 0)
	    return false;
	  divisor += 2;
	}
      return true;
    }
}

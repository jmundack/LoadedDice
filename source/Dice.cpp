/**
 * \file Dice.cpp
 * \author Joseph Mundackal
 * \date 08-25-2013
 *
 * \brief This file contains the implementation of the Dice class
 */

#include "Dice.h"
#include <cstdlib>

size_t Dice::Roll() const
{
   // NOTE : seed the random number generator (eg: with time) to get different results on each run
   const int val((std::rand() % (_LoadedSideWeight+5)) +1);
   return (val > 6 ? _LoadedSide : val);
}

#include "Dice.h"
#include <cstdlib>
#include <iostream>

using namespace std;

size_t Dice::Roll() const
{
   const int val((std::rand() % (_LoadedSideWeight+5)) +1);
   return (val > 6 ? _LoadedSide : val);
}

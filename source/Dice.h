/**
 * \file Dice.h
 * \author Joseph Mundackal
 * \date 08-25-2013
 *
 * \brief This file conttains the class that 
 *        represents a LoadedDice and simulates it.
 */

#pragma once

#include <boost/noncopyable.hpp>
#include <vector>
#include <string>

class Dice : private boost::noncopyable
{
public:
   /**
    * \brief Constructs the dice with a name and information about 
    *        the loaed side.
    *
    * \param[in] name       Name of the dice
    * \param[in] loadedSide Which side of the dice is loaded
    * \param[in] weight     How is the laoded sided loaded.
    */
   Dice(const std::string &name, 
        const size_t loadedSide, 
        const size_t weight)
      :_Name(name),_LoadedSide(loadedSide),_LoadedSideWeight(weight)
   {}

   /**
    * \brief Returns the name of the dice
    */
   const std::string &GetName() const { return _Name; }

   /**
    * \brief Simulated a dice roll and return the number rolled
    */
   size_t Roll() const;
private:
   const std::string _Name;
   const size_t _LoadedSide;
   const size_t _LoadedSideWeight;
};

/**
 * \file ReadDiceConfiguration.h
 * \author Joseph Mundackal
 * \date 08-25-2013
 *
 * \brief This file contains classes used to  load dice configurations from a given file.
 *        it will throw exceptions if its a bad configuration file
 */

#pragma once

#include <boost/noncopyable.hpp>
#include <string>
#include <vector>

/**
 * \brief Class represents raw dice data
 */
class DiceData
{
public:
   /**
    * \brief default constructor - Initiaize an invalid dice
    */
   DiceData():_Name("Invalid"),_LoadedSide(0),_LoadAmount(0)
   {}

   /**
    * \brief Constructs dice data from given data
    *
    * \param[in] name       Name of the dice
    * \param[in] loadedSide Which side of the dice is loaded
    * \param[in] loadAmount How is the laoded sided loaded.
    */
   DiceData(const std::string name, 
            const size_t loadedSide,
            const size_t loadAmount):
      _Name(name),_LoadedSide(loadedSide), _LoadAmount(loadAmount)
   {}
          
   /**
    * \brief Returns the name of the dice
    */
   const std::string &GetName() const { return _Name; }

   /**
    * \brief Returns the loaded side
    */
   size_t GetLoadedSide() const { return _LoadedSide; }

   /**
    * \brief Returns the loaded side's load amount
    */
   size_t GetLoadAmount() const { return _LoadAmount; }
private:
   std::string _Name;
   size_t _LoadedSide;
   size_t _LoadAmount;
};

/**
 * \brief This class reads dice configuraitons from a given file
 */
class ReadDiceConfiguration : private boost::noncopyable
{
public:
   /**
    * \brief Loads the dice configuraitons from the given file
    *
    * \param[in] filename Dice configuration file name
    */
   ReadDiceConfiguration(const std::string &filename);

   /**
    * \brief Returns the number of rolls to simulate
    */
   size_t GetNumRolls() const { return _NumRolls; }

   /**
    * \brief Returns the raw dice data read in from the configuration file
    */
   const std::vector<DiceData> &GetDiceData() const { return _DiceData; }
private:
   size_t _NumRolls;
   std::vector<DiceData> _DiceData;
};

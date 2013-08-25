#include "ReadDiceConfiguration.h"
#include <boost/lexical_cast.hpp>

#include <iostream>
#include <fstream>

using namespace boost;
using namespace std;
#ifdef DEBUG
#define DEBUG_LOG cout
#else 
#define DEBUG_LOG if(false) cout
#endif

namespace 
{
   pair<string,string> _ParseLine(const string &line)
   {
      DEBUG_LOG << "Parsing Line : " << line << endl;
      const size_t equalPos(line.find("="));
      const string key(line.substr(0,equalPos));
      const string value(line.substr(equalPos+1));
      if (key.empty() || value.empty() || equalPos == string::npos)
      {
         cerr << "Invalid Line : " << line << endl;
         throw "Invalid Line in configuration file";
      }
      return make_pair(key,value);
   }
};

ReadDiceConfiguration::ReadDiceConfiguration(const string &filename):_NumRolls(0)
{
   ifstream inFile(filename.c_str());
   vector<pair<string,string> > keyValuePairs;
   if (inFile.good())
   {
      while(!inFile.eof() && inFile.good())
      {
         string line;
         inFile >> line;
         if (!line.empty())
            keyValuePairs.push_back(_ParseLine(line));
      }
   }
   else
   {
      cerr << "Unable to open file : " << filename << endl;
   }
   DEBUG_LOG << "Key value pairs from configuration file" << endl;
   for(vector<pair<string, string> >::const_iterator itr = keyValuePairs.begin(); itr != keyValuePairs.end(); ++itr)
   {
      DEBUG_LOG << "Key : " << itr->first << " value : " << itr->second << endl;
   }
   string diceName;
   size_t loadedSide(0);
   size_t loadAmount(0);
   for(vector<pair<string, string> >::const_iterator itr = keyValuePairs.begin(); itr != keyValuePairs.end(); ++itr)
   {
      if (itr->first == "NumRolls")
      {
         _NumRolls = lexical_cast<size_t>(itr->second);
      }
      else if (itr->first == "Dice")
      {
         if (!diceName.empty())
         {
            DiceData data(diceName,loadedSide,loadAmount);
            _DiceData.push_back(data);
            diceName = itr->second;
         }
         diceName = itr->second;
      }
      else if (itr->first == "LoadedSide")
         loadedSide = lexical_cast<size_t>(itr->second);
      else if (itr->first == "LoadAmount")
         loadAmount = lexical_cast<size_t>(itr->second);
      else
      {
         cerr << "Ignoring invlaid key valud pair : Key - " << itr->first << " value - " << itr->second << endl;
      }
   }
   if (!diceName.empty())
   {
      DiceData data(diceName,loadedSide,loadAmount);
      _DiceData.push_back(data);
   }
}

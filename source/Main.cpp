#include <iostream>
#include <boost/ptr_container/ptr_vector.hpp>
#include <map>
#include <algorithm>
#include <ctime>
#include "Dice.h"
#include "ReadDiceConfiguration.h"

using namespace boost;
using namespace std;

int main ( int argc, char *argv[] )
{
   if (argc != 2)
   {
      cerr << "Usage : " << argv[0] << " <dice configuration file>" << endl;
      return 1;
   }
   const string configurationFilename(argv[1]);
   ReadDiceConfiguration configurations(configurationFilename);
   const vector<DiceData> &diceData(configurations.GetDiceData());
   cout << "Dice Configurations --> " << endl;
   cout << "Num rolls : " << configurations.GetNumRolls() << endl;
   for(size_t i = 0; i < diceData.size(); i++)
   {
      cout << "Dice " << i << endl;
      cout << "\t Name : " << diceData.at(i).GetName() << endl;
      cout << "\t Loaded Side : " << diceData.at(i).GetLoadedSide() << endl;
      cout << "\t Load Amount : " << diceData.at(i).GetLoadAmount() << endl;
   }

   map<string, vector<size_t> > results;
   ptr_vector<Dice> dices;
   for(size_t i = 0; i < diceData.size(); i++)
   {
      const DiceData &data(diceData.at(i));
      dices.push_back(new Dice(data.GetName(), data.GetLoadedSide(), data.GetLoadAmount()));
   }
   for (size_t i = 0; i < configurations.GetNumRolls(); i++)
   {
      for(size_t j = 0; j < dices.size(); j++)
      {
         results[dices.at(j).GetName()].push_back(dices.at(j).Roll());
      }
   }

   cout << "\n\n********** Output **********\n";

   for (size_t i = 0; i < configurations.GetNumRolls(); i++)
   {
      cout << "Throw " << i << " : ";
      for(map<string, vector<size_t> >::const_iterator itr = results.begin(); itr != results.end(); ++itr)
      {
         if (itr != results.begin())
            cout << ", ";
         cout << itr->first << " rolled a " << itr->second.at(i);
      }
      cout << endl;
   }

   for(map<string, vector<size_t> >::const_iterator itr = results.begin(); itr != results.end(); ++itr)
   {
      cout << itr->first << " Statistics for " << configurations.GetNumRolls() << " rolls : " << endl;
      for (size_t i= 1; i < 7; i++)
      {
         const float numOccurances(count(itr->second.begin(), itr->second.end(), i));
         cout << "Side : " << i << " : " << (numOccurances*100/itr->second.size()) << endl;
      }
   }
   return 0;
}

#include <boost/noncopyable.hpp>
#include <string>
#include <vector>

class DiceData
{
public:
   DiceData():_Name("Invalid"),_LoadedSide(0),_LoadAmount(0)
   {}

   DiceData(const std::string name, 
            const size_t loadedSide,
            const size_t loadAmount):
      _Name(name),_LoadedSide(loadedSide), _LoadAmount(loadAmount)
   {}
          
   const std::string &GetName() const { return _Name; }
   size_t GetLoadedSide() const { return _LoadedSide; }
   size_t GetLoadAmount() const { return _LoadAmount; }
private:
   std::string _Name;
   size_t _LoadedSide;
   size_t _LoadAmount;
};

class ReadDiceConfiguration : private boost::noncopyable
{
public:
   ReadDiceConfiguration(const std::string &filename);
   size_t GetNumRolls() const { return _NumRolls; }
   const std::vector<DiceData> &GetDiceData() const { return _DiceData; }
private:
   size_t _NumRolls;
   std::vector<DiceData> _DiceData;

};

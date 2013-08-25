#include <vector>
#include <string>
#include <boost/noncopyable.hpp>

class Dice : private boost::noncopyable
{
public:
   Dice(const std::string &name, 
        const size_t loadedSide, 
        const size_t weight)
      :_Name(name),_LoadedSide(loadedSide),_LoadedSideWeight(weight)
   {}

   const std::string &GetName() const { return _Name; }
   size_t Roll() const;
private:
   const std::string _Name;
   const size_t _LoadedSide;
   const size_t _LoadedSideWeight;
};

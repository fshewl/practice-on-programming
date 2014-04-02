#include "CWarrior.hpp"
#include "Type.hpp"

class CLion: public CWarrior {

private:
  int loyalty;

public:
  CLion(int id, const CHeadquarter *pHQ, WarriorType type, int strength);
  
  int getLoyalty() const { return loyalty; }
  void setLoyalty(int &l) { loyalty = l; }

  void print() const;
};

CLion::CLion(int id, const CHeadquarter *pHQ, WarriorType type, int life)
  :CWarrior(id, pHQ, type, life)
{
  loyalty = pHQ -> getLifePool();
}

void CLion::print() const {
  std::cout  << "It's loyalty is " << loyalty << std::endl;
}


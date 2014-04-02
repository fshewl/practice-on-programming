#include "CWarrior.hpp"
#include "Type.hpp"

class CWolf: public CWarrior {

private:

public:
  CWolf(int id, const CHeadquarter *pHQ, WarriorType type, int strength);

  void print() const;
};

CWolf::CWolf(int id, const CHeadquarter *pHQ, WarriorType type, int life)
  :CWarrior(id, pHQ, type, life)
{

}

void CWolf::print() const {

}


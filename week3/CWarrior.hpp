#ifndef CWARRIOR_H__
#define CWARRIOR_H__

#include "CHeadquarter.hpp"
#include "Type.hpp"

class CHeadquarter;

class CWarrior {
  
private:
  static const char * pWarriorTypeString[];
  
  const int id;
  const int strength;
  const WarriorType type;
  const CHeadquarter *pHQ;

public:

  CWarrior(int id, const CHeadquarter *pHQ, WarriorType type, int strength):
    id(id), pHQ(pHQ), type(type), strength(strength) {}

  int getID();
  int getStrength();
  int getType();
  const char * getTypeString() const;
  const CHeadquarter * getHQ() const;

};

#endif

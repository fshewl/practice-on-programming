#ifndef CWARRIOR_HPP__
#define CWARRIOR_HPP__

#include <iostream>
#include "Type.hpp"

using namespace std;

class CWarrior {

private:
  const int id;
  const int strength;
  const WarriorType type;
  const HeadquarterType hq;

public:

  CWarrior(int id, HeadquarterType hq, WarriorType type, int strength):
    id(id), hq(hq), type(type), strength(strength) {}

  int getID();
  int getStrength();
  int getType();
  int getHQ();

};


#endif

#include "CWarrior.hpp"

using namespace std;

const char * CWarrior::pWarriorTypeString[5] =
    { "dragon", "ninja", "iceman", "lion", "wolf" };

int CWarrior::getID() {
  return id;
}

int CWarrior::getStrength() {
  return strength;
}

int CWarrior::getType() {
  return type;
}

const char *  CWarrior::getTypeString() const
{
  return pWarriorTypeString[type];
}

const CHeadquarter * CWarrior::getHQ() const
{
  return pHQ;
}


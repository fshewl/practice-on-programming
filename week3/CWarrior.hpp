#ifndef CWARRIOR_H__
#define CWARRIOR_H__

#include "CHeadquarter.hpp"
#include "Type.hpp"


class CHeadquarter;

class CWarrior {
  
private:
  static const char * pWarriorTypeString[];
  
  const int id;
  int life;
  const WarriorType type;
  const CHeadquarter *pHQ;

public:

  CWarrior(int id, const CHeadquarter *pHQ, WarriorType type, int life):
    id(id), pHQ(pHQ), type(type), life(life) {}

  int getID();
  int getLife();
  void setLife(int life);
  int getType();
  const char * getTypeString() const;
  const CHeadquarter * getHQ() const;

};

#endif

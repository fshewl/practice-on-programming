#ifndef CHEARQUARTER_H__
#define CHEARQUARTER_H__

#include "CWarrior.hpp"
#include "Type.hpp"
#include <iostream>
#include <iomanip>

#define MAX_WARRIORS 1000

class CWarrior;

class CHeadquarter {

private:
  static const char * pColor[];
  static const WarriorType Warrior_RED[];
  static const WarriorType Warrior_BLUE[];
  CWarrior * warriors[MAX_WARRIORS];

  
  const HeadquarterType HQType;
  int life_pool;
  int number_of_warriors[5];
  int warriors_strength[5];
  
  int id;
  int last_create;

  int total_warriors;

  bool stop;

public:
  CHeadquarter(HeadquarterType type, int life, int *warrior_str);
  void create_warrior(int clock);
  bool stop_create();
  const char * getColor() const;
  int getWarriorNum() const;
  int getLifePool() const { return life_pool; }
  
};


#endif

#ifndef CHEADQUARTER_HPP_INCLUDED__
#define CHEADQUARTER_HPP_INCLUDED__

#include <iostream>
#include <iomanip>
#include "CWarrior.hpp"
#include "Type.hpp"

using namespace std;

class CHeadquarter {

private:

  static const WarriorType Warrior_RED[];
  static const WarriorType Warrior_BLUE[];
  bool stop;
  
  const HeadquarterType HQType;
  int life_pool;
  int number_of_warriors[5];
  int warriors_strength[5];
  
  int id;

public:
  CHeadquarter(HeadquarterType type, int life, int *warrior_str);
  void create_warrior(int clock);
  bool stop_create();
  
};


int main() {

  int case_num;
  int life_pool;
  int warrior_str[5];
  int clock = 0;

  cin >> case_num;
  cin >> life_pool;
  cin >> warrior_str[0] >> warrior_str[1] >> warrior_str[2] >> warrior_str[3] >> warrior_str[4];

  HeadquarterType type1 = RED;
  HeadquarterType type2 = BLUE;
  CHeadquarter red_quarter(type1, life_pool, warrior_str);
  CHeadquarter blue_quarter(type2, life_pool, warrior_str);


  while(!red_quarter.stop_create() && !blue_quarter.stop_create()) {
    red_quarter.create_warrior(clock);
    blue_quarter.create_warrior(clock);
    clock++;
  }
    

  return 0;
}



#endif

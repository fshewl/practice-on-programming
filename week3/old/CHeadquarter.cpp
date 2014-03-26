#include "CHeadquarter.hpp"

const WarriorType CHeadquarter::
Warrior_RED[] = { ICEMAN, LION, WOLF, NINJA, DRAGON };

const WarriorType CHeadquarter::
Warrior_BLUE[]  = { LION, DRAGON, NINJA, ICEMAN, WOLF };

CHeadquarter::
CHeadquarter(HeadquarterType type, int life, int *warrior_str)
  :HQType(type), life_pool(life)
{
    
    for (int i = 0; i < 5; i++) 
      number_of_warriors[i] = 0;

    for (int i = 0; i < 5; i++) 
      warriors_strength[i] = warrior_str[i];

    id = 0;
    stop = false;

}


void CHeadquarter::create_warrior(int clock) {

  WarriorType WType;

  if (HQType == RED)
    WType = Warrior_RED[(clock%5)];
  else
    WType = Warrior_BLUE[(clock%5)];

  int strength_to_create = warriors_strength[WType];
  
  if (life_pool < strength_to_create)
    cout << HQType << "headquater stops making warriors" << endl;

  else {
    life_pool -= strength_to_create;
    
    CWarrior warrior(++id, HQType, WType, strength_to_create);
    number_of_warriors[warrior.getType()]++;
    
    
    string hq, w;
    if (HQType == RED)
      hq = "red";
    else
      hq = "blue";

    switch(warrior.getType()) {
    case 0:
      w = "lion";
      break;
    case 1:
      w = "dragon";
      break;
    case 2:
      w = "ninja";
      break;
    case 3:
      w = "iceman";
      break;
    case 4:
      w = "wolf";
      break;
    }

    cout << setfill('0') << setw(3) << clock << ' ';
    cout << w << ' ';
    cout << warrior.getID() << ' ';
    cout << "born with strength " << warrior.getStrength() << ",";
    cout << number_of_warriors[warrior.getType()] << ' ';
    cout << w << "in " << hq << "headquater" << endl;

  }
    

}


bool CHeadquarter::stop_create() {
  return stop;
}

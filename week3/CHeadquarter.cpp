#include "CHeadquarter.hpp"

using namespace std;

const char * CHeadquarter::
pColor[] = { "red", "blue" };

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

    total_warriors = 0;
    
    id = 0;
    stop = false;
    last_create = 0;

}


void CHeadquarter::create_warrior(int clock) {

  if (!stop) {

    WarriorType WType;

    int i = 0;
      
    for (; i < 5; i++) {
      
      if (HQType == RED)
	WType = Warrior_RED[((last_create + i)%5)];
      else
	WType = Warrior_BLUE[((last_create + i)%5)];

      // cout << "Try to create: " << warriors_strength[WType] << endl;
      if (life_pool >= warriors_strength[WType])
	break;
    }
	
      
    if (i == 5) {
      cout << setfill('0') << setw(3) << clock << ' ';
      cout << getColor() << " headquarter stops making warriors" << endl;
      stop = true;
      return;
    }
	
    else {
     	
      last_create = (last_create + i + 1)%5;
      int strength_to_create = warriors_strength[WType];
      life_pool -= strength_to_create;

      //cout << " Life left: " << life_pool << endl;
      
      warriors[total_warriors] = new CWarrior(++id, this, WType, strength_to_create);
      CWarrior & warrior = *warriors[total_warriors];
      total_warriors++;
      
      number_of_warriors[warrior.getType()]++;
      
      cout << setfill('0') << setw(3) << clock << ' ';
      cout << getColor() << ' ';
      cout << warrior.getTypeString() << ' ';
      cout << warrior.getID() << ' ';
      cout << "born with strength " << warrior.getStrength() << ",";
      cout << number_of_warriors[warrior.getType()] << ' ';
      cout << warrior.getTypeString() << " in " << getColor() << " headquarter" << endl;
      //cout << endl;
    }
  }
  

}
  

bool CHeadquarter::stop_create() {
  return stop;
}

const char * CHeadquarter::getColor() const {
  return pColor[HQType];
}

int CHeadquarter::getWarriorNum() const {
  return total_warriors;
}

#include <iostream>
#include <iomanip>

using namespace std;

enum HeadquarterType { RED = 0, BLUE };
enum WarriorType { DRAGON = 0, NINJIA, ICEMAN, LION, WOLF };
enum Weapon { SWORD = 0, BOMB, ARROW };
static const char * weaponString[] = { "sword", "bomb", "arrow" };


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
  int getOneWarriorNum(int i) const;
  int getLifePool() const { return life_pool; }

  
};


class CWarrior {
  
private:
  static const char * pWarriorTypeString[];
  
  const int id;
  int life;
  const WarriorType type;
  const CHeadquarter *pHQ;

public:

  CWarrior(int id, const CHeadquarter *pHQ, WarriorType type, int life);


  int getID();
  int getLife();
  void setLife(int life);
  int getType();
  const char * getTypeString() const;
  const CHeadquarter * getHQ() const;
  void printBase();
};


const char * CWarrior::pWarriorTypeString[5] =
    { "dragon", "ninja", "iceman", "lion", "wolf" };

CWarrior::CWarrior(int id, const CHeadquarter *pHQ, WarriorType type, int life):
  id(id), pHQ(pHQ), type(type), life(life)
{ printBase(); }

int CWarrior::getID() {
  return id;
}

int CWarrior::getLife() {
  return life;
}

void CWarrior::setLife(int l) {
  life = l;
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

void CWarrior::printBase() {
  cout << pHQ -> getColor() << ' ';
  cout << getTypeString() << ' ';
  cout << getID() << ' ';
  cout << "born with strength " << getLife() << ",";
  cout << pHQ -> getOneWarriorNum(getType()) << ' ';
  cout << getTypeString() << " in " << pHQ -> getColor() << " headquarter" << endl;


}

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
  print();
}

void CLion::print() const {
  cout  << "It's loyalty is " << loyalty << endl;
}


class CWolf: public CWarrior {

private:

public:
  CWolf(int id, const CHeadquarter *pHQ, WarriorType type, int strength);

  void print() const;
};

CWolf::CWolf(int id, const CHeadquarter *pHQ, WarriorType type, int life)
  :CWarrior(id, pHQ, type, life)
{
  print();
}

void CWolf::print() const {

}


class CDragon: public CWarrior {

private:
  Weapon weapon;
  int damage;
  float morale;

public:
  CDragon(int id, const CHeadquarter *pHQ, WarriorType type, int strength);
  
  Weapon getWeapon() const { return weapon; }
  void setWeapon(Weapon &w) { weapon = w; }
  
  int getDamage() const { return damage; }
  void setDamage(int d) { damage = d; }
  
  float getMorale() const { return morale; }
  void setMorale(double &m) { morale = m; }

  void print() const;
};

CDragon::CDragon(int id, const CHeadquarter *pHQ, WarriorType type, int life)
  :CWarrior(id, pHQ, type, life)
{
  weapon = (Weapon)(id%3);
  morale = (double)(pHQ -> getLifePool()) / life;
  print();
}

void CDragon::print() const {
  cout << setprecision(2) << fixed;
  cout  << "It has a " << weaponString[weapon]
	     << ",and it's morale is ";
  cout << morale << endl;

}


class CIceman: public CWarrior {

private:
  Weapon weapon;
  int damage;

public:
  CIceman(int id, const CHeadquarter *pHQ, WarriorType type, int strength);
  
  Weapon getWeapon() const { return weapon; }
  void setWeapon(Weapon &w) { weapon = w; }
  
  int getDamage() const { return damage; }
  void setDamage(int d) { damage = d; }

  void print() const;
};

CIceman::CIceman(int id, const CHeadquarter *pHQ, WarriorType type, int life)
  :CWarrior(id, pHQ, type, life)
{
  weapon = (Weapon)(id%3);
  print();
}

void CIceman::print() const {
  cout  << "It has a " << weaponString[weapon] << endl;
}


class CNinjia: public CWarrior {

private:
  Weapon weapon[2];
  int damage[2];

public:
  CNinjia(int id, const CHeadquarter *pHQ, WarriorType type, int strength);
  
  Weapon getWeapon(int i) const { return weapon[i]; }
  void setWeapon(int i, Weapon &w) { weapon[i] = w; }
  
  int getDamage(int i) const { return damage[i]; }
  void setDamage(int i, int d) { damage[i] = d; }

  void print() const;
  
};

CNinjia::CNinjia(int id, const CHeadquarter *pHQ, WarriorType type, int life)
  :CWarrior(id, pHQ, type, life)
{
  weapon[0] = (Weapon)(id%3);
  weapon[1] = (Weapon)((id+1)%3);
  print();
}

void CNinjia::print() const
{
  cout << "It has a " << weaponString[weapon[0]]
	    << " and a " << weaponString[weapon[1]] << endl;
}


const char * CHeadquarter::
pColor[] = { "red", "blue" };

const WarriorType CHeadquarter::
Warrior_RED[] = { ICEMAN, LION, WOLF, NINJIA, DRAGON };

const WarriorType CHeadquarter::
Warrior_BLUE[]  = { LION, DRAGON, NINJIA, ICEMAN, WOLF };

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
      
      total_warriors++;
      number_of_warriors[WType]++;

      cout << setfill('0') << setw(3) << clock << ' ';
      
      switch(WType) {
      case LION:
	warriors[total_warriors] =
	  new CLion(++id, this, WType, strength_to_create);
	break;

      case WOLF:
	warriors[total_warriors] =
	  new CWolf(++id, this, WType, strength_to_create);
	break;

      case DRAGON:
	warriors[total_warriors] =
	  new CDragon(++id, this, WType, strength_to_create);
	break;

      case ICEMAN:
	warriors[total_warriors] =
	  new CIceman(++id, this, WType, strength_to_create);
	break;

      case NINJIA:
	warriors[total_warriors] =
	  new CNinjia(++id, this, WType, strength_to_create);
	break;
	
      }


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

int CHeadquarter::getOneWarriorNum(int i) const {
  return number_of_warriors[i];
}


int main() {

  int case_num = 1;
  int life_pool;
  int warrior_str[5];
  int clock = 0;
  int t;
  cin >> t;
  while (t--) {
    
    cin >> life_pool;
    cin >> warrior_str[0] >> warrior_str[1] >> warrior_str[2] >> warrior_str[3] >> warrior_str[4];
    clock = 0;
    HeadquarterType type1 = RED;
    HeadquarterType type2 = BLUE;
    CHeadquarter red_quarter(type1, life_pool, warrior_str);
    CHeadquarter blue_quarter(type2, life_pool, warrior_str);

    cout << "Case:" << case_num << endl;
    while(!red_quarter.stop_create() || !blue_quarter.stop_create()) {
      red_quarter.create_warrior(clock);
      blue_quarter.create_warrior(clock);
      clock++;
    }

    case_num++;
  }
    

  return 0;
  
}


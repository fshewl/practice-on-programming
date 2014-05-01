#include <iostream>
#include <iomanip>

using namespace std;

enum CityFlag { RED = 0, BLUE, UNKNOWN };
enum WarriorType { DRAGON = 0, NINJIA, ICEMAN, LION, WOLF };
enum Weapon { SWORD = 0, BOMB, ARROW };
static const char * weaponString[] = { "sword", "bomb", "arrow" };
static const char * colorString[] = { "red", "blue", "unknown" };
static const WarriorType Warrior_RED[] = { ICEMAN, LION, WOLF, NINJIA, DRAGON };
static const WarriorType Warrior_BLUE[] = { LION, DRAGON, NINJIA, ICEMAN, WOLF };
static const char warriorTypeString[5] = { "dragon", "ninja", "iceman", "lion", "wolf" };
static int M, N, R, K, T;


#define MAX_WARRIORS 500
#define MAX_CITIES 100

class CWarrior;

class CCity {

private:
  
  CWarrior * redWarrior;
  CWarrior * blueWarrior;
  
  int cityID;
  CityFlag flag;
  int life_pool;



public:
  static CCity * map[MAX_CITIES]; // record the number of cities
  CCity(int cID, int lpool = 0) : cityID(cID), life_pool(lpool) {
    total_warriors = totalRedWarriors = totalBlueWarriors = 0;
    flag = UNKNOWN;
  }

  virtual ~CCity() {
  }

  void addLife(int i) { life_pool += i; }
  int donateLife() {
    int rt = life_pool;
    life_pool = 0;
    return rt;
  }

  const char * getFlag() const;
  
  int getID() { return cityID; }
  int getLifePool() const { return life_pool; }

  CWarrior * getRedWarrior() { return redWarrior; }
  void setRedWarrior(CWarrior * w) { redWarrior = w; } 

  CWarrior * getBlueWarrior() { return blueWarrior; }
  void setBlueWarrior(CWarrior * w) { blueWarriors = w; } 

  void startBattle();
  
};


class CHeadquarter : public CCity {

private:
  int number_of_warriors[5];
  int warriorInitLife[5];
  int warriorInitDamage[5];
  int total_warriors;
  int last_create;
  bool stop;

public:
  CHeadquarter(CityFlag f, int initLife, int * wInitLife, int * wInitDamage);
  void create_warrior(int clock);
  bool stop_create();
  int getOneWarriorNum(int i) const;
  int getWarriorNum() const { return total_warriors; }

};

class CWarrior {
  
private:
  
  const int id;
  int life;
  int damage;
  const WarriorType type;
  const CHeadquarter *pHQ;
  int cityID;
  bool dead;
  bool hasBomb;

public:

  CWarrior(int id, const CHeadquarter *pHQ, WarriorType type, int life);

  int getID();
  int getLife();
  void setLife(int life);
  int getType();
  int getCityID() { return cityID; }
  void setCityID(int i) { city ID = i; }
  
  const char * getTypeString() const;
  const CHeadquarter * getHQ() const;
  bool isDead() const { return dead; }
  bool hasBomb() const { return hasBomb; }

  void printBase();
  virutal void print();
  virtual void Attack(CWarrior * enemy);
  virtual void Hurted(int damage);
  virtual void FightBack(CWarrior * enemy);
  virtual void March();
  virtual int predictDamage();

  
};


class CWeapon {
private:
  Weapon weapon;
  int damage;

public:
  Weapon(int i, int d) : weapon(i), damage(d) {}
  Weapon getWeapon() { return weapon; }
  const char * getWeaponString { return weaponString[weapon]; }
  int getDamage() { return damage; }

  Virtual void attack(CWarrior * warrior);

};

class CSword : public CWeapon {
private:
  
  bool broken;

public:
  CSword(int initD) : Weapon(SWOR, initD), broken(false) {}
  bool isBroken() { return broken; }
  void attack(CWarrior * warrior);
};

void CSword::atack(CWarrior * warrior) {
  warrior -> Hurted(damage);
  damage = damage * 0.8;

  if (damage == 0)
    broken = true;
}


class CBomb : public CWeapon {
private:
  CWarrior * owner;
  

};

class CArrow : public CWeapon {

};


  
CWarrior::CWarrior(int id, CHeadquarter *pHQ, WarriorType type, int life):
  id(id), pHQ(pHQ), type(type), life(life), pCity(pHQ), dead(false)
{ 
  cityID = pHQ -> getID();
  printBase();
}

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
  return warriorTypeString[type];
}

const CHeadquarter * CWarrior::getHQ() const
{
  return pHQ;
}

void CWarrior::printBase() {
  cout << pHQ -> getFlag() << ' ';
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
  CLion(int id, const CHeadquarter *pHQ, WarriorType type, int initLife);
  
  int getLoyalty() const { return loyalty; }
  void setLoyalty(int &l) { loyalty = l; }
  void print() const;

  void Attack(CWarrior * enemy);
  void Hurted(int damage);
  void FightBack(CWarrior * enemy);
  void March();
  
  
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

void CLion::Attack(CWarrior * enemy) {
  emenmy -> Hurted(damage);
}

void CLion::Hurted(int damage) {
  life -= damage;

  if (life <= 0) {
    life = 0;
    dead = true;
  }
}

void CLion::FightBack(CWarrior * enemy) {
  enemy -> Hurted(damage);
}

void CLion::March() {
  if ((getHQ() -> getFlag) == "red") {
    if (cityID < N+1) {
      cityID++;
      map[cityID] -> setRedWarrior(this);
    }
  }

  else {
    if (cityID > 0) {
      cityID--;
      map[cityID] -> setBlueWarrior(this);
    }
  }
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

  void Attack(CWarrior * enemy);
  void Hurted(int damage);
  void FightBack(CWarrior * enemy);
  void March();

  
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




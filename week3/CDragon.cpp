#include "CWarrior.hpp"
#include "Type.hpp"

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
}

void CDragon::print() const {
  std::cout  << "It has a " << weaponString[weapon]
	     << ",and it's morale is ";
  std::cout.precision(2);
  std::cout << morale << std::endl;

}


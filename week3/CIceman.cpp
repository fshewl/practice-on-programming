#include "CWarrior.hpp"
#include "Type.hpp"

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
}

void CIceman::print() const {
  std::cout  << "It has a " << weaponString[weapon] << std::endl;
}


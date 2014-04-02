#include "CWarrior.hpp"
#include "Type.hpp"

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
}

void CNinjia::print() const
{
  std::cout << "It has a " << weaponString[weapon[0]]
	    << " and a " << weaponString[weapon[1]] << std::endl;
}




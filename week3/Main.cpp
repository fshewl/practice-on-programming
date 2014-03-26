/*
 *  Drafted on March 26th, 2014
 *  by  Wenlei He
 *  fshewl@gmail.com
 *
 *  Coursera - Practice on Programming
 */

#include "CHeadquarter.hpp"
#include "CWarrior.hpp"
#include <iostream>

using namespace std;

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


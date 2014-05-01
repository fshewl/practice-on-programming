#include <iostream>
#include <set>
#include <map>
#include <cmath>

using namespace std;

typedef int mid_t;
typedef int strength_t;

int findComponent(strength_t, map<strength_t, mid_t>&);

int main() {

  int totalRecords;
  set<strength_t> strengthSet;
  map<strength_t, mid_t> memberRecord;
  memberRecord.insert(pair<strength_t, mid_t>(1000000000, 1)); // facer's infor
  
  cin >> totalRecords;

  for (int i = 0; i < totalRecords; i++) {
    int id, strength;
    cin >> id >> strength;
  
    memberRecord.insert(pair<strength_t, mid_t>(strength, id));

    int component = findComponent(strength, memberRecord);

    cout << id << ' ' << component << endl;

  }

  return 0;

}

int findComponent(strength_t s, map<strength_t, mid_t> &memberRecord) {

  multimap<strength_t, mid_t>::iterator itLB;    // iterator to lower bound
  multimap<strength_t, mid_t>::iterator itUB;    // iterator to upper bound
  
  itLB = memberRecord.lower_bound(s);
  itUB = memberRecord.upper_bound(s);
  
  if (itUB == memberRecord.end())
    return ((--itLB)->second);

  if (itLB == memberRecord.begin())
    return (itUB->second);
  
  if (abs(((--itLB)->first)-s) <= abs(((itUB)->first)-s))
    return (itLB->second);
  else
    return (itUB->second);
}

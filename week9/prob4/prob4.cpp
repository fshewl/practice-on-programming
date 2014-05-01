#include <iostream>
#include <map>
#include <cmath>
#include <cstdio>

using namespace std;

typedef int mid_t;
typedef int strength_t;

int findComponent(strength_t, map<strength_t, mid_t>&);
int findComponent(strength_t, map<strength_t, mid_t>::iterator&, map<strength_t, mid_t>&);


// solution 2: add the following line
// cin and cout require more time than scanf & printf
//ios::sync_with_stdio(false);

int main() {

  int totalRecords;
  map<strength_t, mid_t> memberRecord;
  memberRecord.insert(pair<strength_t, mid_t>(1000000000, 1)); // facer's infor
  
  //cin >> totalRecords;
  scanf("%d", &totalRecords);

  for (int i = 0; i < totalRecords; i++) {
    int id, strength;
    //cin >> id >> strength;
    scanf("%d", &id);
    scanf("%d", &strength);
  
    map<strength_t, mid_t>::iterator it = (memberRecord.insert(pair<strength_t, mid_t>(strength, id))).first;

    int component = findComponent(strength, it, memberRecord);

    //cout << id << ' ' << component << endl;
    printf("%d %d\n", id, component);

  }

  return 0;

}

int findComponent(strength_t s, map<strength_t, mid_t> &memberRecord) {

  map<strength_t, mid_t>::iterator itLB;    // iterator to lower bound
  map<strength_t, mid_t>::iterator itUB;    // iterator to upper bound
  
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

int findComponent(strength_t s, map<strength_t, mid_t>::iterator& it, map<strength_t, mid_t>& memberRecord) {

  if (it == memberRecord.end())
    return ((--it)->second);

  if (it == memberRecord.begin())
    return ((++it)->second);

  map<strength_t, mid_t>::iterator previous = it;
  previous--;
  map<strength_t, mid_t>::iterator next = it;
  next++;
  
  if (abs((previous->first)-s) <= abs((next->first)-s))
    return (previous->second);
  else
    return (next->second);
  
}

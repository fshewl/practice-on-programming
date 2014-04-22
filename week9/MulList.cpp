#include <iostream>
#include <list>
#include <cstdlib>
#include <cstring>

using namespace std;

#define MAXID 10000
#define MAXCMD 200000

class MulList {

private:
  list<int> *mList[MAXID];
  int init[MAXID];

  void parseCmd(const char *command, int *num1, int *num2);
  
  int ifInit(int id) { return init[id]; }
  int newList(int id);
  void add(int id, int num);
  void merge(int id1, int id2);
  void output(int id);
  void unique(int id);
  
public:
  void runCmd(const char *command);

};

void MulList::parseCmd(const char *command, int *num1, int *num2) {

  const char *start = strchr(command, ' ');
  *num1 = atoi(start);

  if (command[0] == 'a' || command[0] == 'm') {
    start = strchr(start+1, ' ');
    *num2 = atoi(start);
  }
  
}

// return -1 if already created
int MulList::newList(int id) {

  if (ifInit(id))
    return -1;

  init[id] = 1;
  mList[id] = new list<int>();

  return 0;
}

void MulList::add(int id, int num) {
  mList[id]->push_back(num);
}

void MulList::output(int id) {
  mList[id]->sort();
  list<int>::iterator it = mList[id]->begin();
  for(; it != mList[id]->end(); it++)
    cout << *it << ' ';

  cout << endl;
}

void MulList::merge(int id1, int id2) {
  mList[id1]->sort();
  mList[id2]->sort();

  mList[id1]->merge(*mList[id2]);
}

void MulList::unique(int id) {
  mList[id]->unique();
}
 

void MulList::runCmd(const char *command) {
  int num1, num2;

  parseCmd(command, &num1, &num2);
  
  char c = command[0];
  switch(c) {
  case 'n':
    newList(num1);
    break;
  
  case 'a':
    add(num1, num2);
    break;
  
  case 'o':
    output(num1);
    break;

  case 'm':
    merge(num1, num2);
    break;

  case 'u':
    unique(num1);
    break;

  default:
    cout << "Invalid command!" << endl;
    break;
  }

}


int main() {

  int numCmd;
  char command[MAXCMD];

  MulList ml;
  
  cin >> numCmd;
  cin.ignore();

  for (int i = 0; i < numCmd; i++) {
    cin.getline(command, MAXCMD);
    ml.runCmd(command);
  }

}

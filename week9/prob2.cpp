#include <iostream>
#include <set>
#include <cstring>
#include <cstdlib>

using namespace std;

#define MAXCMD 100

int main() {

  multiset<int> ms;

  int numCmd;

  cin >> numCmd;
  cin.ignore();
  cin.ignore();

  char command[MAXCMD];
  int num;
  
  for (int i = 0; i < numCmd; i++) {
    cin.getline(command, MAXCMD);

    if (strlen(command) == 0)
      continue;

    num = atoi(strchr(command, ' ') + 1);

    switch(command[1]) {
    case 's':
      if (ms.find(num) == ms.end())
	cout << "0 0" << endl;
      else
	cout << "1 " << ms.count(num) - 1 << endl;
      break;

    case 'd':
      if (ms.count(num) == 0)
	ms.insert(num);
      ms.insert(num);
      cout << ms.count(num) - 1 << endl;
      break;

    case 'e':
      if (ms.count(num) == 0)
	cout << "0" << endl;
      else {
	cout << ms.count(num) - 1 << endl;
	ms.erase(num);
	ms.insert(num);
      }
      break;
    }
	
    
  }
  
  return 0;

}


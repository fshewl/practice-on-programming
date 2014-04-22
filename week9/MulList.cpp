#include <iosteam>
#include <List>

using namespace std;

#define MAXID 10000
#define MAXCMD 200000

class MulList {

private:
  List<int> *mList[MAXID];
  int init[MAXID];
  int ifInit(int id) { return init[id]; }
  void init(int id) { init[id] = 1; mList[id] = new List<int>(); }
  
public:
  void runCmd(char *command);

}


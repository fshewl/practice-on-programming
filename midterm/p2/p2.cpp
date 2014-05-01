#include <iostream>
#include <list>
using namespace std;

class MyLess {

public:
  bool operator()(int num1, int num2) {
    if ((num1 % 10) < (num2 % 10))
      return false;

    if ((num1 % 10) == (num2 % 10))
      if (num1 < num2)
	return false;

    return true;

  }

};


int main()
{
  int t;
  cin >> t;
  list<int> lst;
  while( t--) {
    int n;
    cin >> n;
    lst.clear();
    int m;
    for( int i = 0;i < n; ++i) {
      cin >> m;
      lst.push_back(m);
    }
    lst.sort(MyLess());
    list<int>::iterator it;
    for( it = lst.begin(); it != lst.end(); ++ it) {
      cout << * it  << " ";
    }
    cout << endl;
  }
  return 0;
}

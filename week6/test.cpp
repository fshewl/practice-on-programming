#include <iostream>
using namespace std;

class A {
  
private:
  int i;
  
public:
  A(int in) : i(in) {}
  ~A() { cout << "destructed!" << endl; }
  void print() { cout << i << endl; }

};

int main() {

  A * pA = new A(10);
  A a(10);
  //  delete pA;
  //  pA = NULL;
  if (pA == NULL) cout << "null" << endl;
  else
    cout << "not null" << endl;

  pA -> print();

  return 0;

}
  

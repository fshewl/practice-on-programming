#include <iostream>
using namespace std;

class A {


public:
    int i;
  A(int i) : i(i) { cout << "I'm " << i << " Con!" << endl; }
  
  A(const A & a) {
    i = a.i + 1;
    cout << "Copy!" << endl;
  }

  void print() { cout << "print! " << i << endl; }
  
};


A funccall( A  a)  {
  
  A b(4);

  return b;
  }


int main() {

  A a(1);
  
  A b(a);

  A c(funccall(b));

  c.i = 10;
  cout << c.i << endl;

  //  cout <<  funccall(a).i << endl;

  


}

  

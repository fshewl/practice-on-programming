#include <iostream>
#include <string>

using namespace std;

class A {
  int a;

public:
  A(int i): a(i) {}

};

int main() {

  A * pA;

  pA = new A(10);
  
  A a(10);
  
  pA = &a;

}
  

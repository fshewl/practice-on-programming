#include <iostream>
using namespace std;

class A {
private:
  int val;
public:
  A(int i): val(i) {}
  A(A & a) { cout << "I'm 2, copy!" << endl; }
  int getVal() { return val;}
};

A test(A b) {

  A a(2);
  return a;
}
int main() {

  A a(0);
  A b(1);
  a = b;
  cout << a.getVal() << endl;

  test(a);

  //cout << test(a).getVal() << endl;

  return 0;
}
  

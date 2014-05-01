#include <iostream>
#include <string>

using namespace std;

class A {
private:
  int val;

public:
  A():val(10)  { cout << "const" << endl; }
  A(const A &b) { 
    cout << "copy" << endl;
    val = b.val;
  }
  ~A() { cout << "destr" << endl; }

  int get() { return val; }

};

A& func(A& a) {
  
  cout << a.get() << endl;

  return a;

}
int main() {

  A a;

  func(a);

}

    

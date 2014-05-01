#include <iostream>
#include <vector>

using namespace std;

class A {

  int val;

public:
  A(int i) : val(i) {
    cout << "Con is called, val = " << val << endl;
  }

  A(const A & a) {
    cout << "CopyCon is called, val = " << a.get() << endl;
    val = a.get();

  }

 int get() const { return val; } 

};


int main() {

  vector<A> vA;

  A a(10);

  vA.push_back(&a);

  

}

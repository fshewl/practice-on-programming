#include <iostream>
using namespace std;

class Base {
private:
  int i;
public:
  Base(int val):i(val) {}
  int getVal() { return i; }
  virtual void print() = 0;
};


class A : public Base {
public:
  A(int val) : Base(val) {}
  void print() { cout << "A " << getVal() << endl; }
};

class B : public Base {
public:
  B(int val) : Base(val) {}
  void print() { cout << "B " << getVal() << endl; }
};

void PrintInfo(Base *ptr) {
  ptr->print();
}
  
Base* a[100];

int main()
{
  int t;
  cin >> t;
  while( t -- ) {
    int n;
    cin >> n;
    for( int i = 0;i < n; ++i){
      char c; int k;
      cin >> c >> k;
      if( c == 'A')
	a[i] = new A(k);
      else
	a[i] = new B(k);
    }
    cout << n << endl;
    for( int i = 0;i < n; ++i)
      PrintInfo(a[i]);
    cout << "****" << endl;
  }
}

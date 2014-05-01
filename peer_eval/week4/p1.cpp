#include <iostream>
#include <cstring>
using namespace std;
class Complex {
private:
  double r,i;
public:
  Complex() { r = 0; i = 0; }
  
  void Print() {
    cout << r << "+" << i << "i" << endl;
  }  
  
  Complex & operator= (const char * s);
};

Complex & Complex::operator= (const char * s) {
  
  if (s) {

    int len = strlen(s);
    char * tmp = new char[len+1];
    
    strcpy(tmp, s);
    
    char * p = strchr(tmp, '+');
    
    p[0] = '\0';
    tmp[len-1] = 0;

    r = atof(tmp);
    i = atof(p+1);
    delete []tmp;
  }

  else {
    r = 0;
    i = 0;
  }
  
  
  return *this;
}


int main() {
  Complex a;
  a = "3+4i"; a.Print();
  a = "5+6i"; a.Print();
  return 0;
}

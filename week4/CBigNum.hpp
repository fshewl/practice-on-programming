#ifndef CBIGNUM_HPP__
#define CBIGNUM_HPP__

#include <iostream>
#include <string>

#define MAX_LENGTH 100
#define TRUE 1
#define FALSE 0
#define POSITIVE 0
#define NEGATIVE 1

class CBigNum {

private:
  int length;
  int sign;
  int * p_num;


public:
  CBigNum(const std::string num_string);  // Constructor
  //CBigNum(const CBigNum &num);        // Copy Constructor
  ~CBigNum() {
    delete p_num;
  }

  int getLength() { return length; }
  int getSign() { return sign; }
  
  int operator<(CBigNum &num) const;
  CBigNum operator+(CBigNum &num) const;
  
  /*
  CBigNum operator-(CBigNum num);
  CBigNum operator*(CBigNum num);
  CBigNum operator/(CBigNum num);
  */

  friend std::ostream& operator<<(std::ostream &os, const CBigNum &num);
};

std::ostream& operator<<(std::ostream &os, const CBigNum &num);

#endif

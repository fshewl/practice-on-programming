#include "CBigNum.hpp"

using namespace std;


CBigNum::CBigNum(const string num_string) {

  char c_sign = num_string[0];
  int pos = 0;
  
  if (c_sign == '+') {
    length = num_string.length() - 1;
    pos = 1;
    sign = POSITIVE;
  }

  else if (c_sign == '-') {
    length = num_string.length() - 1;
    pos = 1;
    
    if (num_string[pos] == '0')
      sign = POSITIVE;
    else
      sign = NEGATIVE;
  }

  else {
    length = num_string.length();
    sign = POSITIVE;
  }

  p_num = new int[length];
  
  for(int i = 0; i < length; i++) {
    p_num[i] = num_string[pos++]-'0';
  }

}

ostream& operator<<(ostream &os, const CBigNum &num) {

  if(num.sign == NEGATIVE)
    os << '-';

  for (int i = 0; i < num.length; i++)
    os << num.p_num[i];

  return os;

}


int CBigNum::operator<(CBigNum &num) const {

  if (sign < num.sign)
    return TRUE;

  if (sign == POSITIVE) {

    if (length < num.length)
      return TRUE;
    
    else 
      for (int i = (length-1); i >= 0; i--) {
	if (p_num[i] < num.p_num[i])
	  return TRUE;
    }
    
  }

  if (sign == NEGATIVE) {

    if (length < num.length)
      return TRUE;
    
    else 
      for (int i = (length-1); i >= 0; i--) {
	if (p_num[i] > num.p_num[i])
	  return TRUE;
      }
    
  }

  return FALSE;

}

CBigNum CBigNum::operator+(CBigNum &num) const {

  
  
}

int main() {

  string num;

  cin >> num;
  
  CBigNum bignum1(num);

  cin >> num;
  CBigNum bignum2(num);
  
  cout << bignum1 << endl;
  cout << bignum2 << endl;
  
  return 0;

}

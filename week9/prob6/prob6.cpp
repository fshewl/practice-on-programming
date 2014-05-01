#include <iostream>
#include <string>
using namespace std;
template <class T>
class CMyistream_iterator
{

private:
  istream &input;
  T *ptr;
  bool next;

public:
  CMyistream_iterator(istream &is) : input(is) {
    ptr = NULL;
    next = true;
  }
  T operator*();
  void operator++(int) { next = true; }

};

template<class T>
T CMyistream_iterator<T>::operator*() {
  if (next) {
    ptr = new T;
    cin >> *ptr;
    next = false;
    return *ptr;
  }

  else
    return *ptr;
}





int main()  
{ 
  int t;
  cin >> t;
  while (t--) {
    CMyistream_iterator<int> inputInt(cin);
    int n1,n2,n3;
    n1 = * inputInt;
    int tmp = * inputInt; 
    cout << tmp << endl;
    inputInt ++;   
    n2 = * inputInt; 
    inputInt ++;   
    n3 = * inputInt; 
    cout << n1 << "," << n2<< "," << n3 << ",";
    CMyistream_iterator<string> inputStr(cin);
    string s1,s2;
    s1 = * inputStr; 
    inputStr ++;     
    s2 = * inputStr; 
    cout << s1 << "," << s2 << endl;
  }
  return 0;  
}

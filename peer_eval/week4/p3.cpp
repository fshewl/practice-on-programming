#include <iostream>
using namespace std;

class Array2 {
  
private:
  int * parray;
  int row, col;

public:
  Array2(int row = 0, int col = 0): row(row), col(col) {
    parray = new int[row*col];
  }
  ~Array2() { delete [] parray; }

  Array2 & operator= ( const Array2 & arr) {
    row = arr.row;
    col = arr.col;

    if (parray != NULL) delete [] parray;

    parray = new int[row*col];
    
    memcpy(parray, arr.parray, sizeof(int)*col*row);

    return *this;
  }

  int* operator[] (int i) {
    return parray + i*col;
  }

  int operator() (int i, int j) {
    return *(parray + i*col + j);
  }
  
};


int main() {
  
  Array2 a(3,4);
  int i,j;

  for(  i = 0;i < 3; ++i )
    for(  j = 0; j < 4; j ++ )
      a[i][j] = i * 4 + j;

  
  for(  i = 0;i < 3; ++i ) {
    for(  j = 0; j < 4; j ++ ) {
      cout << a(i,j) << ",";
    }
    cout << endl;
  }

  cout << "next" << endl;
  Array2 b; b = a;
  
  for(  i = 0;i < 3; ++i ) {
    for(  j = 0; j < 4; j ++ ) {
      cout << b[i][j] << ",";
    }
    cout << endl;
  }
  
  return 0;
}

#include <iostream>
using namespace std;

template <class T>
class CArray3D {

private: 
  // 构造一个私有的2D类模板 
  class CArray2D {
  private:
    T * p2D;

    int row, col;

  public:
    CArray2D() {
      p2D = new T[1*1];
    }
    
    CArray2D(int i, int j) {
      row = i;
      col = j;
      p2D = new T[i*j];
    }

    // 由于构造函数不适用于建立动态数组
    // 所以构造一个初始化函数
    void init(int i, int j) {
      if (p2D != NULL) delete [] p2D;
      row = i;
      col = j;
      p2D = new T[i*j];
    }
    T * operator[] (int i) {
      return (p2D + i*col);
    }
  };
  

  CArray2D *p3D;
  int size;

public:
  CArray3D(int z, int i, int j) : size(i*j) {
    p3D = new CArray2D[z];

    for (int k = 0; k < z; k++)
      p3D[k].init(i, j);
  }
  
  CArray2D & operator[] (int i) {
    return * (p3D + i);
  }
  
};


int main()

{

  CArray3D<int> a(3,4,5);

  int No = 0;

  for( int i = 0; i < 3; ++ i )

    for( int j = 0; j < 4; ++j )

      for( int k = 0; k < 5; ++k )

	a[i][j][k] = No ++;

  for( int i = 0; i < 3; ++ i )

    for( int j = 0; j < 4; ++j )

      for( int k = 0; k < 5; ++k )

	cout << a[i][j][k] << ",";

  return 0;

}

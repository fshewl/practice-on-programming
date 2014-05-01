#include <iostream>

using namespace std;

int main() {

  int line;
  int n, i, j;

  cin >> line;
  
  for (int t = 0; t < line; t++)  {

    cin >> n >> i >> j;
    int mask_i = 1 << i;
    int mask_j = 1 << j;

    int k = ((n & mask_i) | ((~n) & mask_j));
      
    cout << k << endl;
  }
  
  return 0;

}

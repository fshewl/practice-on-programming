#include <iostream>
#include <queue>
#include <cmath>
#include <set>
#include <vector>

using namespace std;

int numPrime(int num) {
  int count = 0;
  int temp = num;

  if (num == 2)
    return count;

  int flag = 0;
  while (num % 2 == 0) {
    
    if (flag == 0) {
      count++;
      flag = 1;
    }
    num /= 2;
    
  }
 
  
  for (int i = 3; i <= sqrt(num); i += 2) {
    flag = 0;
    
    while (num % i == 0) {
      if (flag == 0) {
	count++;
	flag = 1;
      }
      num /= i;
    }
    
  }

  if ((num > 2) && (num < temp))
    count++;

  return count;

 }


class MyComparator {
  
public:
  bool operator()(int num1, int num2);
};

bool MyComparator::operator()(int num1, int num2) {

  if (numPrime(num1) < numPrime(num2))
    return true;
  
  if ((numPrime(num1) == numPrime(num2)) && (num1 < num2))
    return true;
  
  return false;
  
}

class MyComparator2 {
  
public:
  bool operator()(int num1, int num2);
};

bool MyComparator2::operator()(int num1, int num2) {
  
  if (numPrime(num2) < numPrime(num1))
    return true;
  
  if ((numPrime(num2) == numPrime(num1)) && (num2 < num1))
    return true;
  
  return false;
  
}


int main() {
  
  
  int line;
  
  cin >> line;

  priority_queue<int, vector<int>, MyComparator> pq;
  priority_queue<int, vector<int>, MyComparator2> pq2;
  
  for (int i = 0; i < line; i++) {
      
    for (int j = 0; j < 10; j++) {
      int num;
      cin >> num;
      pq.push(num);
      pq2.push(num);
    }
    
    cout << pq.top() << ' ' << pq2.top() << endl;
    pq.pop();
    pq2.pop();
    
  }
  
}

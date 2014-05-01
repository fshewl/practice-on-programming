#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <queue>

using namespace std;
 
// A function to print all prime factors of a given number n
void primeFactors(int n)
{
  // Print the number of 2s that divide n
  while (n%2 == 0)
    {
      printf("%d ", 2);
      n = n/2;
    }
 
  // n must be odd at this point.  So we can skip one element (Note i = i +2)
  for (int i = 3; i <= sqrt(n); i = i+2)
    {
      // While i divides n, print i and divide n
      while (n%i == 0)
        {
	  printf("%d ", i);
	  n = n/i;
        }
    }
 
  // This condition is to handle the case whien n is a prime number
  // greater than 2
  if (n > 2)
    printf ("%d ", n);

  printf("\n");
}

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

  cout << "Comparing " <<  "num1: " << num1 << ", num2: " << num2 << endl;

  cout << "num1 anaylsis: ";
  primeFactors(num1);
  printf("%d\n", numPrime(num1));
  cout << "num2 anaylsis: ";
  primeFactors(num2);
  printf("%d\n", numPrime(num2));

  if (numPrime(num1) < numPrime(num2)) {
    cout << "num1 < num2 is TRUE!" << endl;
    return true;
  }
  
  if ((numPrime(num1) == numPrime(num2)) && (num1 < num2)) {
    cout << "num1 < num2 is TRUE!" << endl;
    return true;
  }

  cout << "num1 < num2 is FALSE!" << endl;
  return false;
  
}

/* Driver program to test above function */
int main()
{
    int line;
  
  cin >> line;
  
  for (int i = 0; i < line; i++) {
    
    priority_queue<int, vector<int>, MyComparator> pq;
    //priority_queue<int, vector<int>, MyComparator2> pq2;
    
    for (int j = 0; j < 10; j++) {
      int num;
      cin >> num;
      pq.push(num);
      //pq2.push(num);
      cout << pq.top() << endl;
    }

    cout << pq.top() << endl;
    //cout << pq.top() << ' ' << pq2.top() << endl;
    
  }

  
}




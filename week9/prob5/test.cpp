#include <iostream>
#include <cmath>

using namespace std;

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
  int flag = 0;
  if (num == 2)
    return count;

  flag = 0;
  while (num % 2 == 0) {
    num /= 2;
    if(flag == 0) {
      count++;
      flag = 1;
    }
  }

  for (int i = 3; i <= sqrt(num); i += 2) {
    flag = 0;
    while (num % i == 0) {
      num /= i;
      if (flag == 0) {
	count++;
	flag = 1;
      }
    }
  }

  if ((num > 2) && (num < temp))
    count++;

  return count;
}

int main() {

  int i;

  while (true) {

    cin >> i;

    cout << numPrime(i) << endl;
    primeFactors(i);

  }

}

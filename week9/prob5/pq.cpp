#include <iostream>
#include <queue>

using namespace std;


int main() {

  priority_queue<int, vector<int>, greater<int> > pq;

  pq.push(2);

  pq.push(20);

  cout << pq.top() << endl;
    

}

#include <iostream>
#include <queue>
#include <bitset>
#include <iomanip>
#include <cstring>

using namespace std;
bitset<65536> flags;

unsigned int reverse(unsigned int origNum, int numBits) {

  unsigned int revNum = 0;
  for (int i = 0; i < numBits; i++) {
    revNum <<= 1;
    revNum += origNum & 1;
    origNum >>=1;
  }
  return revNum;

}

unsigned int flip(unsigned int currentStatus, int pos) {
  unsigned int mask = (1 << pos);
  int color = currentStatus & mask;
  currentStatus ^= mask;
  
  int row = pos/4;
  int col = pos%4;

  //flip left
  if (col > 0) currentStatus ^= (mask >> 1);

  //flip right
  if (col < 3) currentStatus ^= (mask << 1);

  //flip up
  if (row > 0) currentStatus ^= (mask >> 4);

  //flip down
  if (row < 3) currentStatus ^= (mask << 4);

  return currentStatus;
}

/*
unsigned int flip(unsigned int currentStatus, int pos) {
  unsigned int mask = (1 << pos);
  int color = currentStatus & mask;
  currentStatus ^= mask;
  
  int row = pos/4;
  int col = pos%4;
  
  //filp left
  for (int i = 1; i <= col ; i++) {
    currentStatus ^= (mask >> i);

    if (((col - i) == 0) || ((currentStatus & (mask >> i)) > 0) == ((currentStatus & (mask >> (i+1))) > 0)) 
      break;
  }

  //flip right
  for (int i = 1; i < (4-col); i++) {
    currentStatus ^= (mask << i);

    if (((col + i) == 3) || ((currentStatus & (mask << i)) > 0) == ((currentStatus & (mask << (i+1))) > 0)) 
      break;
  }

  //flip up
  for (int i = 1; i <= row; i++) {
    currentStatus ^= (mask >> 4*i);

    if (((row - i) == 0) || ((currentStatus & (mask >> 4*i)) > 0) == ((currentStatus & (mask >> 4*(i+1))) > 0)) 
      break;
  }
  
  //flip down
  for (int i = 1; i < (4-row); i++) {
    currentStatus ^= (mask << 4*i);
    
    if (((row + i) == 3) || ((currentStatus & (mask << 4*i)) > 0) == ((currentStatus & (mask << 4*(i+1))) > 0)) 
      break;
  }

  return currentStatus;

}
*/

class Node {
public:
  unsigned int status;
  unsigned int level;

  Node(unsigned int s, unsigned int l) : status(s), level(l) {}

  
};

void enqueue(queue<Node>& gameQueue, unsigned int currentStatus, unsigned int currentLevel) {
  
  for (int i = 0; i < 16; i++) {
    unsigned int flipStatus = flip(currentStatus, i);
    if (flags.test(flipStatus)) continue;

    flags.set(flipStatus);
    gameQueue.push(Node(flipStatus, currentLevel+1));

  }
  
}

int main() {

  //queue<unsigned int> gameQueue;
  queue<Node> gameQueue;
  flags.reset();

  unsigned int initialStatus = 0;
  unsigned int targetBlack = 0xffff;
  unsigned int targetWhite = 0x0000;
  unsigned int mask = 0x0000ffff;

  //cout << sizeof(unsigned int) << endl;
  //cout << target << endl;
  //cout << hex << target << endl;

  char line[10];
  
  for (int i = 0; i < 4; i++) {
    cin.getline(line, 10);

    for (int j = 0; j < strlen(line); j++) {
      initialStatus <<= 1;
      if (line[j] == 'b') initialStatus += 1;
    }
    
  }
  
  initialStatus = reverse(initialStatus, 16);
  
  //cout << hex << "Initial status: " << initialStatus << endl;

  //cout << hex << flip(initialStatus, 0) << endl;

  /*
  if ((initialStatus == targetWhite) || (initialStatus == targetBlack)) {
    cout << 0 << endl;
    return 0;
  }
  */
  
  flags.set(initialStatus);
  gameQueue.push(Node(initialStatus, 0));

  while (!gameQueue.empty()) {
    
    unsigned int currentStatus = gameQueue.front().status;
    unsigned int currentLevel = gameQueue.front().level;

    //cout << currentStatus << " " << currentLevel << endl;

    if ((currentStatus == targetWhite) || (currentStatus == targetBlack)) {
      
      cout << currentLevel << endl;
      return 0;
    }

    enqueue(gameQueue, currentStatus, currentLevel);
    
    gameQueue.pop();

  }

  cout << "Impossible" << endl;
  return 0;
  
  
}

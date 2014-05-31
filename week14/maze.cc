#include <iostream>
#include <bitset>
#include <cstring>
#include <stack>

using namespace std;

#define MAXNODE 25

struct Node {
  int row;
  int col;
  Node* parentPtr;

  Node(int r = -1, int c = -1, Node* p = NULL) : row(r), col(c), parentPtr(p) {}

  /*
  ostream& operator<<(ostream& os, int) {
  os << "(" << node.row << ", " << node.col << ")";
  return os;
  
  }
  */

};


ostream& operator<<(ostream& os, const Node& node) {
  os << "(" << node.row << ", " << node.col << ")";
  return os;
}


int main() {

  int maze[5][5];
  Node mazeQueue[25];
  int head = 0;
  int tail = 0;
  bitset<25> flags;

  /*
  char buf[10];
  for (int i = 0; i < 5; i++) {
    cin.getline(buf, 10);
    for (int j = 0; j < strlen(buf); j++) {
      if (buf[j] == '0')
	maze[i][j] = 0;
      else
	maze[i][j] = 1;
    }
  }
  */

  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++)
      cin >> maze[i][j];


  flags.set(0);
  mazeQueue[tail++] = Node(0, 0, NULL);

  while (head != tail) {
    int row = mazeQueue[head].row;
    int col = mazeQueue[head].col;
    Node* parentPtr = &(mazeQueue[head]);
    //cout << mazeQueue[head] << endl;
    
    if (row == 4 && col == 4) {
      //cout << "break!" << endl;
      break;
    }
    //go left
    if (col > 0 && maze[row][col-1] == 0 && !flags.test(row*5 + col-1)) {
      flags.set(row*5 + col-1);
      mazeQueue[tail++] = Node(row, col-1, parentPtr);
    }

    //go right
    if (col < 4 && maze[row][col+1] == 0 && !flags.test(row*5 + col+1)) {
      flags.set(row*5 + col+1);
      mazeQueue[tail++] = Node(row, col+1, parentPtr);
    }

    //go up
    if (row > 0 && maze[row-1][col] == 0 && !flags.test((row-1)*5 + col)) {
      flags.set((row-1)*5 + col);
      mazeQueue[tail++] = Node(row-1, col, parentPtr);
    }
    
    //go down
    if (row < 4 && maze[row+1][col] == 0 && !flags.test((row+1)*5 + col)) {
      flags.set((row+1)*5 + col);
      mazeQueue[tail++] = Node(row+1, col, parentPtr);
    }

    head++;

    //cout << "head: " << head << ", tail: " << tail << endl;
  }

  stack<Node*> outputStack;
  Node* currentNodePtr = &mazeQueue[head];
  
  while(currentNodePtr != &(mazeQueue[0])) {
    //    cout << *currentNodePtr << endl;
    outputStack.push(currentNodePtr);
    currentNodePtr = currentNodePtr->parentPtr;
  }

  outputStack.push(&mazeQueue[0]);

  while(!outputStack.empty()) {
    cout << *(outputStack.top()) << endl;;
    outputStack.pop();    
  }
  

}

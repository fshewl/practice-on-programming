#include <iostream>
#include <string>
using namespace std;

class Student {
private:
  string name;
  int id;

public:
  Student() {}
  Student(string &s, int i) : name(s), id(i) {}
  Student(const char *s, int i) : name(s), id(i) {}

  void Read() {
    cin >> name >> id;
  }

  void Print() {
    cout << id << " " << name << endl;
  }
  
};

int main()
{
  int t;
  cin >> t;
  Student s("Tom",12);
  while( t-- ){
    int n;
    cin >> n;
    Student st;
    for( int i = 0;i < n; ++i) {
      st.Read();
      st.Print();
    }
    cout << "****" << endl;
  }
  return 0;
}

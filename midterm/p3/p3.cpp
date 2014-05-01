#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;


class Student {

private:
  string name;
  int score;

public:
  Student() {}
  Student(string n, int s) : name(n), score(s) {}

  string getName() {
    return name;
  }

  int getScore() {
    return score;
  }
  
  void setName(string n) {
    name = n;
  }

  void setScore(int s) {
    score = s;
  }

  bool operator<(const Student &st) const {
    if (score < st.score)
      return true;
    
    return false;
  }

};

istream & operator>>(istream &in, Student &st) {
  string n;
  int s;
  cin >> n >> s;

  st.setName(n);
  st.setScore(s);
  
  return in;

}

ostream & operator<<(ostream& out, Student &st) {
  out << st.getName();
  return out;
}

int main()
{
  int t;
  vector<Student> v;
  cin >> t;

  while( t--) {
    int n;
    cin >> n;
    Student st;
    v.clear();
    for( int i = 0;i < n; ++i ) {
      cin >> st;
      v.push_back(st);
    }
    sort(v.begin(),v.end());
    for( int i = 0;i < v.size(); ++ i)
      cout << v[i] << endl;
    cout << "****" << endl;
  }
  return 0;
}

#include <iostream>
#include <map>
using namespace std;

struct Student
{
  int id;
  string name;
  int score;
  Student(int id_,const string & nm,int sc):
    id(id_),name(nm),score(sc) { }
  Student() { }


};


struct Info
{
  String name;
  int score;
  Info(const string & s,int sc):name(s),score(sc) { }
};


pair<int, Info> MyMakePair(Student &st) {
  struct Info info(st.name, st.score);
  return make_pair(st.id, info);
}

Student MyFind(std::map<int, Info> &mp, int n) {
  struct Info info = mp.find(n)->second;
  struct Student st(n, info.name, info.score);
  return st;
}

int main()
{
  std::map<int,Info>  mp;
  int t;
  cin >> t;
  while( t -- ) {
    mp.clear();
    int n;
    cin >> n;
    Student st;
    for( int i = 0;i < n; ++i) {
      cin >> st.id >> st.name >> st.score;
      mp.insert(MyMakePair(st));
    }
    cin >> n;
    st = MyFind(mp,n) ;
    cout << st.name << " " << st.score  << endl;
  }
  return 0;
}

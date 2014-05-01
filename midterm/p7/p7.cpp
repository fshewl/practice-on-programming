#include <iostream>
#include <set>
using namespace std;

template<typename _T, class Compare = less<_T> >
class MySet : public set<_T, Compare> {

public:
  MySet() : set<_T, Compare>() {}
  MySet(_T *__first, _T *__last) : set<_T, Compare>(__first, __last) {}


  pair<typename set<_T, Compare>::iterator, typename set<_T, Compare>::iterator> FindInterval(_T __min, _T __max) {
    typename set<_T, Compare>::iterator upb = set<_T, Compare>::lower_bound(__max);
    typename set<_T, Compare>::iterator lowb = set<_T, Compare>::upper_bound(__min);
    if (lowb != set<_T, Compare>::end() && upb != set<_T, Compare>::end())
      return make_pair(lowb, upb);

    else
      return make_pair(set<_T, Compare>::begin(), set<_T, Compare>::begin());

  }

};


template<typename _InputIterator>
void MyPrint(_InputIterator __first, _InputIterator __last) {
  for(; __first != __last; ++__first) {
    cout << *__first << " ";
  }
}


int main()
{
  int t;
  cin >> t;
  MySet<int> stInt;
  int a[100];
  while(t--) {
    int n;
    cin >> n;
    for(int i = 0;i < n; ++i )
      cin >> a[i];
    MySet<int> stInt(a,a+n);
    MyPrint(stInt.begin(),stInt.end()); //èååéåå
    cout << endl;
    int s,e;
    cin >> s >> e; // åéèèåää s å e äéçåç
    pair<MySet<int>::iterator, MySet<int>::iterator> p;
    p  = stInt.FindInterval(s,e);
    if( p.first != p.second) {
      MyPrint(p.first,p.second);
      cout << endl;
    }
    else
      cout << "Interval Not Found" << endl;
    cin >> n;
    MySet<double,greater<double> > stDouble;
    for( int i = 0;i < n; ++i){
      double d;
      cin >> d;
      stDouble.insert(d);
    }
    MyPrint(stDouble.begin(),stDouble.end());
    cout << endl;
    double w;
    cin >> w;
    cout << * stDouble.upper_bound(w) << endl;
  }
}

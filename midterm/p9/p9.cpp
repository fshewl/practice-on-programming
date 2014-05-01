#include <iostream>
#include <string>
using namespace std;

class Student {
private:
  int id;
  static int count;
public:
  Student() { count++; }
  Student(int i) : id(i) { count++;}
  Student(Student &st) { id = st.id; count++; }
  static void InitCount() { count = 0; }
  ~Student() { count--; }

  friend void Print(Student s);
  friend void PrintCount();

};


int Student::count;
void PrintCount() {
  cout << "Total " << Student::count << " students" << endl;
}
void Print(Student s)
{
  cout << "the id is " << s.id << endl;
}

int main()
{
  Student::InitCount();
  Student s;
  PrintCount();
  Student s1(10);
  Student s2(s1);
  PrintCount();
  Print(s2);
  PrintCount();
  return 0;
}

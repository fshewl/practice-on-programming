#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class CStudent
{
  
private:
  string name;
  int age;
  string id;
  int average;

public:
  CStudent(string n, int a, string i, int avr):name(n),age(a),id(i),average(avr){}
  void print() {
      cout << name << "," << age << "," << id << "," << average << endl;
  }
  
};

int main()
{
  string input;

  cin >> input;
  stringstream ss(input);
  string token;
  string name;
  int age;
  string id;
  int first, second, third, forth;

  getline(ss, name, ',');
  
  getline(ss, token, ',');
  stringstream(token) >> age;
  getline(ss, id, ',');
  
  getline(ss, token, ',');
  stringstream(token) >> first;
  getline(ss, token, ',');
  stringstream(token) >> second;
  getline(ss, token, ',');
  stringstream(token) >> third;
  getline(ss, token, ',');
  stringstream(token) >> forth;

  
  /*
  ss >> name;
  ss.ignore(1);
  ss >> age;
  ss.ignore(1);
  ss >> id;
  ss.ignore(1);
  ss >> first;
  ss.ignore(1);
  ss >> second;
  ss.ignore(1);
  ss >> third;
  ss.ignore(1);
  ss >> forth;
  */

  

  int average = (first+second+third+forth)/4;

  CStudent student(name, age, id, average);
  student.print();
}
  

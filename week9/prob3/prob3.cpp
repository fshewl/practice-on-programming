#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <sstream>

using namespace std;

#define MAXLENGTH 500;
string *strArray;
int size;
char tempString[5];

string copy(int id, int pos, int len) {
  string result = strArray[id].substr(pos, len);
  return result;
}

bool isValidNum(const string &s) {
  if (s.length() > 5) return false;
  
  for(int i = 0; i < s.length(); i++) {
    //cout << s[i] << endl;
    if ((s[i] < '0') || (s[i] > '9')) 
      return false;
  }

  return true;
}

string add(const string &s1, const string &s2) {

  if (isValidNum(s1) && isValidNum(s2)) {
    int num1 = atoi(s1.c_str());
    int num2 = atoi(s2.c_str());
    int result = num1+num2;
    stringstream ss;
    ss << result;
    return ss.str();
  }

  else {
    string s = s1+s2;
    return s;
  }
}

int find(const string &s, int id) {

  int found = strArray[id].find(s);

  if (found != string::npos)
    return found;
  else
    return strArray[id].length();
  
}


int rfind(const string &s, int id) {

  int found = strArray[id].rfind(s);

  if (found != string::npos)
    return found;
  else
    return strArray[id].length();
}

string& insert(const string &s, int id, int pos) {
  return strArray[id].insert(pos, s);
}

void reset(const string &s, int id) {
  
  strArray[id] = s;
  
}

void print(int id) {

  cout << strArray[id] << endl;
  
}

void printall() {

  for (int i = 1; i <= size; i++)
    cout << strArray[i] << endl;
  
}



string parseCmd(string &cmdstring) {

  if (cmdstring == "printall") {
    printall();
    return string();
  }

  int pos = cmdstring.find(" ");

  if (pos == string::npos)
    return cmdstring;

  string cmd = cmdstring.substr(0, pos);
  string cmdleft = cmdstring.substr(pos+1);


  if (cmd == "copy") {
    string operandstring = parseCmd(cmdleft);
    int start = 0;
    int found = operandstring.find(' ', start);
    string id_s = operandstring.substr(start, found-start);
    
    start = found+1;
    found = operandstring.find(' ', start);
    string pos_s = operandstring.substr(start, found-start);
    
    start = found+1;
    found = operandstring.find(' ', start);
    string len_s;
    if (found == string::npos) {
      len_s = operandstring.substr(start);
      string result = copy(atoi(id_s.c_str()), atoi(pos_s.c_str()), atoi(len_s.c_str()));
      return result;
    }
    else {
      len_s = operandstring.substr(start, found-start);
      string left = operandstring.substr(found+1);
      string result = copy(atoi(id_s.c_str()), atoi(pos_s.c_str()), atoi(len_s.c_str()));
      return result+' '+left;
      //cout << "copy: " << operandstring << endl;
    }
  }

  if (cmd == "add") {
    string operandstring = parseCmd(cmdleft);
    int start = 0;
    int found = operandstring.find(' ', start);
    string s1 = operandstring.substr(start, found-start);
    
    start = found+1;
    found = operandstring.find(' ', start);
    string s2 = operandstring.substr(start, found-start);

    if (found == string::npos) {
      s2 = operandstring.substr(start);
      string result = add(s1, s2);
      return result;
    }
    else {
      s2 = operandstring.substr(start, found-start);
      string left = operandstring.substr(found+1);
      string result = add(s1, s2);
      return result+' '+left;
    }
    //cout << "add: " << operandstring << endl;
  }

  if (cmd == "find") {
    string operandstring = parseCmd(cmdleft);
    
    int start = 0;
    int found = operandstring.find(' ', start);
    string s = operandstring.substr(start, found-start);
    
    start = found+1;
    found = operandstring.find(' ', start);
    string id_s;
    if (found == string::npos) {
      id_s = operandstring.substr(start);
      int ret = find(s, atoi(id_s.c_str()));
      stringstream ss;
      ss << ret;
      return ss.str();
    }
    else {
      id_s = operandstring.substr(start, found-start);
      string left = operandstring.substr(found+1);
      int ret = find(s, atoi(id_s.c_str()));
      stringstream ss;
      ss << ret;
      return ss.str()+' '+left;;
    }
        
    //cout << "find: " << operandstring << endl;
  }

  if (cmd == "rfind") {
    string operandstring = parseCmd(cmdleft);
    int start = 0;
    int found = operandstring.find(' ', start);
    string s = operandstring.substr(start, found-start);
    
    start = found+1;
    found = operandstring.find(' ', start);
    string id_s;
    
    if (found == string::npos) {
      id_s = operandstring.substr(start);
      int ret = rfind(s, atoi(id_s.c_str()));
      stringstream ss;
      ss << ret;
      return ss.str();
    }
    else {
      id_s = operandstring.substr(start, found-start);
      string left = operandstring.substr(found+1);
      int ret = rfind(s, atoi(id_s.c_str()));
      stringstream ss;
      ss << ret;
      return ss.str()+' '+left;;

    }

    //cout << "rfind: " << operandstring << endl;
  }
  
  if (cmd == "insert") {
    string operandstring = parseCmd(cmdleft);
    int start = 0;
    int found = operandstring.find(' ', start);
    string s = operandstring.substr(start, found-start);
    
    start = found+1;
    found = operandstring.find(' ', start);
    string id_s = operandstring.substr(start, found-start);
    
    start = found+1;
    string pos_s = operandstring.substr(start);

    insert(s, atoi(id_s.c_str()), atoi(pos_s.c_str()));
    //cout << "insert: " << operandstring << endl;
  }
    
  if (cmd == "reset") {
    string operandstring = parseCmd(cmdleft);
    int start = 0;
    int found = operandstring.find(' ', start);
    string s = operandstring.substr(start, found-start);
    
    start = found+1;
    string id_s = operandstring.substr(start);

    reset(s, atoi(id_s.c_str()));
    //cout << "reset: " << operandstring << endl;
  }

  if (cmd == "print") {
    string operandstring = parseCmd(cmdleft);
    print(atoi(operandstring.c_str()));
    return string();
    //cout << "print: " << operandstring << endl;

  }


  return cmd+' '+parseCmd(cmdleft);

}


int main() {

  cin >> size;
  strArray = new string[size+1];
  
  for (int i = 1; i <= size; i++) {
    string temp;
    cin >> temp;
    strArray[i] = temp;
    //print(i);
    //cout << find("one", i) << endl;
    //cout << rfind("one", i) << endl;
    //cout << insert("insert", i, 2) << endl;
    //printall();
    //cout << copy(i, 2, 2) << endl;
    //if (i >= 1) {
    //cout << add(strArray[i-1], strArray[i]) << endl;
    //}
  }

  cin.ignore();
  string cmdstring;
  while (true) {
    getline(cin, cmdstring);
    //cout << cmdstring << endl;
    if (cmdstring == "over")
      break;
    parseCmd(cmdstring);
  }
  
  return 0;

}

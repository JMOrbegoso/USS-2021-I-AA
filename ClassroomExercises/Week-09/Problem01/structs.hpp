#include <iostream>

using namespace std;

struct personStruct {
  string firstName;
  string lastName;
  unsigned short age;
};

struct personNode {
  personStruct person;
  personNode *right;
  personNode *left;
};

typedef personNode *peopleThree;

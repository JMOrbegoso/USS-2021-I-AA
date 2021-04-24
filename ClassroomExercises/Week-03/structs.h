#include <iostream>

using namespace std;

struct authorStruct {
  string firstName;
  string lastName;
  unsigned short age;
};

struct authorNode {
  authorStruct author;
  authorNode *next;
  authorNode *previous;
};

struct authorsList {
  authorNode *firstNode;
  int length;
};

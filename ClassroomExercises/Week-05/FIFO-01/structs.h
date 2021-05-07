#include <iostream>

using namespace std;

struct personStruct {
  string firstName;
  string lastName;
  string address;
  char genre;
  unsigned short age;
};

struct personNode {
  personStruct person;
  personNode *next;
};

struct personsQueue {
  personNode *head;
  personNode *tail;
  int length;
};

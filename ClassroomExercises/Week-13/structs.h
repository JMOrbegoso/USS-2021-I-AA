#include <iostream>

using namespace std;

struct studentStruct {
  string firstName;
  string lastName;
  string dni;
};

struct studentNode {
  studentStruct student;
  studentNode *prev;
  studentNode *next;
};

struct studentsList {
  studentNode *head;
  int length;
};

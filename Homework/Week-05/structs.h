#include <iostream>

using namespace std;

struct recordStruct {
  string code;
  string type;
};

struct recordNode {
  recordStruct record;
  recordNode *next;
};

struct recordsStack {
  recordNode *top;
  int length;
};

struct clientStruct {
  string firstName;
  string lastName;
  char genre;
  unsigned short age;
  recordsStack records;
};

struct clientNode {
  clientStruct client;
  clientNode *next;
};

struct clientsQueue {
  clientNode *head;
  clientNode *tail;
  int length;
};

struct bankStruct {
  string name;
  string address;
  clientsQueue clients;
};
